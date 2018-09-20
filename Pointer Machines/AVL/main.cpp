#include <iostream>
#include "AVL.h"
#include <stdlib.h>
using namespace std;

int main(){

	AVL<int,int> tree;
	int a=0;
	for(int i=1; i<20; i++){
		tree.insert(i,1);
	}
	return 0;
}