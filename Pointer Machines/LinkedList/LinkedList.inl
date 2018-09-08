template <class K, class D>
void Node<K,D>::SetSiguiente(Node* p_node)
{
	siguiente = p_node;
	
}

template <class K, class D>
D Node<K,D>::GetDato()
{
	return dato;
}

template <class K, class D>
K Node<K,D>::GetKey()
{
	return key;
}

template <class K, class D>
Node<K,D>::~Node()
{
	/*this->key = nullptr;
	this->dato = nullptr;*/
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template <class K, class D>
LinkedList<K,D>::LinkedList()
{
	p_head = nullptr;
	p_last = nullptr;
	sn = new Node<K,D>[100];
	idxfree = 0;
	p_free = nullptr;
}

template <class K, class D>
LinkedList<K,D>::LinkedList(const LinkedList & List)
{
	const Node<K,D> *HeadList = List.p_head;
	Node<K,D> *tmp = nullptr;

	if(HeadList != nullptr){
	    p_head = new Node<K,D>(HeadList -> dato);
	    tmp = p_head;
		HeadList = HeadList -> siguiente;
	}
	while (HeadList != nullptr) {
	    Node<K,D> *New = new Node<K,D>(HeadList -> dato);
	    tmp -> siguiente = New;
	    tmp = tmp -> siguiente;
	    HeadList = HeadList -> siguiente;
	}
}

template <class K, class D>
LinkedList<K,D> & LinkedList<K,D>::operator = (const LinkedList & List){
	LinkedList<K,D> copy(List);
	swap(copy.p_head, p_head);
	return *this;
}

template <class K, class D>
LinkedList<K,D>::~LinkedList()
{
}

/*template <class K, class D>
void LinkedList<K,D>::Insert(const K & p_key, const D & p_dato){
	int idxfree = 0;
	aux = &sn[idxfree++];
	aux->dato = p_dato;
	if(p_head == nullptr){
		p_head = aux;
		aux->siguiente = nullptr;
	}
	else{
		aux->siguiente = p_head;
		p_head = aux;
	}
}*/

template <class K, class D>
void LinkedList<K,D>::InsertFront(const K & p_key, const D & p_dato)
{
	Node<K,D>* aux;
	if(p_head == nullptr){//lista vacia
		aux = &sn[idxfree];
		aux->dato = p_dato;
		p_head = aux;
		p_last = aux;
		aux->siguiente = nullptr;
		idxfree++;
	}
	else if(p_free != nullptr){
		p_free->dato = p_dato;
		p_free->siguiente = p_head;
		p_head = p_free;
	}
	else{
		aux = &sn[idxfree];
		aux->dato = p_dato;
		aux->siguiente = p_head;
		p_head = aux;
		idxfree++;
	}

	/*if (raiz == nullptr)
	{
		raiz = new Node<K,D>(p_key, p_dato);
		return true;
	}
	else
	{
		Node<K,D>* actual = raiz;
	
		while (actual!=nullptr)
		{
			if (actual->GetSiguiente()==nullptr)
			{
				Node<K,D>* Nuevo= new Node<K,D>(p_key, p_dato);
				actual->SetSiguiente(Nuevo);
				Nuevo->siguiente = nullptr;
				return true;
			}
			else
			{
				actual=actual->GetSiguiente();
			}
		}
		
	
		return true;
	}*/
}

template <class K, class D>
void LinkedList<K,D>::Show()
{
	Node<K,D>* actual = p_head;
	while(actual != nullptr)
	{
		cout << actual->GetKey()<<"->";
		actual = actual->GetSiguiente();
	}
}

template <class K, class D>
void LinkedList<K,D>::RemoveFront()
{
	if(p_head == p_last){
		p_free = p_head;
		p_head = nullptr;
		p_last = nullptr;
	}
	else{
		p_free = p_head; 
		p_head = p_head->siguiente; 
		p_free->siguiente = p_free;
	}
	/*if (raiz != nullptr)
	{
		Node<K,D>* Actual = raiz;
		Node<K,D>* Temp = Actual;

		while (Actual->siguiente != nullptr)
		{
			Temp = Actual;			
			Actual = Actual->siguiente;		
			
	    }
		Temp->siguiente = Actual->siguiente;
		delete Actual;
		return true;
	}
	else
		return false;
	return false;*/
}

template <class K, class D>
Node<K,D>* LinkedList<K,D>::GetHead()
{
	return p_head;
}

template <class K, class D>
void LinkedList<K,D>::InsertBack(const K & p_key, const D & p_dato){
	Node<K,D>* aux;
	if(p_head == nullptr){
		aux = &sn[idxfree];
		aux->dato = p_dato;
		p_head = aux;
		p_last = aux;
		p_head->siguiente = nullptr;
		p_last = aux;
		idxfree++;
	}
	else if(p_free != nullptr){
		p_free->dato = p_dato;
		p_last->siguiente = p_free;
		p_last = p_free;
	}
	else{
		aux = &sn[idxfree];
		aux->dato = p_dato;
		p_last->siguiente = aux;
		p_last = aux;
		idxfree++;
	}
	p_last->siguiente = nullptr;

	/*if (raiz == nullptr)
	{
		raiz = new Node<K,D>(p_key, p_dato);
		return true;
	}
	else
	{
		Node<K,D>* actual = raiz;
		Node<K,D>* Nuevo= new Node<K,D>(p_key, p_dato);
		Nuevo->siguiente = actual;
		raiz = Nuevo;
		return true;
	}*/	
}

template <class K, class D>
void LinkedList<K,D>::RemoveBack(){
	Node<K,D>* aux = p_head;
	if(aux->siguiente != nullptr){
		while((aux->siguiente)->siguiente != nullptr){
			aux = aux->siguiente;
		}
		p_free = aux->siguiente;
		aux->siguiente = nullptr;
	}
	else{
		p_free = p_last;
		p_head = nullptr;
		p_last = nullptr;

	}
	/*if (raiz != nullptr)
	{
		Node<K,D>* Actual = raiz;

		if(Actual->siguiente != nullptr)
		{	
			raiz = Actual->siguiente;
			Actual = nullptr;
			delete Actual;
			return true;
		}

		else
		{
			raiz = nullptr;
			delete raiz;
			return true;
		}
	}
	else{
		return false;
	}
	return false;*/
}
