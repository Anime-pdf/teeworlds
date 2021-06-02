#ifndef GAME_SERVER_DISCORD_BOT_H
#define GAME_SERVER_DISCORD_BOT_H

#include <game/server/gamecontext.h>
#include <dpp/dpp.h>


class CDiscordBot
{
public:
	std::string Token;
    CDiscordBot(CGameContext *pGS);
    void LogChat(int Team, std::string Nickname, std::string Message);
    void LogEnter(std::string Nickname);
    void LogExit(std::string Nickname);
private:
    CGameContext* m_pGS
};

#endif
