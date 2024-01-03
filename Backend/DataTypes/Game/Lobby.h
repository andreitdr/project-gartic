#pragma once
#include <string>

struct Lobby
{
    int m_index;
    int m_lobbyId;
    int m_leaderId;

    int m_lobbyType;
    bool m_isPrivate;
    std::string m_userIds; // JSON string
};
