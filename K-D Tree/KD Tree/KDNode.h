#ifndef KDNODE_H
#define KDNODE_H

#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
 
class KDNode {
    
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
    void removeNode(KDNode* entry, KDNode* root);
    
    
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