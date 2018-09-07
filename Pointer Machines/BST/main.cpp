#include <iostream>
#include "BST.h"
#include <stdlib.h>
using namespace std;

int main(){
	BST<int,int> tree;
	int a=0;
	for(int i=1; i<100; i++){
		a = rand() % 100;
		tree.insert(a,1);
	}
	tree.remove(41);
	tree.print();



	return 0;
}