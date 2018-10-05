Node(const int & i, const int & j, Node<T> * r_next, Node<T> * c_next){
	posij[0] = i;
	posij[1] = j;
	p_next[0] = r_next;
	p_next[1] = c_next;
}

Sp_Mat(const int & m, const int & n){
	ptr_index[0] = new Node<T> * [m];
	ptr_index[1] = new Node<T> * [n];
	n_rows=m;
	n_cols=n;
}

~Sp_Mat(){}

T& Sp_Mat<T>::operator ()(unsigned int m, unsigned int n){
	Node<T> ** new_row;
	if(!find(new_row, i, j, 0))	
	{
		Node<T> ** new_col;
		find(new_col, j, i, 1);	

		*new_row = *new_col = new Node<T>(i, j, *new_row, *new_col);
	
	}

	return (*new_row)->value;
}

template <class T>
bool Sp_Mat<T>::find(Node<T> **& n, const int & i, const int & p, const bool & b){
	n = &index[b][i];	
	while(*n)
	{
		if((*n)->pos[!b] == i){
			return true;
		}
		if((*n)->pos[!b] > i){ 
			return false;
		}
		n = &(*n)->p_next[b];
	}
	return false;
}



template <class T>
void Sp_Mat<T>::print(const bool & b){
	for (int i = 1; i <= n_rows; i++){
		for (int j = 1; j <= n_cols; j++){
			Node<T> * n = index[b][i];
			printf("(%d %d) ", n->pos[0], n->pos[1]);
			std::cout << n->value << " -> ";
			n = n->p_next[b];
			printf("\n");
		}
	}		
}

//operator <<{}