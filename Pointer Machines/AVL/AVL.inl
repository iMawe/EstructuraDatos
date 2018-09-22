template<class K, class D>
Node<K,D>::Node(const K k, const D d, Node<K,D> * children){
	dato = d;
	key = k;
	h = 0;
	p_child[0] = NULL;
	p_child[1] = NULL;
}

template <class K, class D>
int AVL<K,D>::height(Node<K,D> *n){
	return n == NULL ? -1 : n->h;
}

template <class K, class D>
int AVL<K,D>::max( int a, int b ){
    return a > b ? a : b;
}

template<class K, class D>
void AVL<K,D>::turn_side(Node<K,D>** n, bool dir)
{
    Node<K,D>* tmp = (*n);
    (*n) = (*n)->p_child[dir];
    tmp->p_child[dir] = (*n)->p_child[!dir];
    (*n)->p_child[!dir] = tmp;
}
template<class K, class D>
void AVL<K,D>::doble_turn_side(Node<K,D>** n, bool dir)
{
    turn_side(&(*n)->p_child[dir], !dir);
    turn_side(n, dir);
}

template<class K, class D>
void AVL<K,D>::insert(const K & key, const D & dato){
	insert(&p_root, key, dato);
}

template<class K, class D>
bool AVL<K,D>::insert(Node<K,D>** p, const K &key, const D &d){
   if ((*p) == NULL) {
        (*p) = new Node<K,D>(key, d);
        return true;
    }
    else if( key < (*p)->key ){
        insert(&(*p)->p_child[0], key, d );
        if(height( (*p)->p_child[0] ) - height( (*p)->p_child[1] ) == 2 )
	        if( key < (*p)->p_child[0]->key )
	            turn_side(p, 0);
	        else
	            doble_turn_side(p, 0);
	    return true;
    }
    else if((*p)->key < key ){
        insert(&(*p)->p_child[1], key, d );
        if(height( (*p)->p_child[1] ) - height( (*p)->p_child[0] ) == 2 ){
            if( (*p)->p_child[1]->key < key )
                turn_side(p, 1);
            else
                doble_turn_side(p, 1);
        }
        return true;
    }
    else
        ;
    (*p)->h = max(height( (*p)->p_child[0] ), height( (*p)->p_child[1] ) ) + 1; 

    return true;

}

template<class K, class D>
int AVL<K,D>::getMinValue(Node<K,D>* p){
	if (p == NULL) return 0;	        
	         
	if (p->p_child[0] == NULL) return p->key;
	     
	return getMinValue(p->p_child[0]);
}

template<class K, class D>
void AVL<K,D>::remove(K key){
	remove(&p_root, key);
}

template<class K, class D>
bool AVL<K,D>::remove(Node<K,D>** p, K key){
    if(!(*p))  
    	return false;  
    if((*p)->key > key){  
    	remove(&(*p)->p_child[0], key);  
    }  
    else if((*p)->key < key){  
    	remove(&(*p)->p_child[1], key);  
    }  
    else{
    	if ((*p)->p_child[0] == NULL)
    		(*p) = (*p)->p_child[1];

        else if ((*p)->p_child[1] == NULL)
            (*p) = (*p)->p_child[0];

       	else{
	    int keyaux = getMinValue((*p)->p_child[1]);
	    (*p)->key = keyaux;
	    remove(&(*p)->p_child[1], keyaux);
        } 
    }

    if ((*p) == NULL) return false;

	balanceo(p, (*p)->key);
    return true; 
}
template<class K, class D>
int AVL<K,D>::get_balance(Node<K,D>* p){  
   if(!p)  
     return 0;  
   return (height(p->p_child[0]) - height(p->p_child[1])); 
}

template <class K, class D>
void AVL<K,D>::recalc(Node<K,D>* p)
{
    p->h = 1 + max(height(p->p_child[0]), height(p->p_child[1]));
}

template<class K, class D>
void AVL<K,D>::balanceo(Node<K,D>** p, K key){
	recalc(*p);

	if( height( (*p)->p_child[0] ) - height( (*p)->p_child[1] ) == 2 )
	    if( key < (*p)->p_child[0]->key )
	        turn_side(p, 0);
	    else
	        doble_turn_side(p, 0);
	else if( height( (*p)->p_child[1] ) - height( (*p)->p_child[0] ) == 2 ){
        if( (*p)->p_child[1]->key < key )
            turn_side(p, 1);
        else
            doble_turn_side(p, 1);
    }
}

template<class K, class D>
void AVL<K,D>::printARBOL(){
    cout<<"graph {"<<endl;
    cout<<p_root->dato<<endl;
    printARBOL(p_root);
    cout<<"}";
    system("dot.lnk -Tpng -o < grap.dot > out2.png");
}



template<class K, class D>
void AVL<K,D>::printARBOL(Node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            cout<<n->dato;
            cout<<"--";
            cout<<n->p_child[0]->dato<<endl;
            printARBOL(n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            cout<<n->dato;
            cout<<"--";
            cout<<n->p_child[1]->dato<<endl;
            printARBOL(n->p_child[1]);
        }
    }
}