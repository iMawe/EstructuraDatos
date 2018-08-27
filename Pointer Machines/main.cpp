#include <iostream>
using namespace std;

#include "LinkedList.h"

int main(){
	LinkedList list;
	list.Insert(1,23);
	list.Insert(2,12);
	list.Insert(3,45);
	list.Insert(4,21);
	list.Insert(5,48);
	list.Remove(3);
	list.Insert(6,65);
	list.Insert(7,23);
	list.Show();

	return 0;
}