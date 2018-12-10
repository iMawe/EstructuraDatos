KDNode::KDNode() {
    x = 0;
    y = 0;
    beenHere = false;
    child[0] = NULL;
    child[1] = NULL;
    parent = NULL;
}
 
KDNode::KDNode(float _x, float _y){
    x = _x;
    y = _y;
    beenHere = false;
    child[0] = NULL;
    child[1] = NULL;
    parent = NULL;   
}
 
KDNode::KDNode(const KDNode& orig) {
    x = orig.x;
    y = orig.y;
    child[0] = orig.child[0];
    child[1] = orig.child[1];
    parent = orig.parent;
}
 
KDNode::~KDNode() {
     
    if(child[0] != NULL)
        delete child[0];
    child[0] = NULL;
     
    if(child[1] != NULL)
        delete child[1];
    child[1] = NULL;
     
}
 
KDNode& KDNode::operator =(const KDNode& R){
    x = R.x;
    y = R.y;
    level = R.level;
    beenHere = R.beenHere;
}
 
float KDNode::getX() const{
    return x;
}

float KDNode::getY() const{
    return y;
}

bool KDNode::getLevel() const{
    return level;
}

bool KDNode::getBeenHere() const{
    return beenHere;
}

KDNode* KDNode::getChd0() const{
    return child[0];
}
 
KDNode* KDNode::getChd1() const{
    return child[1];
}
 
KDNode* KDNode::getParent() const{
    return parent;
}
 
void KDNode::setX(float _x){
    x = _x;
}
 
void KDNode::setY(float _y){
    y = _y;
}
 
void KDNode::setLevel(bool _lev){
    level = _lev;
}
 
void KDNode::setBeenHere(bool _here){
    beenHere = _here;
}
 
void KDNode::setChd1(KDNode* newRight){
    child[1] = newRight;
}
 
void KDNode::setChd0(KDNode* newLeft){
    child[0] = newLeft;
}
 
void KDNode::setParent(KDNode* newParent){
    parent = newParent;
}

void KDNode::insertNode(KDNode* newNode, KDNode* &root){
    if(this->level){
        if(this->x > newNode->x){
            if(child[0] != NULL) child[0]->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel()));
                newNode->setParent(this);
                this->setChd0(newNode);
                return;
            }
        }
        else if(this->x < newNode->x){
            
            if(child[1] != NULL)
                child[1]->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel()));
                newNode->setParent(this);
                this->setChd1(newNode);
                return;
            }
        }
        else{
            if(this->y == newNode->y) return;
            else{
                if(child[1] != NULL) child[1]->insertNode(newNode, root);
                else{
                    newNode->setLevel(!(this->getLevel()));
                    newNode->setParent(this);
                    this->setChd1(newNode);
                    return;
                }
            }
        }            
    }
     
    else if(!(this->level)){
        if(this->y > newNode->y){
            if(child[0] != NULL)
                child[0]->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel()));
                newNode->setParent(this);
                this->setChd0(newNode);
                return;
            }
             
        }
        else if(this->y < newNode->y){
            if(child[1] != NULL)
                child[1]->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel()));
                newNode->setParent(this);
                this->setChd1(newNode);
                return;
            }
        }
        else{
            if(this->x == newNode->x) return;
            else{
                if(child[1] != NULL)
                    child[1]->insertNode(newNode, root);
                else{
                    newNode->setLevel(!(this->getLevel()));
                    newNode->setParent(this);
                    this->setChd1(newNode);
                    return;
                }
            }
        }
    }
}
 
void KDNode::removeNode(KDNode* nwno, KDNode* root){
    if(this->level){
        if(this->x > nwno->x){
            if(child[0] != NULL) child[0]->removeNode(nwno, root);
            return;
        }
        else if(this->x < nwno->x){
            if(child[1] != NULL) child[1]->removeNode(nwno, root);
            return;            
        }
        else{
            if(this->y == nwno->y){
                if(this->child[0] == NULL && this->child[1] == NULL){
                    if(this->parent->child[0]->x == this->x && this->parent->child[0]->y == this->y){
                        this->parent->setChd0(NULL);
                        delete this;
                    }
                    else{
                        this->parent->setChd1(NULL);
                        delete this;
                    }
                }
                else{
                    if(this->parent == NULL){
                        //new root is the child[1] node
                        //root = root->findNewRoot(root);
                        //this->balance(this, root);
                        //delete this;
                         
                    }
                    else{
                        if(this->parent->child[0]->x == this->x && this->parent->child[0]->y == this->y) this->parent->setChd0(NULL);
                        else this->parent->setChd1(NULL);
                    }                    
                    this->balance(this, root);                    
                }
            }
            else{
                if(child[1] != NULL) child[1]->removeNode(nwno, root);
                return;
            }
        }
    }
    else if(!(this->level)){
        if(this->y > nwno->y){
            if(child[0] != NULL) child[0]->removeNode(nwno, root);
            
            return;
        }
        else if(this->y < nwno->y){
            if(child[1] != NULL) child[1]->removeNode(nwno, root);
            return;
        }
        else{
            if(this->x == nwno->x){
                if(this->child[0] == NULL && this->child[1] == NULL){
                    if(this->parent->child[0]->x == this->x && this->parent->child[0]->y == this->y){
                        this->parent->setChd0(NULL);
                        delete this;
                    }
                    else{
                        this->parent->setChd1(NULL);
                        delete this;
                    }
                }
                else{
                    if(this->parent == NULL){
                        //new root is the child[1] node
                        //root = root->findNewRoot(root);
                        //this->balance(this, root);
                        //delete this;
                    }
                    else{
                        if(this->parent->child[0]->x == this->x && this->parent->child[0]->y == this->y) this->parent->setChd0(NULL);
                        else this->parent->setChd1(NULL); 
                    }                    
                    this->balance(this, root);                    
                }
            }
            else{
                if(child[1] != NULL){
                    child[1]->removeNode(nwno, root);
                }
                return;                
            }
        }
    }
}
 
