#include "Logger.h"

#include <iostream>

void ::Logger::logMessage(LogLevel level, const string& message)
{
    switch (level)
    {
    case Debug:   console(message); break;
    case Info:    console(message); break;
    case Warning: warning(message); break;
    case Error:   console(message); break;
    default: ;
    }
}

void Logger::warning(const string& message)
{
    console("\033[33m" + message + "\033[0m");
}

void Logger::console(const string& message)
{
    cout << message << endl;
}
