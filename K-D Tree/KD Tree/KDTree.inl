#include "KDTree.h"

class KDTree;
 
KDTree::KDTree() {
    root = NULL;
}
 
KDTree::KDTree(const KDTree& orig) {
}
 
KDTree::~KDTree() {
    if(root != NULL){
        delete root;
    }
    root = NULL;
}
 
KDNode* KDTree::getRoot(){
    return root;
}
 

