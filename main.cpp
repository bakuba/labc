//
//  main.cpp
//  labirynt
//
//  Created by kuba dyrba on 16/09/2020.
//  Copyright © 2020 Jakub Dyrba. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Labirynt
{
private:
    string labirynt;
    int wysokosc = 0;
    fstream plik;
    void konwertuj();
public:
    int szerokosc = 0;
    string labrob;
    void wczytajLab();
    void info();
    void idz();
    void wyswietLab();
     
};

class Ludzik
{
private:
    
public:
    int wspol, szerokosc;
    string lab;
    char otoczenie[3][3];
    void patrz();
    void wez(string, int);
    void pokazMape();
    void sprawdzLab();
};

///##################################################
void Ludzik::patrz(){
    otoczenie[0][0] = lab[wspol-szerokosc-1];
    otoczenie[0][1] = lab[wspol-szerokosc];
    otoczenie[0][2] = lab[wspol-szerokosc+1];
    otoczenie[1][0] = lab[wspol-1];
    otoczenie[1][1] = lab[wspol];
    otoczenie[1][2] = lab[wspol+1];
    otoczenie[2][0] = lab[wspol+szerokosc-1];
    otoczenie[2][1] = lab[wspol+szerokosc];
    otoczenie[2][2] = lab[wspol+szerokosc+1];
};
void Ludzik::sprawdzLab(){
    int pozycja=NULL, druga=NULL;
    druga = pozycja;

    pozycja = lab.find("X");
    if(pozycja == string::npos){
        cout<<"Nie znaleziono polozenia ludzika!\n";
        return;
    }
    pozycja = lab.find("X");
//    cout<<"Znaleziona pozycja:\n"<<pozycja<<endl;
    if(pozycja > 0){
        druga=pozycja;
    }
    do{
        pozycja = lab.find("X", pozycja+1);
        if(pozycja > 0 && druga != pozycja){
            cout<<"Znaleziono wiecej niz jedna pozycje ludzika! Jest problem!\n";
            return;
        }
        cout<<"Można zaczynac.\n";
    }while(pozycja != string::npos);
    cout<<"Ludzika odnaleziono.\nJego pozycja to:\n"<<druga<<" w jednowymiarowej tablicy znakow.\nMozna zaczynac!!!\n";
    wspol=druga;
};
void Ludzik::wez(string rob, int szer){
    lab = rob;
    szerokosc = szer;
    cout<<"Ludzik wzial zgnieciona mape.\n";
};
void Ludzik::pokazMape(){
//    cout<<"Ludzik pokazuje pognieciona mape:\n"<<lab<<endl;
    cout<<"Ludzik pokazuje posiadany fragment mapy:\n\n";
    for(int i = 0; i<3;i++){
        for(int j=0; j<3; j++){
            cout<<"\t"<<otoczenie[i][j];
        }
        cout << endl;
    }
    cout<<endl;
}

///************************************************************************
void Labirynt::wczytajLab(){
    string roboczy;
    plik.open("//Users/roboczy/labiryntC++/labirynt/labirynt.txt");
    while( plik.good() ){
        plik >> roboczy;
        szerokosc = string(roboczy).length();
        wysokosc++;
        labirynt += roboczy + "\n";
        labrob += roboczy;
    }
    plik.close();
};

void Labirynt::info(){
    cout <<endl<< "Labirynt jest szeroki na " << szerokosc << " i wysoki na " << wysokosc << endl;
};

void Labirynt::wyswietLab(){
 //   cout<<"Labirynt w postaci jednowymiarowej tablicy:\n"<<labrob<<endl;
    cout<<labirynt;
};

int main(int argc, const char * argv[]) {
    Labirynt noowy;
    Ludzik jacek;
    noowy.wczytajLab();
    noowy.info();
    jacek.wez(noowy.labrob, noowy.szerokosc);
    jacek.sprawdzLab();
    cout<<"wspol:\n";
    cout<<jacek.wspol<<endl;
    
    return 0;
}
