#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;

#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

int main(){
	LinkedList<int, int> list;
	Queue<int,int> queue;
	Stack<int,int> stack;

	queue.PushBack(1,23);
	queue.PushBack(2,23);
	queue.PushBack(3,23);
	queue.PushBack(4,23);
	queue.Pop();
	queue.Top();
	queue.Print();

	cout<<endl;

	stack.Push(1,23);
	stack.Push(2,23);
	stack.Push(3,23);
	stack.Push(4,23);
	stack.Pop();
	stack.Top();
	stack.Print();	
/*
	list.InsertFront(1,23);
	list.InsertFront(2,12);
	//list.InsertBack(3,45);
	list.Show();
	cout<<endl;
	list.InsertFront(4,21);
	list.InsertFront(5,48);
	list.Show();
	cout<<endl;
	//list.RemoveFront();
	//list.Show();
	cout<<endl;
	//list.RemoveBack();
	//list.Show();
	cout<<endl;
	//list.InsertBack(7,23);
	//list.Show();
*/
	/*const int N=1000000000;
	int *aint;
	for (int n = 10; n <= N; n*=10)
	{
		float ta=clock();
		aint=new int[n];
		for(int i=0; i<n; i++){
			aint[i]=i*i;
		}
		delete []aint;
		ta=clock()-ta;
		float tl = clock();
		LinkedList<int,int> * lint=new LinkedList<int,int>;
		for(int i=0; i<n; i++){
			lint->InsertFront(i*i,i+1);
		}
		delete lint;
		tl=clock()-tl;
		printf("%d %.3f %.3f \n", n, ta / CLOCKS_PER_SEC, tl / CLOCKS_PER_SEC);
	}*/

	return 0;
}