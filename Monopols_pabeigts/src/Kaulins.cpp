#include "Kaulins.h"

Kaulins::Kaulins()
{
    this->vertiba = 0;
}

Kaulins::~Kaulins()
{
    //dtor
}
int Kaulins::mest(){
/** atgriež metamo kauliņu summu*/
    srand(time(NULL));

    this->vertiba = rand() % 6 + 1;



    return this->vertiba;
}
int Kaulins::getVertiba(){
    return this->vertiba;
}
