template<class K, class D>
Node<K,D>::Node(const K k, const D d, Node<K,D> * children){
	dato = d;
	key = k;
	h = 0;
	p_child[0] = NULL;
	p_child[1] = NULL;
}

template <class K, class D>
int AVL<K,D>::height(Node<K,D> *p){
	recalc(p);
	return p == NULL ? -1 : p->h;
}

template <class K, class D>
int AVL<K,D>::max( int a, int b ){
    return a > b ? a : b;
}

template<class K,class D>
Node<K,D>* AVL<K,D>::Min(Node<K,D> **p)
{
    if(*p == NULL)
        return NULL;
    else if((*p)->p_child[0] == NULL)
        return *p;
    else
        return Min(&(*p)->p_child[0]);
}

template<class K, class D>
void AVL<K,D>::turn_side(Node<K,D>** p, bool dir)
{
    Node<K,D>* tmp = (*p);
    (*p) = (*p)->p_child[dir];
    tmp->p_child[dir] = (*p)->p_child[!dir];
    (*p)->p_child[!dir] = tmp;
}
template<class K, class D>
void AVL<K,D>::doble_turn_side(Node<K,D>** p, bool dir)
{
    turn_side(&(*p)->p_child[dir], !dir);
    turn_side(p, dir);
}

template<class K,class D>
void AVL<K,D>::find(K key){
    Node<K,D> **aux;
    if(find(key, aux) == true){
        cout<< "elemento " << key << " a sido encontrado" <<endl;
    }else{
        cout<< key << " Elemento no encontrado";
    }

}

template<class K,class D>
bool AVL<K,D>::find(K key,Node<K,D> **&tmp){
    tmp = &p_root;
    while(*tmp){
       
            if((*tmp)->key == key){
                return true;
            } 
            tmp = &(*tmp)->p_child[((*tmp)->key < key)];
       }
    return false;
}

template<class K, class D>
void AVL<K,D>::insert(const K & key, const D & dato){

	insert(&p_root, key, dato);
}

template<class K, class D>
bool AVL<K,D>::insert(Node<K,D>** p, const K &key, const D &d){
   if(*p==NULL){ 
        *p=new Node<K,D>(key, 1); 
        (*p)->key = key; 
        return true;
    }

    if((*p)->key == key)
    	return false;

    bool dir = (*p)->key < key;

    if(insert(&(*p)->p_child[dir], key, d))
    	balanceo(p, dir);

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
    Node<K,D>* temp;
    if (*p == NULL)
        return false;

    if((*p)->key == key){
        if((*p)->p_child[0] && (*p)->p_child[1]){
            
            temp = Min(&(*p)->p_child[1]);
            (*p)->key = temp->key;
            remove(&(*p)->p_child[1], (*p)->key); 
        }

        else{
            temp = *p;
            if((*p)->p_child[0] == NULL)
                *p = (*p)->p_child[1];
            
            else if((*p)->p_child[1]== NULL)
                *p = (*p)->p_child[0];
            
            delete temp;
        }

        if(*p==NULL)
            return false;
        
    }
    bool dir = (*p)->key < key; 
    if(remove(&(*p)->p_child[dir],key))
        return balanceo(p, dir);
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
bool AVL<K,D>::balanceo(Node<K,D>** p, bool dir){
    Node<K,D> * tmp  = (*p)->p_child[dir];

    int hp = height((*p)->p_child[0])-height((*p)->p_child[1]);
    int htmp = height(tmp->p_child[0])-height(tmp->p_child[1]);
        
    if (hp == -2 or hp == 2){
        if (hp * htmp <= 0)
            turn_side(&(*p)->p_child[dir], !dir);

        turn_side(p, dir);

        return false;
    }
    return true;
}

template<class K, class D>
void AVL<K,D>::printARBOL(int p){
    string num_arch = to_string(num);
	string ext1 = ".dot";
	string num_xt1=""+ num_arch +""+ ext1 +"";
	ofstream es(num_xt1);
	////////
	string s = to_string(num);
	string pt1="dot.lnk -Tpng  < ";
	string pt2=" > ";
	string pt3=".png";
	string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
	const char *buffer = rt.c_str();
	////////
	es<<"graph {"<<endl;
	es<<p_root->key<<endl;
	printARBOL(es,p_root);
	es<<"}"<<endl;
	es.close();
	system(buffer);
}



template<class K, class D>
void AVL<K,D>::printARBOL(ofstream & os, node<K,D> *p){
    if(p!=NULL)
    {    
        if(p->p_child[0]!=NULL){
            os<<p->key;
            os<<"--";
            os<<p->p_child[0]->key<<endl;
            printOficial(os,p->p_child[0]);
        }
        if(p->p_child[1]!=NULL){
            os<<p->key;
            os<<"--";
            os<<p->p_child[1]->key<<endl;
            printOficial(os,p->p_child[1]);
        }
    }
}