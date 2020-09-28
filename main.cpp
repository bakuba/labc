//
//  main.cpp
//  labirynt
//
//  Created by kuba dyrba on 16/09/2020.
//  Copyright © 2020 Jakub Dyrba. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

class Labirynt
{
private:
public:
    int wysokosc = 0, szerokosc = 0, szer, wys = 0 ;
    fstream plik;
    fstream wczytajLab();
    void info();
    void idz();
    
};

fstream Labirynt::wczytajLab(){
    fstream plik;
    string labi;
    plik.open("//Users/roboczy/labiryntC++/labirynt/labirynt.txt");
    while( plik.good() ){
        plik >> labi;
        szer = string(labi).length();
        wys++;
    }
    return plik;
};

void Labirynt::info(){
    cout <<endl<< "Labirynt jest szeroki na " << szer << " i wysoki na " << wys << endl;
};


int main(int argc, const char * argv[]) {
    string wiersz;
    Labirynt noowy;
    noowy.Labirynt::wczytajLab();
    noowy.plik >> wiersz;
    noowy.info();
    cout << wiersz;
    return 0;
}
