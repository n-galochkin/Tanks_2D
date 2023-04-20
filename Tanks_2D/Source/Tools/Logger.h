#pragma once
#include <format>
#include <string>

using namespace std;

enum LogLevel
{
    Debug,
    Info,
    Warning,
    Error
};

class Logger
{
public:
    static void log(LogLevel level, const string& message)
    {
        logMessage(level, message);
    }

private:
    static void logMessage(LogLevel level, const string& message);

    static void warning(const string& message);

    static void console(const string& message);
};
