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
        if( height( (*p)->p_child[0] ) - height( (*p)->p_child[1] ) == 2 )
	        if( key < (*p)->p_child[0]->key )
	            turn_side(p, 0);
	        else
	            doble_turn_side(p, 0);
	    return true;
    }
    else if( (*p)->key < key ){
        insert(&(*p)->p_child[1], key, d );
        if( height( (*p)->p_child[1] ) - height( (*p)->p_child[0] ) == 2 ){
            if( (*p)->p_child[1]->key < key )
                turn_side(p, 1);
            else
                doble_turn_side(p, 1);
        }
        return true;
    }
    else
        ;
    (*p)->h = max( height( (*p)->p_child[0] ), height( (*p)->p_child[1] ) ) + 1; 

    return true;

}

template<class K, class D>
void AVL<K,D>::balanceo(Node<K,D>** n){
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