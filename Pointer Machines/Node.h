template <class K, class D>
class Node
{
private:
	
public:
	K key;
	D dato;
	Node* siguiente;
	Node* anterior;


	Node(K p_key, D p_dato);
	K GetKey();
	D GetDato();
	void  SetSiguiente(Node* p_node);
	Node* GetAnterior()
	{
		return anterior;
	}
	Node* GetSiguiente()
	{
		return siguiente;
	}
	~Node();
};

template <class K, class D>
void Node<K,D>::SetSiguiente(Node* p_node)
{
	siguiente = p_node;
	
}

template <class K, class D>
Node<K,D>::Node(K p_key, D p_dato)
{
	key = p_key;
	dato = p_dato;
	siguiente = nullptr;
	anterior = nullptr;
}

template <class K, class D>
D Node<K,D>::GetDato()
{
	return dato;
}

K Node<K,D>::GetKey()
{
	return key;
}

template <class K, class D>
Node<K,D>::~Node()
{
	//this->dato = nullptr;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}