template <class K, class D>
class Nodo
{
private:
	
public:
	K key;
	D dato;
	Nodo* siguiente;
	Nodo* anterior;


	Nodo(K p_key, D p_dato);
	D  GetDato();
	void  SetSiguiente(Nodo* p_nodo);
	Nodo* GetAnterior()
	{
		return anterior;
	}
	Nodo*  GetSiguiente()
	{
		return  siguiente;
	}
	~Nodo();
};

template <class K, class D>
void Nodo<K,D>::SetSiguiente(Nodo* p_nodo)
{
	siguiente = p_nodo;
	
}

template <class K, class D>
Nodo<K,D>::Nodo(K p_key, D p_dato)
{
	key = p_key;
	dato = p_dato;
	siguiente = nullptr;
	anterior = nullptr;
}

template <class K, class D>
D Nodo<K,D>::GetDato()
{
	return dato;
}

template <class K, class D>
Nodo<K,D>::~Nodo()
{
	//this->dato = nullptr;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}