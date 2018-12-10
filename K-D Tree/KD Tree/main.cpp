#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string>
#include <winbgim.h> 

#include "KDTree.h"
#include "KDNode.h"

using namespace std;



DrawnP(){
	setcolor(4);				
	moveto(5, 0);					
	lineto(5, 595);//Y 590
	moveto(0, 595);					
	lineto(600, 595);//X 600
	setcolor(3);
};


int main() {
    
    initwindow(600, 650);
	DrawnP();
    KDTree *KDtree = new KDTree();
    
    //while(c--){
    //	cin>>a>>b;
    	KDNode *node1 = new KDNode(15,20);
//	}
    
    
    /*moveto(300, 0);
    lineto(300, 595);*/
    KDNode *node2 = new KDNode(25,25);
    /*moveto(5, 420);
    lineto(300, 420);*/
    KDNode *node3 = new KDNode(25,35);
    /*moveto(300, 180);
    lineto(600, 180);*/
    KDNode *node4 = new KDNode(24,34);
    KDNode *node5 = new KDNode(27,33);
    KDNode *node6 = new KDNode(5,7);
    KDNode *node7 = new KDNode(10,11);
    KDNode *node8 = new KDNode(15,9);
    
    KDtree->insert(node1);
    KDtree->insert(node2);
    KDtree->insert(node3);
	KDtree->insert(node4);
	KDtree->insert(node5);
	KDtree->insert(node6);
	KDtree->insert(node7);
	KDtree->insert(node8);
    
    
    
    KDtree->print();
    
    while(!kbhit()) delay(1);
    return 0;
}
