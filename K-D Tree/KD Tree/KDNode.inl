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
 

