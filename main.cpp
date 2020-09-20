//
//  main.cpp
//  labirynt
//
//  Created by kuba dyrba on 16/09/2020.
//  Copyright © 2020 Jakub Dyrba. All rights reserved.
//

#include <iostream>
#include <fstream>
int main(int argc, const char * argv[]) {
    using namespace std;
    fstream plik;
    plik.open("labirynt.txt");
    cout << "Hello, World!\n";
    return 0;
}
