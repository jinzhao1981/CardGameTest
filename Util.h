#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include "Type.h"
using namespace std;

class Util{
    public:
        static string toString(Suit suit);
        static string toString(FaceValue faceValue);
        static bool isVerbose();
        static int maxSupportedPlayers();
        static int maxSupportedDecks();
};
#endif