#include <iostream>
#include "AVL.h"
using namespace std;

int main(){

	AVL<int,int> tree;
	
	for(int i=1; i<20; i++){
		tree.insert(i,1);
		tree.printARBOL(i);
	}
	tree.remove(15);
	return 0;
}