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
    KDNode* masProximo(KDNode* nwnode);
    
    void print();
    void insert(KDNode* newN);
    void remove(KDNode* nwnode);
    
private:
    KDNode *root;
 
};


#include "KDTree.inl"
#endif
