#ifndef AVL_H
#define AVL_H

#include <cstdlib>
#include <cstdio>  
#include <malloc.h>
#include <fstream>
using namespace std;

template <class K,class D>
class AVL;

template<class K, class D>
class Node{
private: 
	D dato;
	K key;
	int h;
	Node<K,D>* p_child[2];
public:
	Node(const K k, const D d, Node<K,D>* children=NULL);
	virtual ~Node(){};

friend class AVL<K,D>;
};

template<class K, class D>
class AVL{
private:
	Node<K,D> *p_root;
public:
	AVL():p_root(NULL){};
	virtual ~AVL(){};

	void insert(const K &key, const D &dato);
	void find(K key);
	int getMinValue(Node<K,D>* p);
	void remove(K key);
	int max(int a, int b);
	Node<K,D>* Min(Node<K,D> **n);
	int height(Node<K,D>* n);
	void turn_side(Node<K,D>** n, bool dir);
	void doble_turn_side(Node<K,D>** n, bool dir);
	int get_balance(Node<K,D>* root);
	void recalc(Node<K,D>* p);
	bool balanceo(Node<K,D>** n, bool dir);
	void printARBOL();

private:
	
	bool insert(Node<K,D>** n, const K &key, const D &dato);
	bool find(K key, Node<K,D> **&aux);
	bool remove(Node<K,D>** p, K key);
	void printARBOL(ofstream & os, Node<K,D> *p);

};

#include "AVL.inl"
#endif