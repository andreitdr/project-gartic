module logging;

import <format>;


std::string_view LogLevelToString(Logger::Level level)
{
	switch (level)
	{
	using enum Logger::Level;
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

Logger::Logger(std::ostream& os, Logger::Level minimumLevel) :
	m_os{ os },
	m_minimumLevel{ minimumLevel }
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

	m_os << std::format("[{}] {}\n", LogLevelToString(logLevel), message);
}