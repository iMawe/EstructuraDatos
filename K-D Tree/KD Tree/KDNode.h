#ifndef KDNODE_H
#define KDNODE_H

#include <iostream>
#include <vector>
#include <math.h>
#include <winbgim.h> 

using namespace std;
 
class KDNode{
public:
    KDNode();
    KDNode(float _x, float _y);
    KDNode(const KDNode& orig);
    virtual ~KDNode();
    KDNode& operator=(const KDNode &R);
     
    float getX() const;
    float getY() const;
    bool getLevel() const;
    bool getBeenHere() const;
    KDNode* getChd0() const;
    KDNode* getChd1() const;
    KDNode* getParent() const;
     
    void setX(float _x);
    void setY(float _y);
    void setLevel(bool _lev);
    void setBeenHere(bool _here);
    void setChd0(KDNode* newChd0);
    void setChd1(KDNode* newChd1);
    void setParent(KDNode* newParent);

    void insertNode(KDNode* newNode, KDNode* &root);
    void removeNode(KDNode* nwno, KDNode* root);
    void printNodes();
    KDNode* fClosesNode(KDNode* nwno);
    KDNode* closesPath(KDNode* nwno, KDNode* root);
    void clearPoint();
    void follow(KDNode *nwno);
    void balance(KDNode* nwno, KDNode* root);
    double distanciaEntreDosPuntos(KDNode* a, KDNode* b);
   
private:
    float x;
    float y;
    bool level;
    bool beenHere;  
    KDNode* child[2];
    KDNode* parent;
 
};

#include "KDNode.inl"
#endif
