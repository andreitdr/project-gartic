#pragma once
#include <vector>
#include <time.h>

class Words
{
private:
	std::vector<std::string> m_word_list;
	int getRandomIndex();
public:
	Words(std::vector<std::string> word_list);
	std::string getRandomWord() const;
	void addWord(std::string word);
	
};