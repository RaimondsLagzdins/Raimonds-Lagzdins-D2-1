#ifndef LAUKS_H
#define LAUKS_H
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class Lauks
{
    public:

        Lauks(int, string, int);
        virtual ~Lauks();
        void printInfo();

        void setId(int);
        int getID();

        void setPrice(int);
        int getPrice();
        void setName(string);

        void setOwned(int);
        bool getOwned();


        void setIpasnieks(int);
        int getIpasnieks();
    protected:
        string name;

        int id;
        int price;
        int ipasnieks;

        bool isOwned;
    private:

};

#endif // LAUKS_H


