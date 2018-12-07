#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string>
#include <winbgim.h> 

#include "KDTree.h"
#include "KDNode.h"

using namespace std;



DrawnP(){
	setcolor(3);				
	moveto(5, 0);					
	lineto(5, 600);//Y 605
	moveto(0, 595);					
	lineto(600, 595);//X 600
};

int main() {
    
    initwindow(600, 650);
	DrawnP();
	
    
    while(!kbhit()) delay(1);
    return 0;
}
