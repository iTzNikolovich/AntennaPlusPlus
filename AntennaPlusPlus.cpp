//
//  main.cpp
//  antennaplusplus
//
//  Created by Nicolò Carcagnì on 01/03/22.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

#define LS 299792.458

void menu();
void quarterwave();
void dipole();

int main(){
    char a;
    do{
        menu();
        std::cout << "Pick a choice [1-x]: ";
        std::cin >> a;
        switch(a){
            case '1':
                quarterwave();
                break;
            case '2':
                dipole();
                break;
        }
    }while(a!='4');
}

void menu(){
    system("clear");
    std::cout << "=========Antenna++=========" << std::endl;
    std::cout << "1. Quarter Wave Antenna" << std::endl;
    std::cout << "2. Dipole Antenna" << std::endl;
    std::cout << "3. Stay Tuned..." << std::endl;
    std::cout << "4. Stay Tuned..." << std::endl;
    std::cout << "===========================" << std::endl;
    return;
}

void quarterwave(){
    float mhz, vf, alenght, blenght, wavelenght;
    std::cout << "Frequency [mhz]: ";
    std::cin >> mhz;
    wavelenght = (LS / mhz) / 10;
    std::cout << "Velocity factor [0 = default]: ";
    std::cin >> vf;
    if(vf == 0){
        std::cout << "Default VF = 0.95" << std::endl;
        alenght = (wavelenght * 0.25 * 0.95);
        blenght = (wavelenght * 0.28 * 0.95);
        std::cout << "Vertical monopole radiating element [A]: " << alenght << " cm" << std::endl;
        std::cout << "Radials [B]: " << blenght << " cm" << std::endl;
    }
    if(vf != 0){
        alenght = (wavelenght * 0.25 * vf);
        blenght = (wavelenght * 0.28 * vf);
        std::cout << "Vertical monopole radiating element [A]: " << alenght << " cm" << std::endl;
        std::cout << "Radials [B]: " << blenght << " cm" << std::endl;
    }
    std::cout << R"(
    |
    | A
    |
   ---
   / \
  /   \
 /     \ B
/       \
    )" << '\n';
    std::exit(0);
}

void dipole(){
    float mhz, lenght;
    std::cout << "Frequency [mhz]: ";
    std::cin >> mhz;
    lenght = (LS / (mhz * 1000)) / 2;
    std::cout << "Dipole lenght [A + B]: " << lenght * 100 << " cm" << std::endl;
    std::cout << R"(
   A         B
-------   -------
       | |
       | |
        *
    )" << '\n';
    std::exit(0);
}
