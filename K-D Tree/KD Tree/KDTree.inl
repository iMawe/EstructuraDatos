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
 
void KDTree::insert(KDNode* newEntry){
    if(root == NULL){
        newEntry->setLevel(true);
        newEntry->setParent(NULL);
        root = newEntry;
    }
    else root->insertNode(newEntry, root);
}
 
void KDTree::remove(KDNode* entry){
    if(root == NULL) return;         
    else root->removeNode(entry, root);
}

KDNode* KDTree::findClosestPoint(KDNode* entry){
    if(root == NULL) return NULL;
    else return(root->fClosesNode(entry));
    }
 
void KDTree::print(){
    if(root == NULL) return;
    else root->printNodes();
}

void KDTree::printP(){
    if(root == NULL) return;
    else root->printPNodes();
}

void KDTree::printA(){
	ofstream os("KDTree.dot");
	os<<"digraph {"<<endl;
	os<<"p"<<root<<" "<<"[label=\""<<"["<<root->x<<" "<<","<<" "<<root->y<<"]"<<"\"]"<<endl;
	os<<"p"<<root<<endl;
	printA(root,os);
	os<<"}"<<endl;
	os.close();
	system("dot.lnk -Tpng  < KDTree.dot > KDTree.png");
}

void KDTree::printA(KDNode *r, ofstream & os){
	if(r!=NULL){
		if(r->child[0]!=NULL){
			os<<"p"<<r->child[0]<<" "<<"[label=\""<<"["<<r->child[0]->x<<" "<<","<<" "<<r->child[0]->y<<"]"<<"\"]"<<endl;
			os<<"p"<<r<<"->"<<"p"<<r->child[0]<<endl;
			printA(r->child[0],os);
		}
		if(r->child[1]!=NULL){
			os<<"p"<<r->child[1]<<" "<<"[label=\""<<"["<<r->child[1]->x<<" "<<","<<" "<<r->child[1]->y<<"]"<<"\"]"<<endl;
			os<<"p"<<r<<"->"<<"p"<<r->child[1]<<endl;
			printA(r->child[1],os);
		}
	}
}

