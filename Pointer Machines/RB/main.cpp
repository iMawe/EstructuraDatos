#include "RB.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main(){
    RB<int, int> treerb;
    int iSecret, jSecret;
    srand (time(NULL));


    for(int i=1;i<30;i++){
        iSecret = rand() % 30 + 1;
        treerb[iSecret] = i;  
    }

    for(int j=31;j<50;j++){
        jSecret = rand() % 30 + 1;
    	treerb.remove(jSecret, 0);
    }
    treerb.draw();


    return 0;
}