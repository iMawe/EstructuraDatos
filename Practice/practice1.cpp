#include <iostream>
#include <ctime>
using namespace std;

int main(){
	const int N = 1000000000;
	int * aint;
	for(int n = 10; n <= N; n *= 10){
	ta = clock();
	aint = new int[n];
	for(int i = 0; i < n; i++)
		aint[i] = i*i;
	delete []aint;
	ta = claock() - ta;	
	}
}