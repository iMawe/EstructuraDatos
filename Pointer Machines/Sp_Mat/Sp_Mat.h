#include <cstdio>
#include <iostream>
#include <stddef.h>
#include <iterator>

using namespace std;

template <class T>
struct Node{
	T value;
	unsigned posij[2];
	Node<Node> * p_next[2]; //[0] = Fila, [1] = Columna
}

template <class >
class Sp_Mat{
private:
	Node<T> ** ptr_index[2]; //[0] = Filas, [1] = Columnas
	unsigned int m,n;
public:
	Sp_Mat();
	~Sp_Mat();
	T& operator ()(unsigned int m, unsigned int n);
	&ofstream operator << ();

	bool find(Node<T> **& n, const int & i, const int & p, const bool & b);
}



