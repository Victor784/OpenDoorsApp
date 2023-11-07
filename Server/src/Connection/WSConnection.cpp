#include "WSConnection.hpp"
#include "../Logger/Logger.hpp"
#include "../../utils/utils.hpp"
#include "WSConnection.hpp"

#include <string>


using namespace logging;


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

void WSConnection::createSocket()
{
    Logger& logger = Logger::getInstance();
    WSADATA wsadata;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested,  &wsadata);
    if(wsaerr != 0)
    {
       logger.log("createSocket() - Winsock dll not found..");
    }
    else {
        logger.log("createSocket() - Winsock dll found ");
        logger.log("createSocket() - Status: "); 
        logger.log(wsadata.szSystemStatus);  
    }
    //Socket creation and initial set up (TCP type , etc..)
    serverSocket = INVALID_SOCKET;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverSocket == INVALID_SOCKET)
    {
        logger.log("createSocket() - Error at socket(): " +  getErrorAsString(WSAGetLastError()));
        WSACleanup();
    }
    else {
        logger.log("createSocket() - Socket() is OK! "); 
    }
}
void WSConnection::bindSocket()
{
    Logger& logger = Logger::getInstance();
    // We need this socaddr_in obj to finish setting up the socket and bind it to an ip/port
    if(serverSocket == INVALID_SOCKET)
    {
        logger.log("bindSocket() - Error at socket(): " +  getErrorAsString(WSAGetLastError()));
        WSACleanup();
    }
    else 
    {

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_port = 9999;  // this is actually converted into 3879 because of big endian - little endian conversion
                              // use of nhlot() or htol() can solve this flipping bytes issue
    InetPton(AF_INET, ("127.0.0.1"), &(service.sin_addr.s_addr));

    // actual binding of the socket
    if(bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        logger.log("bindSocket() - bind() failed: " +  getErrorAsString(WSAGetLastError()));
        closesocket(serverSocket);
        WSACleanup();
    }
    else {
        std::cout << "bindSocket() - bind() is OK!\n";   
    }
}
    
}
    //listen function to "open" the socket for listening on the port 
void WSConnection::listenOnSocket()
{
    Logger& logger = Logger::getInstance();
    // We need this socaddr_in obj to finish setting up the socket and bind it to an ip/port
    if(serverSocket == INVALID_SOCKET)
    {
        logger.log("listenOnSocket() - Error at socket(): " +  getErrorAsString(WSAGetLastError()));
        WSACleanup();
    }
    else 
    {
    if (listen(serverSocket , 1) == SOCKET_ERROR)
    {
        logger.log("listenOnSocket() - Error listening on socket" +  getErrorAsString(WSAGetLastError()));
    }
    else 
    {
        logger.log("listenOnSocket() - listen() is OK, I am waiting for connections..");  
    }
    }
}

std::string WSConnection::acceptNewClientSocketAndRecieve()
{
    Logger& logger = Logger::getInstance();
    // We need this socaddr_in obj to finish setting up the socket and bind it to an ip/port
    if(serverSocket == INVALID_SOCKET)
    {
        logger.log("acceptNewClientSocketAndRecieve() - Error at socket(): " +  getErrorAsString(WSAGetLastError()));
        WSACleanup();
        return "";
    }
    else 
    {
    SOCKET acceptSocket;
    acceptSocket = accept(serverSocket, NULL, NULL);
    if(acceptSocket == INVALID_SOCKET)
    {
        logger.log("acceptNewClientSocketAndRecieve() - accept failed : " +  getErrorAsString(WSAGetLastError()));
        WSACleanup();
        return "";
    }
    else  
    {
        #define DEFAULT_BUFLEN 100

    char recvbuf[DEFAULT_BUFLEN];
    int iResult, iSendResult;
    int recvbuflen = DEFAULT_BUFLEN;

    // Receive until the peer shuts down the connection
    do {

        iResult = recv(acceptSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            logger.log("acceptNewClientSocketAndRecieve() - Bytes received:"  +  getErrorAsString(WSAGetLastError()));
            return recvbuf;
            // Echo the buffer back to the sender
            // iSendResult = send(acceptSocket,"response from server", iResult, 0);
            // if (iSendResult == SOCKET_ERROR) {
            //     printf("send failed: %d\n", WSAGetLastError());
            //     closesocket(acceptSocket);
            //     WSACleanup();
            //     return 1;
            // }
            // printf("Bytes sent: %d\n", iSendResult);
        } else if (iResult == 0)
        {
            logger.log("acceptNewClientSocketAndRecieve() - Connection closing...");
            return "";
        }
        else {
            logger.log("acceptNewClientSocketAndRecieve() - recv failed"  +  getErrorAsString(WSAGetLastError()));
            closesocket(acceptSocket);
            WSACleanup();
            return "";
        }
        } while (iResult > 0);
        closesocket(serverSocket);
        WSACleanup();
    }
}
}

void WSConnection::sendResponse(std::string reply)
{
    //TODO: implement this method, and implement a way to receive the reply in Client
}

