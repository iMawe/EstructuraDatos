#include "RB.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    RB<int, int> treerb;

    treerb[17] = 2;
    treerb[7] = 2;
    treerb[90] = 2;
    treerb[4] = 2;
    treerb.remove(7,0);
    treerb.draw();


    return 0;
}