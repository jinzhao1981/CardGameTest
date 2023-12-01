#ifndef GAME_MGR_H_
#define GAME_MGR_H_
#include <string>
#include <memory>
#include "Game.h"
using namespace std;

class GameMgr{
    public:
        static GameMgr& getInstance();

        unique_ptr<Game> createGame(string name="game");

    private:
        static GameMgr* instance;
        GameMgr(){}
        ~GameMgr(){}
};
#endif
