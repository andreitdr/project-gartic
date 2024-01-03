export module Config;

import <string>;
import <fstream>;
import <vector>;


export class ConfigFile
{
public:
    ConfigFile(const std::string& fileName);
    auto ReadConfig(const std::string& key) const;
    void WriteConfig(const std::string& key, const std::string& value) const;

private:
    const std::string m_fileName;
};

ConfigFile::ConfigFile(const std::string& fileName): m_fileName{fileName}
{
}

auto ConfigFile::ReadConfig(const std::string& key) const
{
    std::ifstream f(m_fileName);
    while (!f.eof())
    {
        auto elem = new char[500];
        f.getline(elem, 500);
        auto line = std::string(elem);
        if (line.empty()) continue;
        if (line.starts_with('#')) continue;
        if (!line.starts_with(key)) continue;
        std::string val = line.substr(line.find_last_of('=') + 1, line.size());
        while (val.starts_with(' ')) val = val.substr(1, val.size());
        while (val.ends_with(' ')) val = val.substr(0, val.size() - 1);
        f.close();
        return val;
    }
    f.close();
    throw std::exception("Key not found!");
}


void ConfigFile::WriteConfig(const std::string& key, const std::string& value) const
{
    std::fstream f(m_fileName);
    bool found = false;
    std::vector<std::string> fileContent;
    while (!f.eof())
    {
        auto elem = new char[500];
        f.getline(elem, 500);
        auto line = std::string(elem);
        if (line.empty())
        {
            fileContent.emplace_back(line);
            continue;
        }
        if (line.starts_with('#'))
        {
            fileContent.emplace_back(line);
            continue;
        }
        if (!line.starts_with(key))
        {
            fileContent.emplace_back(line);
            continue;
        }
        found           = true;
        std::string val = line.substr(0, line.find_last_of('='));
        val += "= " + value;
        fileContent.emplace_back(val);
    }

    f.close();
    std::ofstream o(m_fileName);
    if (!found)
    {
        std::string val = key + " = " + value;
        fileContent.emplace_back(val);
    }
    for (std::string elem : fileContent) o << elem << "\n";
    o.close();
    fileContent.clear();
}
