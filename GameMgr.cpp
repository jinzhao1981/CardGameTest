#include "GameMgr.h"

GameMgr* GameMgr::instance=nullptr;
GameMgr& GameMgr::getInstance(){
    if(!instance){
        srand(time(NULL));
        instance = new GameMgr();
    }
    return *instance;
}

unique_ptr<Game> GameMgr::createGame(string name){
    unique_ptr<Game> ptr;
    ptr = make_unique<Game>(name);
    return ptr;
}

