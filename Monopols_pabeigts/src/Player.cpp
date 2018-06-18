#include "Player.h"

Player::Player(string name)
{
    this->name = name;
    this->money = 1500;
    this->vieta = 1;
}

Player::~Player()
{
    //dtor

}

string Player::getName(){
    return this->name;
}

int Player::getID(){
    return this->id;
}

int Player::getMoney(){
    return this->money;
}

void Player::setMoney(int vertiba){
    this->money = vertiba;
}

void Player::addMoney(int vertiba){
    int nauda;

    nauda = this->getMoney();
    nauda += vertiba;
    this->setMoney(nauda);

}

void Player::substractMoney(int vertiba){
    int nauda;

    this->setError(0);

    nauda = this->getMoney();
    if(nauda >= vertiba){
        nauda -= vertiba;
        this->setMoney(nauda);
    }else{
        cout << "Nepietiek nauda!" << endl;
        this->setError(1);
    }
}

void Player::setVieta(int vertiba){

    if((getVieta()+vertiba) > 30){
            cout << "Jūs šķērsojāt starta lauciņu, par to jums tiek pieskaītas 100 naudas vienības " << endl;
            this->addMoney(100);
        this->vieta = ((vieta + vertiba) - 30);
    }

    this->vieta += vertiba;
}

int Player::getVieta(){
    return this->vieta;
}

void Player::pirktLauku(int cena){

    this->substractMoney(cena);

        if(!this->getError()){
            cout << endl;
            cout << "____________________________" << endl;
            cout << "|Pirkums veiksmīgs!         |" << endl;
            cout << "|Jums atlikusī nauda: " << this->getMoney() << "  |" <<endl;
            cout << "|___________________________|" << endl;
            cout << endl;
        }
}

void Player::setIzvele(){
    bool okay;
    while (!okay){
		okay = true;
		cout << "Ievadi savu izveli: " << endl;
            cin >> this->izvele;
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Ludzu ievadi tikai ciparu" << endl;
			okay = false;
		}

	}
}
int Player::getIzvele(){
    return this->izvele;
}


void Player::printInfo(){
    cout << "Spēlētājs : " << this->getName() << endl;
    cout << "Jums pieejamā nauda: " << this->getMoney() << endl;
}


void Player::setError(int error){
    this->error = error;
}
bool Player::getError(){
    return this->error;
}
