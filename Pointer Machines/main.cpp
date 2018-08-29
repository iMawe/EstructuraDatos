#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
	LinkedList<int, int> list;

	list.InsertFront(1,23);
	list.InsertFront(2,12);
	list.InsertBack(3,45);
	list.Show();
	cout<<endl;
	list.InsertFront(4,21);
	list.InsertFront(5,48);
	list.Show();
	cout<<endl;
	list.RemoveFront();
	list.Show();
	cout<<endl;
	list.RemoveBack();
	list.Show();
	cout<<endl;
	list.InsertBack(7,23);
	list.Show();

	return 0;
}