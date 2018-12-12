#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string>
#include <winbgim.h>
#include <fstream>

#include "KDTree.h"
#include "KDNode.h"

using namespace std;



DrawnP(){
	setcolor(4);				
	
	moveto(10, 610);					
	lineto(610, 610);
	moveto(10, 10);					
	lineto(10, 610);
	setcolor(3);
};


int main() {
    
    initwindow(650, 650);
	DrawnP();
    KDTree *KDtree = new KDTree();
    
   	//cout<<"ahello";
	KDNode *node1 = new KDNode(15,20);
	KDNode *node9 = new KDNode(14,20);
    /*moveto(300, 0);
    lineto(300, 595);*/
    KDNode *node2 = new KDNode(25,25);
    /*moveto(5, 420);
    lineto(300, 420);*/
    KDNode *node3 = new KDNode(26,35);
    /*moveto(300, 180);
    lineto(600, 180);*/
    KDNode *node4 = new KDNode(24,34);
    KDNode *node5 = new KDNode(27,33);
    KDNode *node6 = new KDNode(5,7);
    KDNode *node7 = new KDNode(10,11);
    KDNode *node8 = new KDNode(17,9);
    
    KDtree->insert(node1);
    
    KDtree->insert(node6);
    KDtree->insert(node2);
	KDtree->insert(node7);
	KDtree->insert(node8);
	KDtree->insert(node3);
	
	KDtree->insert(node9);/*
	KDtree->insert(node4);
	KDtree->insert(node9);*/
    
    
    
    KDtree->print();
    KDtree->printP();
    
    KDtree->printA();

    
    while(!kbhit()) delay(1);
    return 0;
}


