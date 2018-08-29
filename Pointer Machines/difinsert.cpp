#include <iostream>
#include <ctime>
#include <cstdio>
#include "LinkedList.h"
using namespace std;

int main(){
	const int N = 1000000000;
	int * aint;
	float ta, tl;
	for(int n = 10; n <= N; n *= 10){
	ta = clock();
	aint = new int[n];
	for(int i = 0; i < n; i++)
		aint[i] = i*i;
	delete []aint;
	ta = clock() - ta;
	tl = clock();
	LinkedList<int,int> * lint = new LinkedList<int,int>();
	for(int i = 0; i < n; i++)
		lint->InsertFront(i*i,i);
	delete lint;
	tl = clock()-tl;
	printf("%d %4.3f %4.3f \n", n, ta / CLOCKS_PER_SEC, tl / CLOCKS_PER_SEC);
	}
	
	return 0;
}