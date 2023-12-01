# CardGameTest

* Assumptions:
1) single thread environment. it needs to add lock for multi-thread environment
2) Game::getPlayers() is called as often as Game::dealCards(). so it sorts players in dealCards() to keep getPlayers() efficient.
    if not, will not update players in dealCards() and will sort the players in getPlayers()
3) Supports maximum Util::maxSupportedPlayers() (for example, 1000000) Players
4) Supports maximum Util::maxSupportedDecks() (for example, 1000000) decks of cards

* how to run:
1) clone the repo and cd the the repo
2) sh run
3) ./main
