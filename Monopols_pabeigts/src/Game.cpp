#include "Game.h"

Game::Game()
{
    string vards;
    int skaits;

    /** Spēlētāju izveide
    */

    do{
        cout << "Ievadi lūdzu spēlētāju skaitu: no 2-6 cilvēki " << endl;
            cin >> skaits;

    }while(!(skaits >= 2 && skaits <=6));

    for(int i = 1; i <= skaits; i++){
    cout << "Ievadi " << i << ". speletaja vardu: ";
        cin >> vards;
    speletaji.push_back(new Player(vards, i));
    }



    cout << endl;
    cout << "Speles noteikumi: " << endl;
    cout << "Kad tiek prasīts izvēlnē ievadīt savu izvēli, tad jums ir jāievada kāds no cipariem kas ir rindas priekšā! " << endl;
    cout << "Spēle beidzas kad paliek viens spēlētājs " << endl;
    cout << "Ja jūs esat uzkāpis uz kāda no pretinieka lauciņa un jums pietrūkst nauda, lai viņam samaksātu jūs esiet zaudējis! " << endl;

    system("pause");
    /** Ielādē īpašumus */
    fails.open("ipasumi.txt");
    do{

        int id, price;
        string name, linija;

        getline(fails,linija);
        id = StringToInt(linija);

        getline(fails,linija);
        name = linija;

        getline(fails,linija);
        price = StringToInt(linija);


        lauki.push_back(new Lauks(id, name, price));
    }while(!fails.eof());
    fails.close();



}

Game::~Game()
{
    delete k1;
    delete k2;
    delete p;
    delete l;
    delete ipasnieks;
    delete ipasums;
}


void Game::start(){

    while(speletaji.size() > 1){

        for(int i = 0; i < speletaji.size(); i++ ){
            this->p = speletaji.at(i); /** tiek izvēlēts spēlētājs */
            this->makeMove();

            if(this->p->getMoney() <= 0){
                cout << "Speli beidz " << this->p->getName() << endl;
                speletaji.erase(speletaji.begin()+i);
                this->deletePlayer();
            }
        }

        if(speletaji.size() == 1){
            this->p = speletaji.at(0);
            cout << this->p->getName() << " uzvarēja!!!!" << endl;
        }
    }
}
void Game::makeMove(){
    /** Spēlētājs veic gājienu */
    int i = 0;
    do{

        cout << "___________________________________________________" << endl;
        cout << this->p->getName();
        cout << " veic gājienu " << i + 1 << ". reizi" << endl;

        this->p->printInfo();

        sleep_for(600ms);
        k1->mest();
        sleep_for(600ms);
        k2->mest();

        cout << "Jūsu uzmestie kauliņi: " << k1->getVertiba() <<  " un " << k2->getVertiba() << endl;

        this->p->setVieta((k1->getVertiba()+k2->getVertiba()));
        this->l = lauki.at(p->getVieta()-1);
        this->l->printInfo();

        cout << endl;

        if(!this->izvele()){
            break;
        }

        i++;
        if(i == 3){
            break;
        }
    }while(k1->getVertiba() == k2->getVertiba());
}




int Game::izvele(){

    do{
        cout << endl;
        cout <<"Izvelne " << endl;
        cout <<"______________________________" << endl;
        if(!this->l->getOwned() || this->p->getID() == this->l->getIpasnieks()){
            cout << "|1. pirkt īpašumu            |" << endl;
            cout << "|2. apskatīt savus īpašumus  |" << endl;
            cout << "|3. turpināt                 |" << endl;
            cout << "|____________________________|" << endl;

            this->p->setIzvele();
            switch(this->p->getIzvele()){
                case 1:
                    /** Iespēja pirkt īpašumu */
                    if(!this->l->getOwned()){
                        if(!this->p->getError()){
                            this->p->pirktLauku(this->l->getPrice());
                            this->l->setIpasnieks(this->p->getID());

                            return 1;
                        }

                    }else{
                        cout << "Jums jau pieder šis īpašums! " << endl;
                    }
                    break;

                case 2:
                    /** Iespēja apskatīt savus īpašumus */
                    cout << "Jusu īpašumi: " << endl;

                    for(int i = 0; i < lauki.size(); i++){

                        this->ipasums = lauki.at(i);

                        if(this->ipasums->getOwned() && (this->p->getID() == this->ipasums->getIpasnieks())){
                            this->ipasums->printInfo();
                        }

                    }

                    break;

            }
        }else{


            /** Jāmaksā citiem spēlētajiem par uzkāpšanu uz viņu lauciņa */
            for(int i = 0; i < speletaji.size(); i++){
                this->ipasnieks = speletaji.at(i);
                if(this->l->getIpasnieks() == this->ipasnieks->getID()){
                    cout << "Par uzkapsanu uz " << this->ipasnieks->getName() << " laucina jums bija jamaksa: " << this->l->getPrice() / 5 <<  endl;
                    this->p->substractMoney((this->l->getPrice()/2));

                    if(this->p->getError()){
                        return 0;
                    }
                    this->ipasnieks->addMoney((this->l->getPrice()/2));

                    sleep_for(2s);
                }
            }
            break;
        }



            if(this->p->getIzvele() == 3)
                break;

    }while(this->p->getIzvele() != 3);

}



void Game::deletePlayer(){

    for(int i = 0; i < lauki.size(); i++){
        this->ipasums = lauki.at(i);
        if(this->ipasums->getIpasnieks() == this->p->getID()){
            this->ipasums->setIpasnieks(-1);
            this->ipasums->setOwned(0);
        }
    }

}
