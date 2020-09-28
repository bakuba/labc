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
int main(int argc, const char * argv[]) {
    int i = 0, szer = 0;
    
    fstream plik;
    string labi;
    plik.open("//Users/roboczy/labiryntC++/labirynt/labirynt.txt");
    while( plik.good() ){

        plik >> labi;
        szer = string(labi).length();
        cout << labi << endl;
         i++;
    }
    cout <<endl<< "Labirynt jest szeroki na " << szer << " i wysoki na " << i << endl;
    cout << endl;

    return 0;
}
