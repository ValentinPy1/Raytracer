/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Logger.cpp
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include "Render.hpp"

namespace render {
    Logger::Logger()
    {
        _logFile.open("log.txt");
    }

    Logger::~Logger()
    {
        _logFile.close();
    }

    void Logger::log(const std::string &message)
    {
        _logFile.write(("[INFO] " + message + "\n").c_str(), message.size() + 8);
    }

    void Logger::logError(const std::string &message)
    {
        _logFile.write(("[ERROR] " + message + "\n").c_str(), message.size() + 9);

    }

    void Logger::logWarning(const std::string &message)
    {
        _logFile.write(("[WARNING] " + message + "\n").c_str(), message.size() + 11);
    }
}