KDNode* KDNode::fClosesNode(KDNode* nwno){
    vector<KDNode>path;
    follow(nwno);
    KDNode aux;
    KDNode *pequeAnt = &aux;
    KDNode *pequeNode = closesPath(nwno, this);
     
    while(!(pequeAnt->getX() == pequeNode->getX() && pequeAnt->getY() == pequeNode->getY())){ //visited before?   
        pequeAnt = pequeNode;
        bool checkedLeft = false;
        bool checkedRight = false;
         
        if(pequeNode->getChd0()!=NULL && pequeNode->child[0]->beenHere){
            checkedLeft = true;
        }
        else if(pequeNode->getChd1()!=NULL && pequeNode->child[1]->beenHere){
            checkedRight = true;
        }
        this->clearPoint();

        if(checkedLeft){
            pequeNode->setBeenHere(true);
            if(pequeNode->getChd1() != NULL) (pequeNode->getChd1())->follow(nwno);
        }
        else if(checkedRight){
            pequeNode->setBeenHere(true);
            if(pequeNode->getChd0() != NULL) (pequeNode->getChd0())->follow(nwno);
        }else{
            pequeNode->setBeenHere(true);
            pequeNode->follow(nwno);
        }
        pequeNode = closesPath(nwno, pequeNode);         
    }         
    return pequeNode;    
}
 
KDNode* KDNode::closesPath(KDNode* nwno, KDNode* root){
    double distanceHolder = 100000000;
    KDNode* nodeHolder;
    KDNode* current = root;
    nodeHolder = current;
    bool noAvailableNode = false;
     
    while(!noAvailableNode){
        double tempDistance = distanciaEntreDosPuntos(nwno, current);
         
        if(tempDistance < distanceHolder){
            distanceHolder = tempDistance;
            nodeHolder = current;
        }
         
        bool nextNodeIsLeft = false;
        bool nextNodeIsRight = false;

        if(current->child[0] != NULL){
            if(current->child[0]->beenHere == true){
                nextNodeIsLeft = true;
                noAvailableNode = false;
                current = current->child[0];
            }else{
                noAvailableNode = true;
            }
        }
        if(current->child[1] != NULL && !nextNodeIsLeft){
            if(current->child[1]->beenHere == true){
                nextNodeIsRight = true;
                noAvailableNode = false;
                current = current->child[1];
            }else{
                noAvailableNode = true;
            }
        }
        if(current->child[0] == NULL && current->child[1] == NULL && !nextNodeIsLeft && !nextNodeIsRight) noAvailableNode = true;  
    }
     
    return nodeHolder;
     
}
 
void KDNode::follow(KDNode *nwno){
    this->setBeenHere(true); 
     
    if(this->level){
        if(this->x > nwno->getX()){           
            if(child[0] != NULL) child[0]->follow(nwno);
        }
        else if(this->x < nwno->getX()){
            if(child[1] != NULL) child[1]->follow(nwno);
        }
        else{
            if(this->y == nwno->getY()){ //No revisa el resto del arbol
            }
            else{
                if(child[1] != NULL) child[1]->follow(nwno);
            }
        }      
    }
    else{
        if(this->y > nwno->getY()){
            if(child[0] != NULL) child[0]->follow(nwno);
        }        
        else if(this->y < nwno->getY()){
            if(child[1] != NULL) child[1]->follow(nwno);
        }
        else{
            if(this->x == nwno->getX()){ //No revisa el resto del arbol
            }
            else{
                if(child[1] != NULL) child[1]->follow(nwno);
            }
        }
    }
} 
 
void KDNode::printNodes(){
    if(child[0] != NULL) child[0]->printNodes();

    if(this->parent != NULL) cout<<"("<<this->x<<","<<this->y<<")==>level: "<<level<<"==>parent: ("<<this->getParent()->x<<","<<this->getParent()->y<<")"<<endl;
   
    else cout<<"("<<this->x<<","<<this->y<<")==>level: "<<level<<"==>parent: ROOT"<<endl;
    if(child[1] != NULL) child[1]->printNodes();    
}
 
void KDNode::clearPoint(){
    if(child[0] != NULL) child[0]->clearPoint();
    if(this->beenHere) this->setBeenHere(false);
    if(child[1] != NULL) child[1]->clearPoint();  
}
 
void KDNode::balance(KDNode* nwno, KDNode* root){
    if(this == NULL) return;
    if(this->child[0] != NULL) child[0]->balance(nwno, root);
    if(this->child[1] != NULL) child[1]->balance(nwno, root);
    if(!(this->x == nwno->x && this->y == nwno->y)){
        this->setBeenHere(false);
        this->setChd0(NULL);
        this->setChd1(NULL);
        this->setParent(NULL);
        root->insertNode(this, root);
    }
    else{
        this->setChd1(NULL);
        this->setChd0(NULL);
        this->setParent(NULL);
        delete this;
    }
}

double KDNode::distanciaEntreDosPuntos(KDNode* a, KDNode* b){
    float x1 = a->getX();
    float y1 = a->getY();
    float x2 = b->getX();
    float y2 = b->getY();
            
    double dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    
    return dist;
}
