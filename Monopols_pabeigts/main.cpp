#include <iostream>
#include "Game.h"
using namespace std;



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Game * g = new Game;
    g->start();
    delete g;
    return 0;
}
