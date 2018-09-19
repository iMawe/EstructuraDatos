#ifndef BST_H
#define BST_H

using namespace std;

template <class K,class D>
class BST;

template<class K, class D>
class Node{
private: 
	D dato;
	K key;
	Node<K,D>* p_child[2];
public:
	Node(const K k, const D d, Node<K,D>* children=NULL);
	virtual ~Node();

friend class BST<K,D>;
};

template<class K, class D>
class BST{
private:
	Node<K,D> *p_root;
public:
	BST():p_root(NULL){};
	virtual ~BST();
	bool find(const K & key, D & dato);
	bool insert(const K & key, const D & dato);
	void remove(K & key);
	bool removeP(const K & key);
	void print();
private:
	bool find(const K & key, Node<K,D>** &n);
	void remove(Node<K,D>** n, K key);
	void print(Node<K,D> *n);
};

#include "BST.inl"
#endif