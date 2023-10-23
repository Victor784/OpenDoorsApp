#include "WSConnection.hpp"
#include "../Logger/Logger.hpp"
#include "../../utils/utils.hpp"
#include <string>

using namespace logging;

namespace connection
{

WSConnection::WSConnection()
{
    Logger& logger = Logger::getInstance();
    WSADATA wsadata;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested,  &wsadata);
    if(wsaerr != 0)
    {
       logger.log("WSConnection() - Winsock dll not found..");
    }
    else {
        logger.log("WSConnection() - Winsock dll found ");
        logger.log("WSConnection() - Status: "); 
        logger.log(wsadata.szSystemStatus);  
    }
}

void WSConnection::connect_()
{
    
    Logger& logger = Logger::getInstance();
    WSADATA wsadata;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested,  &wsadata);
    if(wsaerr != 0)
    {
       logger.log("connect_() - Winsock dll not found..");
    }
    else {
        logger.log("connect_() - Winsock dll found ");
        logger.log("connect_() - Status: "); 
        logger.log(wsadata.szSystemStatus); 

    }
    clientScoket = INVALID_SOCKET;
    clientScoket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(clientScoket == INVALID_SOCKET)
    {
        logger.log("connect_() - Error at socket(): " + getErrorAsString(WSAGetLastError()));
        WSACleanup();
    }
    else {
        logger.log("connect_() - Socket() is OK!"); 
    }
     //socket setup continuation
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    InetPton(AF_INET, ("127.0.0.1"), &clientService.sin_addr.s_addr);
    clientService.sin_port = 9999; // this is actually converted into 3879 because of big endian - little endian conversion
    // socket binding / connection
    if(connect(clientScoket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        logger.log("connect_() - Client connect() - Failed to connect err: " + getErrorAsString(WSAGetLastError()));
        WSACleanup(); // Because of WSACLeanup here all other operations will fail , As WSAStartup effects will be negated by this
    }
    else {
        logger.log( "connect_() - Client connect() is OK!");
        logger.log("connect_() - Can start sending and recieveing data..");
    }
}

void WSConnection::write_(std::string message)
{
    Logger& logger = Logger::getInstance();
    if(clientScoket== SOCKET_ERROR)
    {
        logger.log("write_() - Client socket error, cannot send message..");
    }
    else 
    {
        logger.log(message);
        #define DEFAULT_BUFLEN 512
        int recvbuflen = DEFAULT_BUFLEN;

        const char *sendbuf = message.c_str();
        char recvbuf[DEFAULT_BUFLEN];

        int iResult;

        // Send an initial buffer
        iResult = send(clientScoket, sendbuf, (int) strlen(sendbuf), 0);
        if (iResult == SOCKET_ERROR) {
            logger.log("write_() - send failed:" +  getErrorAsString(WSAGetLastError()));
            closesocket(clientScoket);
            WSACleanup();
        }

        logger.log("write_() - Bytes Sent:" + std::to_string((long)iResult));

        // shutdown the connection for sending since no more data will be sent
        // the client can still use the ConnectSocket for receiving data
        iResult = shutdown(clientScoket, SD_SEND);
        if (iResult == SOCKET_ERROR) 
        {
            logger.log("write_() - shutdown failed:" + getErrorAsString(WSAGetLastError()));
            closesocket(clientScoket);
            WSACleanup();
        }
    }
    
}

std::string WSConnection::read_()
{
    Logger& logger = Logger::getInstance();
    if(clientScoket== SOCKET_ERROR)
    {
        logger.log("read_() - Client socket error, cannot recieve message.");
        return "error";
    }
    else {
    
    
     #define DEFAULT_BUFLEN 512

    int recvbuflen = DEFAULT_BUFLEN;
    char recvbuf[DEFAULT_BUFLEN];
    
    int iResult = recv(clientScoket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
        {
            logger.log("read_() - Bytes received:" + std::to_string(iResult));
            logger.log("read_() - Message from server is: ");
            logger.log(recvbuf);
            return recvbuf;
            // message should be passed to client here
        }
        else if (iResult == 0)
            logger.log("read_() - Connection closed");
        else
            logger.log("read_() - recv failed:" + getErrorAsString(WSAGetLastError()));
    return "error";
    }
}

void WSConnection::disconnect_()
{
    Logger& logger = Logger::getInstance();
    closesocket(clientScoket);
    logger.log("disconnect_() - Connection closed");
    WSACleanup();
}

}//connection