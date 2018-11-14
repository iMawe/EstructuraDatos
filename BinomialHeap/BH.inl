template <typename T>
BN<T>::BN(T d, BN<T> * p){
	dato = d;
	parent = p;
	bro = child = nullptr;
	order=  0;
}
template <typename T>
BN<T>::~BN(){
	delete child;
	delete bro;
}

template<typename T>
int BN<T>::size(int & i){
	++i;
	if(bro)
		bro->size(i);
	if(child)
		child->size(i);

	return i;
}


template <typename T>
void BN<T>::addChild(BN<T>* childNode){
	if(childNode){
		childNode->bro = nullptr;
		if(child){
			BN<T>* temp = child;
			while(temp->bro){
				temp = temp->bro;
			}
			temp->bro = childNode;
		}
		else{
			child = childNode;
		}
		++order;
		childNode->parent = this;
	}
}

template <typename T>
BN<T>* BN<T>::find(T d){
	BN<T>* found = nullptr;
	if(d == dato) return this;
	else if(bro){
		found =  bro->find(d);
	}
	if( dato < d && ! found) if(child) found =  child->find(d);
	return found;
}

template <typename T>
void BN<T>::addTo(BH<T> * other){
	other->insert(dato);
	if(bro) bro->addTo(other);
	if(child) child->addTo(other);	
}

template <typename T>
BH<T>::BH(){
	head = 0;
}

template <typename T>
BH<T>::BH(const BH& other){
	*this = other;
}

template <typename T>
BH<T>::BH(BH&& other){
	head=0;
	if(other.head) other.head->addTo(this);
	other.clear();
}

template <typename T>
BH<T>& BH<T>::operator=(const BH& other){
	head=0;
	if(other.head) other.head->addTo(this);
}

template <typename T>
BH<T>::~BH(){
	clear();
}

template <typename T>
void BH<T>::clear(){
	delete head;
	head = nullptr;
}

template <typename T>
bool BH<T>::isEmpty(){
	return (head==0);
}


template <typename T>
void BH<T>::insert(T d){
	BN<T> *p = head?  head->parent:  nullptr;
	BN<T> *singleton = new BN<T>(d, p);
	head = unionH(singleton, head);
}

template <typename T>
T BH<T>::getMin(){
	T min;
	if(head){
		BN<T> * temp = head;
		min = head->dato;
		while(temp){
			if(temp->dato < min) min = temp->dato;
			temp = temp->bro;
		}
	}
	return min;
}

template <typename T>
T BH<T>::extractMin(){
	BN<T> *prev=nullptr, *min=nullptr, *temp=nullptr, *next=nullptr;
	T minValue;
	if(head){
		BN<T>* minPrev = nullptr;
		min = head;
		temp = head->bro;
		prev= head;

		while(temp){
			if(temp->dato < min->dato){
				min = temp;
				minPrev= prev;
			}
			prev= prev->bro;
			temp = temp->bro;
		}
		if(minPrev) minPrev->bro=min->bro;
		
		else head = min->bro;
	
		next = min->child;
		temp = next;

		while(temp){
			temp->parent = min->parent;
			temp = temp->bro;
		}
		min->bro = nullptr;
		min->child = nullptr;
		min->parent = nullptr;
		minValue=  min->dato;
		delete min;
		head = unionH(head, next);
		temp = min = minPrev = next= nullptr;
	}
	return minValue;
}

template <typename T>
int BH<T>::size(){
	int i = 0;
	if(head) head->size(i);
	return i;
}

template <typename T>
void BH<T>::deleteKey(T d){
	decreaseKey(d, getMin()-1);
	extractMin();
}

template <typename T>
void BH<T>::decreaseKey(T d, T newD){
	if(head){
		if(d > newD){
			BN<T> *current = head->find(d), *parent = nullptr;
			T temp;
			if(current){
				current->dato = newD;
				parent = current->parent;

				while(current && parent && (current->dato < parent->dato)){
					temp = current->dato;
					current->dato = parent->dato;
					parent->dato  = temp;
					current = parent;
					parent = current->parent;
				}
			}
		}
	}
}

template <typename T>
BN<T>* BH<T>::findKey(T d){
	if(head) return head->find(d);
	return nullptr;
}

template <typename T>
int BH<T>::order(BN<T>* heap){
	if(!heap) return -1;
	int i = 0;
	BN<T>* child = heap->child;
	while(child){
		++i;
		child = child->bro;
	}
	return i;
}


template <typename T>
BN<T>* BH<T>::unionH(BN<T>* heapA, BN<T>* heapB){
	BN<T>* heapU  = merge(heapA, heapB);
	if(heapU){
		BN<T> *curr = heapU, *prev = nullptr, *next = nullptr;
		int orderA, orderB;
		while(curr && curr->bro){
			next = curr->bro;
			orderA = curr->order;
			orderB = next->order;
			if(orderA == orderB && orderA != order(next->bro)){
				if(curr->dato < next->dato){
					curr->bro = next->bro;
					curr->addChild(next);
					prev = curr;
					curr = curr->bro;
				}
				else{
					if(prev)
						prev->bro = next;
					else
						heapU = next;
					next->addChild(curr);
					prev = next;
					curr = next->bro;
				}
			}
			else{
				if(!prev) heapU = curr;
				prev = curr;
				curr = next;
			}
		}
	}
	return heapU;
}


template <typename T>
BN<T>* BH<T>::merge(BN<T>* heapA, BN<T>* heapB){
	BN<T>* heapM = nullptr;
	if(heapA || heapB){
		if(heapA && !heapB){
			heapM = heapA;
		}
		else if(!heapA && heapB){
			heapM = heapB;
		}
		else{
			BN<T>*temp = nullptr, *next = nullptr, *prev = nullptr,*curr = nullptr;
			
			if(heapA->order > heapB->order){
				heapM = heapB;
				next = heapA;

			}else{
				heapM = heapA;
				next = heapB;
			}
			curr = heapM;

			while(curr && next && curr != next){
				if(curr->order <= next->order){
					if(curr->bro){
						temp = curr->bro;
						curr->bro = next;
						prev = curr;
						curr = next;
						next = temp;
					}
					else{
						curr->bro = next;
						curr = next;
					}
				}
				else{
					if(prev) prev->bro = next;
					else heapM = next;

					temp = next->bro;
					next->bro = curr;
					prev = next;
					next= temp;

				}
			}
		}
	}
	return heapM;
}