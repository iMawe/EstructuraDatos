#include "LinkedList.h"
template <class K, class D>
class Stack
{
private:
	LinkedList<K,D> List;
public:
	Stack();
	void Push(K p_key, D p_dato);
	void Pop();
	K Top();
	void Print();

	~Stack();

};

template <class K, class D>
void Stack<K,D>::Push(K p_key, D p_dato)
{
	List.InsertFront(p_key, p_dato);
}

template <class K, class D>
void Stack<K,D>::Pop()
{
	List.RemoveFront();
}

template <class K, class D>
K Stack<K,D>::Top()
{
	//cout <<"Dato Top -> "<< Lista.raiz->dato << endl;
	return List.raiz->dato;
}

template <class K, class D>
void Stack<K,D>::Print()
{
	List.Show();
}

template <class K, class D>
Stack<K,D>::Stack()
{
}

template <class K, class D>
Stack<K,D>::~Stack()
{
}
