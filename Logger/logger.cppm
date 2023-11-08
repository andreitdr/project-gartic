export module logging;

import <iostream>;
import <string_view>;

export class __declspec(dllexport) Logger
{
public:
	enum class Level : char
	{
		Info,
		Warning,
		Error
	};

public:
	Logger(std::ostream& os, Level minimumLevel = Level::Info);

	void SetMinimumLogLevel(Level level);

	void Log(std::string_view message, Level logLevel = Level::Info);

private:
	std::ostream& m_os;
	Level m_minimumLevel;
};