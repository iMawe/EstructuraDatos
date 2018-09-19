template <class K, class D>
Node<K,D>::Node(const K k,const D d, Node<K,D> * children){
	key = k;
	dato = d;
	p_child[1] = NULL;
    p_child[0] = NULL;
}
template <class K, class D>
Node<K,D>::~Node(){}

template <class K, class D>
BST<K,D>::~BST(){}

template <class K, class D>
bool BST<K,D>::find(const K & key, D & dato){
	Node<K,D> **n;
	if(find(key, n)){
		dato = (*n)->dato;
		return true;
	}
	return false;
}

template <class K, class D>
bool BST<K,D>::insert(const K & key, const D & dato){
	Node<K,D>** n;
	if(!find(key,n)){
		*n = new Node<K,D>(key,dato);
		return true;
	}
	return false;
}

template <class K, class D>
bool BST<K,D>::find(const K & key, Node<K,D>** &n){
	n = &p_root;
	while(*n){
		if((*n)->key == key)
			return true;
		n = &(*n)->p_child[(*n)->key < key];
	} //while Existe n
	return false;
}

template <class K, class D>
void BST<K,D>::remove(K & key){
	Node<K,D> **n;
	n = &p_root;
	Node<K,D> *temp;

	if(find(key,n) == true){
		temp = *n;

		if(temp->p_child[0] == NULL and temp->p_child[1] == NULL){
			*n=NULL;
			delete temp;
		}

		else if (temp->p_child[0] != NULL and temp->p_child[1] != NULL){
			Node<K,D> *dad;
			Node<K,D> *aux;
			temp = *n;
			aux = temp->p_child[0];
			while(aux->p_child[1] != NULL){
				dad = aux;
				aux = aux->p_child[1];
			}
			(*n)->key = aux->key;
			dad->p_child[0] = NULL;
			dad->p_child[1] = NULL;
			delete (aux);
		}

		else{
			bool c = temp->p_child[0] == 0;//1
			*n = (*n)->p_child[c];
			temp->p_child[c] = NULL;
			delete (temp);
		}
	}

	//remove(&p_root,key);
}

template <class K, class D>
void BST<K,D>::remove(Node<K,D>** n,K key){
	if(*n == NULL) return ;//No es encontrar el valor X de los nodos 
    if(key <(*n)->key) 
    { 
         remove(&(*n)->p_child[0], key);//Si X es inferior al valor del nodo, sigue en el árbol de la izquierda elimina el nodo X 
    }
 
    else if(key > (*n)->key)
    { 
         remove(&(*n)->p_child[1], key);//Si X es mayor que el valor del nodo, sigue en el nodo eliminar X subárbol 
    } 
 
    else//Si son iguales, el nodo es eliminar nodo 
    { 
        if((*n)->p_child[0] && (*n)->p_child[1])//El nodo tiene dos hijos 
        { 
            Node<K,D>* temp = (*n)->p_child[1];//Nodos hijo temp hacia la derecha 
            while(temp->p_child[0]!=NULL) temp=temp->p_child[0];//Encontrar un mínimo de nodos
            //A la derecha en el valor mínimo de nodos subárbol de asignar a este nodo 
            (*n)->key = temp->key;
            (*n)->dato = temp->dato;
            remove(&(*n)->p_child[1],temp->key);//Eliminar nodos en el valor mínimo de la derecha subárbol 
        } 
        else//El nodo tiene un hijo o 1 0 
        { 
            Node<K,D>* temp = *n; 
            if((*n)->p_child[0] == NULL)//Hijo o no, el hijo de la derecha 
            	(*n) = (*n)->p_child[1]; 
            else if((*n)->p_child[1] == NULL)//A la izquierda, hijo 
            	(*n) = (*n)->p_child[0];
            temp = NULL; 
            delete(temp); 
        } 
	}
}//--->tarea

template <class K, class D>
void BST<K,D>::print(){
	cout<<"graph {"<<endl;
	cout<<p_root->key<<endl;
	print(p_root);
	cout<<"}"<<endl;
}

template <class K, class D>
void BST<K,D>::print(Node<K,D> *n){
	if(n!=NULL)
    {
        if(n->p_child[0]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_child[0]->key<<endl;
            print(n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            cout<<n->key;
            cout<<"--";
            cout<<n->p_child[1]->key<<endl;
            print(n->p_child[1]);
        }
    }
}

template <class K, class D>
bool BST<K,D>::removeP(const K & key){
	Node<K,D> **n;
	if(!find(key,n)) return false;
	Node<K,D> *del = *n;
	if((*n)->p_child[0] && (*n)->p_child[1]){
		Node<K,D> **aux = &(*n)->p_child[0];
		while((*aux)->p_child[1])
			aux = &(*aux)->p_child[1];
		if(*aux != (*n)->p_child[0]){
			(*aux)->p_child[1] = (*n)->p_child[1];
			swap((*aux)->p_child[0], (*n)->p_child[0]);
			swap(*n, *aux);
			n = aux;
		}
		else{(*aux)->p_child[1] = (*n)->p_child[1];}
		del->p_child[1] = NULL;
	}
	bool c = del->p_child[0] == NULL;
	*n = del->p_child[c];
	delete del;
}