#include "LinkedList.h"
template <class K, class D>
class Queue
{
private:
	LinkedList<K,D> List;
public:
	Queue();
	void PushBack(K p_key, D p_dato);
	void Pop();
	K Top();
	void Print();
	~Queue();
};

template <class K, class D>
void Queue<Tipo>::PushBack(K p_key, D p_dato)
{
	List.InsertFront(p_key,  p_dato);
}
template <class K, class D>
void Queue<Tipo>::Pop()
{
	List.RemoveBack();
}

template <class K, class D>
K Queue<Tipo>::Top()
{
		cout << "Este es el Top ->" << Lista.raiz->dato << endl;
		return List.raiz->dato;
}
template <class K, class D>
void Queue<Tipo>::Print()
{
	list.Show();
}

template <class K, class D>
Queue<Tipo>::Queue()
{
}

template <class K, class D>
Queue<Tipo>::~Queue()
{
}

