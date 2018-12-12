#ifndef KDTree_H
#define KDTree_H

#include "KDNode.h"
#include <cstddef>
#include <winbgim.h>
#include <cstdlib>
#include <fstream>
#include <string>
 
using namespace std;
 
 
class KDTree {
public:
    KDTree();
    KDTree(const KDTree& orig);
    virtual ~KDTree();
 
    KDNode* getRoot();
    KDNode* findClosestPoint(KDNode* entry);
    
    void print();
    void remove(KDNode* entry);
    void insert(KDNode* newEntry);
    void printP();
    void printA();
	void printA(KDNode *r, ofstream & os);
    
private:
    KDNode *root;
 
};


#include "KDTree.inl"
#endif

