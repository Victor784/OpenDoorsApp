#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Logger {
public:
    // Get the single instance of the logger
    static Logger& getInstance() {
        static Logger instance; // Guaranteed to be destroyed and instantiated on first use.
        return instance;
    }

    // Log a message to the file
    void log(const std::string& message) {
        logFile_ << message << std::endl;
    }

private:
    Logger() {
        logFile_.open("logfile.txt", std::ios::app); // Open the file for appending
    }

    ~Logger() {
        logFile_.close(); // Close the file when the logger is destroyed
    }

    Logger(const Logger&) = delete; // Disable copy constructor
    Logger& operator=(const Logger&) = delete; // Disable assignment operator

    std::ofstream logFile_;
};
