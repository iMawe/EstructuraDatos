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
 
void KDTree::insert(KDNode* newN){
    if(root == NULL){
        newN->setLevel(true);
        newN->setParent(NULL);
        root = newN;
    }
    else root->insertNode(newN, root);
}
 
void KDTree::remove(KDNode* nwnode){
    if(root == NULL) return;         
    else root->removeNode(nwnode, root);
}

KDNode* KDTree::masProximo(KDNode* nwnode){
    if(root == NULL) return NULL;
    else return(root->fClosesNode(nwnode));
    }
 
void KDTree::print(){
    if(root == NULL) return;
    else root->printNodes();
}
