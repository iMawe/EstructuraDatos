#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;
typedef vector<piii> vii;
priority_queue<pii, vector<pii>, greater<pii>> resultamin;
vector<vii> Vect;

void Dijkstra(int G,int a){
	int aux=0;
	int aux2=0;
	vi dist2(G, INF);
	vi dist(G, INF); 
	dist[a] = 0;
	dist2[a] = 0;                    
  priority_queue< piii, vector<piii>, greater<piii> > Q; 
  Q.push(piii(0,pii(a,0)));
                  
  while (!Q.empty()){                                            
    piii pri = Q.top(); 
    Q.pop();     
    int t1 = pri.first, t2 = pri.second.first;
    if (t1 > dist[t2]) continue;//->
    for (int i = 0; i < (int)Vect[t2].size(); i++) {
      	piii ve = Vect[t2][i];                       
      	if (dist[t2] + ve.second.first < dist[ve.first]) {
        	dist[ve.first] = dist[t2] + ve.second.first;
        	dist2[ve.first] = dist2[t2] + ve.second.second;                 
        	Q.push(piii(dist[ve.first],pii(ve.first,ve.second.first)));
  			} 
  	} 
  }  

  for (int i = 0; i < G; i++){ 
    aux = aux + dist2[i];
    aux2 = aux2 + dist[i];
  }
  resultamin.push(make_pair(aux2, aux));
}

int main(){
  	int G, E, u, ve, x, y;
  	scanf("%d %d", &G, &E);
  	Vect.assign(G, vii()); 
  	for (int i = 0; i < E; i++) {
    	scanf("%d %d %d %d", &u, &ve, &x, &y);
    	Vect[u-1].push_back(piii(ve-1,pii(x,y)));                              
  	}
  	for (int i = 0; i < G; ++i){
  		Dijkstra(G,i);
  	}
  	pair<int, int> topM = resultamin.top(); 

  	cout<<topM.second;
  	return 0;
}