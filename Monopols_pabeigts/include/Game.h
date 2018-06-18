#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Kaulins.h"
#include "Player.h"
#include <stdlib.h>
#include "Funkcijas.h"
#include <thread>
#include <conio.h>
#include <vector>
#include <windows.h>
#include "Lauks.h"
#include "../src/config.cpp"
using namespace std::this_thread;
using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void makeMove();
        void start();
        void deletePlayer();
        int izvele();

    protected:

    private:
        Kaulins *k1 = new Kaulins;
        Kaulins *k2 = new Kaulins;
        Player *p = nullptr;
        Player *ipasnieks = nullptr;
        Lauks *ipasums = nullptr;
        Lauks *l = nullptr;


        ifstream fails;
        vector<Player *> speletaji;
        vector<Lauks *> lauki;

};

#endif // GAME_H
