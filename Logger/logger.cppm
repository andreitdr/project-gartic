module;
#pragma once
#include <Windows.h>

#include <format>
#include <chrono>
#include <fstream>

export module Logger;


#define COLOR_WHITE 7
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_RED 4


export class __declspec(dllexport) Logger 
{
public:
	enum class Level : char
	{
		Debug,
		Info,
		Warning,
		Error
	};

	enum class Color : int
	{
		Debug=COLOR_WHITE,
		Info=COLOR_GREEN,
		Warning=COLOR_YELLOW,
		Error=COLOR_RED
	};
	Logger(std::ostream& os, Level minimumLevel, const std::string& fileName);

	void SetMinimumLogLevel(Level level);

	void LogMessage(std::string_view message, Level logLevel);

	void LogMessage(std::string_view message);

	void LogMessage(std::string_view message, const std::string& where);

	void LogError(std::string_view message);

	void LogError(const std::exception& ex);
	
	void LogError(std::string_view message, const std::string& where);
	
private:
	std::ostream& m_os;
	Level m_minimumLevel;
	std::string m_fileName;

	void LogError(const std::exception& ex, const std::string& where);
	static Color GetTextColorByLogLevel(Level level);
};

std::string_view LogLevelToString(Logger::Level level)
{
	switch (level)
	{
		using enum Logger::Level;
	case Debug:
		return "Debug";
	case Info:
		return "Info";
	case Warning:
		return "Warning";
	case Error:
		return "Error";
	default:
		return "";
	}
}

Logger::Logger(std::ostream& os, Logger::Level minimumLevel, const std::string& fileName) :
	m_os{ os },
	m_minimumLevel{ minimumLevel },
	m_fileName{fileName}
{
	// Empty
}

void Logger::SetMinimumLogLevel(Level level)
{
	m_minimumLevel = level;
}

void Logger::LogMessage(std::string_view message, Logger::Level logLevel)
{
	if (static_cast<int>(logLevel) < static_cast<int>(m_minimumLevel))
		return;
	const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::fstream f(m_fileName,std::ios::app);
	const auto now = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(GetTextColorByLogLevel(logLevel)));
	m_os << std::chrono::round<std::chrono::seconds>(now) << " "<< std::format("[{}] {}\n", LogLevelToString(logLevel), message);
	f << std::chrono::round<std::chrono::seconds>(now) << " " << std::format("[{}] {}\n",LogLevelToString(logLevel),message);
	f.close();
}
void Logger::LogMessage(std::string_view message)
{
	LogMessage(message,Logger::Level::Info);
}

void Logger::LogMessage(std::string_view message, const std::string& where)
{
	const std::string s_message="["+where+"] " + std::string(message);
	LogMessage(s_message, Logger::Level::Info);
}

void Logger::LogError(std::string_view message)
{
	LogMessage(message, Logger::Level::Error);
}

void Logger::LogError(const std::exception& ex)
{
	LogMessage(ex.what(),Logger::Level::Error);
}

void Logger::LogError(std::string_view message,const std::string& where)
{
	const std::string s_message=std::string(message)+" ["+where+"]";
	LogMessage(s_message, Logger::Level::Error);
}

void Logger::LogError(const std::exception& ex,const std::string& where)
{
	const std::string s_message=std::string(ex.what())+" ["+where+"]";
	LogMessage(ex.what(),Logger::Level::Error);
}


Logger::Color Logger::GetTextColorByLogLevel(Level level)
{
	
	switch(level)
	{
	case Logger::Level::Debug:
		return Color::Debug;
	case Logger::Level::Info:
		return Color::Info;
	case Logger::Level::Warning:
		return Color::Warning;
	case Logger::Level::Error:
		return Color::Error;
	default:
		throw std::exception("invalid log level");
	}
}
