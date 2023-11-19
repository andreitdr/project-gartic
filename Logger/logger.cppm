export module logging;

import <iostream>;
import <string_view>;
import <format>;
import <chrono>;
import <fstream>;
#include <Windows.h>


#define COLOR_WHITE 7
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_RED 4


export  class __declspec(dllexport)  Logger
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
public:
	Logger(std::ostream& os, Level minimumLevel, std::string fileName);

	void SetMinimumLogLevel(Level level);

	void Log(std::string_view message, Level logLevel);


private:
	std::ostream& m_os;
	Level m_minimumLevel;
	std::string m_fileName;
	
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

Logger::Logger(std::ostream& os, Logger::Level minimumLevel, std::string fileName) :
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

void Logger::Log(std::string_view message, Logger::Level logLevel)
{
	if (static_cast<int>(logLevel) < static_cast<int>(m_minimumLevel))
		return;
	const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::fstream f(m_fileName,std::ios::app);
	const auto now = std::chrono::system_clock::now();
	SetConsoleTextAttribute(hConsole, static_cast<WORD>(GetTextColorByLogLevel(logLevel)));
	m_os << now << std::format("[{}] {}\n", LogLevelToString(logLevel), message);
	f << now << std::format("[{}] {}\n",LogLevelToString(logLevel),message);
	f.close();
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
