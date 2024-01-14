#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

export module Config;

std::vector<std::string> split(const std::string& message, char separator)
{
    std::vector<std::string> strings;
    std::istringstream strStream(message);
    std::string str;

    while (std::getline(strStream, str, separator))
        strings.push_back(str);

    return strings;

}

export class ConfigFile
{
public:
    ConfigFile(const std::string& fileName);
    bool WriteValue(const std::string& key, const std::string& value) const;

    std::string ReadValue(const std::string& key) const;

private:
    const std::string m_fileName;
    static constexpr char k_commentLineStart = '#';
    static constexpr int bufferSize = 512;
};

ConfigFile::ConfigFile(const std::string& fileName): m_fileName{fileName}
{

}

std::string ConfigFile::ReadValue(const std::string& key) const
{
    if (key.empty())
        return "";

    std::ifstream fileStream(m_fileName);
    std::string result;
    while(!fileStream.eof())
    {
        std::string line;
        std::getline(fileStream, line);

        if (line.empty()) continue;
        if (line.starts_with(k_commentLineStart)) continue;
        if (!line.starts_with(key)) continue;

        result = line;
        break;
    }


    fileStream.close();


    if (result.empty())
        return "";


    std::string value = split(result, '=')[1];
    std::erase(value, ' ');

    return value;

}

bool ConfigFile::WriteValue(const std::string& key, const std::string& value) const
{
    if (key.empty() || value.empty())
        return false;

    std::ifstream fileStream(m_fileName);
    std::vector<std::string> fileLines;
    std::string line;
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        if (line.starts_with(key))
            fileLines.emplace_back(std::format("{} = {}", key, value));
        else fileLines.emplace_back(line);
    }

    fileStream.close();

    std::ofstream outFileStream(m_fileName);

    for(const std::string& fileLine : fileLines)
    {
        outFileStream << fileLine;
    }

    outFileStream.close();

    return true;
}




//auto ConfigFile::ReadConfig(const std::string& key) const
//{
//    std::ifstream f(m_fileName);
//    while (!f.eof())
//    {
//        auto elem = new char[500];
//        f.getline(elem, 500);
//        auto line = std::string(elem);
//        if (line.empty()) continue;
//        if (line.starts_with(k_commentLineStart)) continue;
//        if (!line.starts_with(key)) continue;
//        std::string val = line.substr(line.find_last_of('=') + 1, line.size());
//        while (val.starts_with(' ')) val = val.substr(1, val.size());
//        while (val.ends_with(' ')) val = val.substr(0, val.size() - 1);
//        f.close();
//        return val;
//    }
//    f.close();
//    throw std::exception("Key not found!");
//}


// void ConfigFile::WriteConfig(const std::string& key, const std::string& value) const
//{
//    std::fstream f(m_fileName);
//    bool found = false;
//    std::vector<std::string> fileContent;
//    while (!f.eof())
//    {
//        auto elem = new char[500];
//        f.getline(elem, 500);
//        auto line = std::string(elem);
//        if (line.empty())
//        {
//            fileContent.emplace_back(line);
//            continue;
//        }
//        if (line.starts_with(k_commentLineStart))
//        {
//            fileContent.emplace_back(line);
//            continue;
//        }
//        if (!line.starts_with(key))
//        {
//            fileContent.emplace_back(line);
//            continue;
//        }
//        found           = true;
//        std::string val = line.substr(0, line.find_last_of('='));
//        val += "= " + value;
//        fileContent.emplace_back(val);
//    }
//
//    f.close();
//    std::ofstream o(m_fileName);
//    if (!found)
//    {
//        std::string val = key + " = " + value;
//        fileContent.emplace_back(val);
//    }
//    for (std::string elem : fileContent) o << elem << "\n";
//    o.close();
//    fileContent.clear();
//}
