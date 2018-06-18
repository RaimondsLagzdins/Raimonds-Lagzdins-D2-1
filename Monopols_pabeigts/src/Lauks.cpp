#include "Lauks.h"

Lauks::Lauks(int id, string name, int price)
{
    this->id = id;
    this->name = name;
    this->price = price;
    this->ipasnieks = -1;
    this->isOwned = false;

}

Lauks::~Lauks()
{
    //dtor
}


void Lauks::printInfo(){

    cout << this->name << endl;
    cout << "Cena: " <<  this->price << endl;
}


void Lauks::setId(int id){
    this->id = id;
}



void Lauks::setPrice(int cena){
    this->price = cena;
}

int Lauks::getPrice(){
    return this->price;
}

void Lauks::setName(string nosaukums){
    this->name = nosaukums;
}

void Lauks::setOwned(int check){
    if(check){
        this->isOwned = true;
    }else{
        this->isOwned = false;
    }
}
bool Lauks::getOwned(){
    return this->isOwned;
}

void Lauks::setIpasnieks(int ipasniekaID){
    this->ipasnieks = ipasniekaID;
    this->setOwned(1);
}

int Lauks::getIpasnieks(){
    return this->ipasnieks;
}
