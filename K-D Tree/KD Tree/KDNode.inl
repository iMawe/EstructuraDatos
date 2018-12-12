KDNode::KDNode() {
    x = 0;
    y = 0;
    beenHere = false;
    child[0] = NULL;
    child[1] = NULL;
    parent = NULL;
    //bisParent = NULL;
}
 
KDNode::KDNode(float _x, float _y){
    x = _x;
    y = _y;
    beenHere = false;
    child[0] = NULL;
    child[1] = NULL;
    parent = NULL;
    //bisParent = NULL;
}
 
KDNode::KDNode(const KDNode& orig) {
    x = orig.x;
    y = orig.y;
    child[0] = orig.child[0];
    child[1] = orig.child[1];
    parent = orig.parent;
    //bisParent = orig.bisParent;
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
    if(this->level){//1
        if(this->x > newNode->x){//child[0]
            if(child[0] != NULL) child[0]->insertNode(newNode, root);
            else{
                newNode->setLevel(!(this->getLevel()));//diferente nivel -> 0
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
            if(this->y == newNode->y) return;//ya existe
            else{
                if(child[1] != NULL) child[1]->insertNode(newNode, root);//si tiene child[1] insertamos debajo de ese
                else{
                    newNode->setLevel(!(this->getLevel()));
                    newNode->setParent(this);
                    this->setChd1(newNode);
                    return;
                }
            }
        }            
    }
     
    else if(!(this->level)){//0
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
        if(this->x > nwno->x){//buscamos en child[0]
            if(child[0] != NULL) child[0]->removeNode(nwno, root);
            return;
        }
        else if(this->x < nwno->x){//buscamos en child[1]
            if(child[1] != NULL) child[1]->removeNode(nwno, root);
            return;            
        }
        else{
            if(this->y == nwno->y){
                if(this->child[0] == NULL && this->child[1] == NULL){//no tiene hijos
                    if(this->parent->child[0]->x == this->x && this->parent->child[0]->y == this->y){//
                        this->parent->setChd0(NULL);//child[0] se cambia a nulo
                        delete this;//eliminamos child[0]
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
                    this->balance(this, root);//en caso de desconectar el arbol              
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
    vector<KDNode> path;
    follow(nwno);//empezamos en la raiz del vector
    KDNode aux;
    KDNode *pequeAnt = &aux;//punto anterior mas pequeño = NULL
    KDNode *pequeNode = closesPath(nwno, this);//buscamos el nodo pequeño mas cercano, llamandolo ocn la raiz
     
    while(!(pequeAnt->getX() == pequeNode->getX() && pequeAnt->getY() == pequeNode->getY())){ //visitado antes?, mientras que no sean iguales
        pequeAnt = pequeNode;
        bool checkedChd0 = false;
        bool checkedChd1 = false;
         
        if(pequeNode->getChd0() != NULL && pequeNode->child[0]->beenHere){//si pqNode tiene child[0] y si estuvo aqui
            checkedChd0 = true;
        }
        else if(pequeNode->getChd1() != NULL && pequeNode->child[1]->beenHere){
            checkedChd1 = true;
        }
        this->clearPoint();//limpia la marca

        if(checkedChd0){//si es true
            pequeNode->setBeenHere(true); //marcamos el mas cercano
            if(pequeNode->getChd1() != NULL) (pequeNode->getChd1())->follow(nwno);//si tiene child[1] buscamos el camino para nwno, intercala por la correspondencia de niveles
        }
        else if(checkedChd1){
            pequeNode->setBeenHere(true);
            if(pequeNode->getChd0() != NULL) (pequeNode->getChd0())->follow(nwno);
        }else{
            pequeNode->setBeenHere(true);
            pequeNode->follow(nwno);//buscamos el camino para nwno
        }
        pequeNode = closesPath(nwno, pequeNode);//buscamos el nodo mas cercano
    }         
    return pequeNode;
}
 
KDNode* KDNode::closesPath(KDNode* nwno, KDNode* root){
    double distanceHolder = 100000000;
    KDNode* nodeHolder;
    KDNode* aux = root;

    nodeHolder = aux;//si solo tenemos un nodo, si hay mas no pasa nada
    bool noAvailableNode = false;
     
    while(!noAvailableNode){//mientras no alcancemos una hoja
        double tempDistance = distanciaEntreDosPuntos(nwno, aux);//hallamos la distancia entre ambos puntos
         
        if(tempDistance < distanceHolder){
            distanceHolder = tempDistance;//copiamos la nueva distancia
            nodeHolder = aux;//copiamos el nodo auxiliar
        }
         
        bool nextNodeIsChd0 = false;
        bool nextNodeIsChd1 = false;

        if(aux->child[0] != NULL){//tiene child[0]
            if(aux->child[0]->beenHere == true){//verifica si estuvo aqui
                nextNodeIsChd0 = true;
                noAvailableNode = false;
                aux = aux->child[0];
            }else{
                noAvailableNode = true;//llegamos a la hoja
            }
        }
        if(aux->child[1] != NULL && !nextNodeIsChd0){//verifica que tenga child[1] y si el siguiente nodo es child[0]
            if(aux->child[1]->beenHere == true){
                nextNodeIsChd1 = true;
                noAvailableNode = false;
                aux = aux->child[1];
            }else{
                noAvailableNode = true;
            }
        }
        if(aux->child[0] == NULL && aux->child[1] == NULL && !nextNodeIsChd0 && !nextNodeIsChd1) noAvailableNode = true;//estamos en la hoja
    }
     
    return nodeHolder;
     
}
 
void KDNode::follow(KDNode *nwno){
    this->setBeenHere(true); 
     
    if(this->level){//1
        if(this->x > nwno->getX()){           
            if(child[0] != NULL) child[0]->follow(nwno);//tiene child[0] llamamos denuevo
        }
        else if(this->x < nwno->getX()){
            if(child[1] != NULL) child[1]->follow(nwno);
        }
        else{
            if(this->y == nwno->getY()){ //No revisa el resto del arbol
            }
            else{
                if(child[1] != NULL) child[1]->follow(nwno);//y diferentes, entonces buscar el camino denuevo con child[1]
            }
        }      
    }
    else{//2
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

    if(this->parent != NULL) cout<<"("<<this->x<<","<<this->y<<")-->level: "<<level<<"-->parent: ("<<this->getParent()->x<<","<<this->getParent()->y<<")"<<endl;
   
    else cout<<"("<<this->x<<","<<this->y<<")-->level: "<<level<<"--> ROOT"<<endl;
    if(child[1] != NULL) child[1]->printNodes();    
}

void KDNode::printPNodes(){
    if(child[0] != NULL) child[0]->printPNodes();
    
    if(this->parent != NULL){
    	if(this->level == 1){
    		
		    	if(this->x < this->parent->x){
		    		moveto(this->x * 12 + 10, 610 - (this->parent->y * 12));
		    		lineto(this->x * 12 + 10, 610);
		    	};
		    	
		    	if(this->x >= this->parent->x){
		    		moveto((this->x * 12) + 10, 610 - (this->parent->y * 12));
		    		lineto((this->x * 12) + 10, 10);
		    	};
		    	
		};
		
		if(this->level == 0){
			if(this->y < this->parent->y){
	    		moveto(this->parent->x * 12 + 10, 610 - (this->y * 12));
	    		lineto(10, 610 - (this->y * 12));
	    	};
	    	
	    	if(this->y >= this->parent->y){
	    		moveto((this->parent->x * 12) + 10, 610 - (this->y * 12));
	    		lineto(610,  610 - (this->y * 12));
	    	};
		}
	};
    if(this->parent == NULL){
        moveto(this->x * 12 + 10, 10);
        lineto(this->x * 12 + 10, 610);
    };
    
    if(child[1] != NULL) child[1]->printPNodes(); 
}
 
void KDNode::clearPoint(){
    if(child[0] != NULL) child[0]->clearPoint();//limpiamos child[0]
    if(this->beenHere) this->setBeenHere(false);//si estuvo aqui --> false
    if(child[1] != NULL) child[1]->clearPoint();
}
 
void KDNode::balance(KDNode* nwno, KDNode* root){
    if(this == NULL) return;
    if(this->child[0] != NULL) child[0]->balance(nwno, root);//con child[0] hasta que sea hoja o no tenga conexion
    if(this->child[1] != NULL) child[1]->balance(nwno, root);
    if(!(this->x == nwno->x && this->y == nwno->y)){//si son diferentes
        this->setBeenHere(false);
        this->setChd0(NULL);
        this->setChd1(NULL);
        this->setParent(NULL);
        root->insertNode(this, root);//creamos la conexion
    }
    else{
        this->setChd1(NULL);
        this->setChd0(NULL);
        this->setParent(NULL);
        delete this;//eliminamos el desconectado
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

