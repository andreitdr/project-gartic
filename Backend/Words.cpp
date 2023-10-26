#include "Words.h"

int Words::getRandomIndex()
{
	std::srand(time(NULL));
	return rand() % m_word_list.size();
}

Words::Words(std::vector<std::string> word_list) : m_word_list(word_list)
{
}

std::string Words::getRandomWord() const
{
	int randomIndex = getRandomIndex();
	return m_word_list[randomIndex];
}

void Words::addWord(std::string word)
{
	m_word_list.push_back(word);
}


