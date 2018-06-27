#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Player
{
    public:
        Player(string, int);
        virtual ~Player();
        string getName();

        int getID();

        int getMoney();
        void setMoney(int);

        void addMoney(int);
        void substractMoney(int);

        void setVieta(int);
        int getVieta();

        void pirktLauku(int);


        void setIzvele();
        int getIzvele();

        void setError(int);
        bool getError();

        void printInfo();

    protected:

    private:
        string name;

        int money;
        int id;
        int vieta;
        int izvele;

        bool error;

};

#endif // PLAYER_H
