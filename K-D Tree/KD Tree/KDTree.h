#ifndef KDTree_H
#define KDTree_H

#include "KDNode.h"
#include <cstddef>
 
using namespace std;
 
 
class KDTree {
public:
    KDTree();
    KDTree(const KDTree& orig);
    virtual ~KDTree();
 
    KDNode* getRoot();
    
    void print();
    void insert(KDNode* newEntry);
    void remove(KDNode* entry);
    
    
private:
    KDNode *root;
 
};


#include "KDTree.inl"
#endif