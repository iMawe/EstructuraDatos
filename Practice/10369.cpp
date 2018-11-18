#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int set[100];

struct coor 
{
	int x, y;
	double peso;
};

struct arista
{
	int a, b;
};

vector <arista> graf;
vector <coor> arista;

int find(int x)
{
    if (set[x] == x){
        return x;
    }
    return set[x] = find(set[x]);
}

bool join(const coor & ari, vector<float> & tamari)
{
    int a = find(ari.x);
    int b = find(ari.y);
    if (a == b) {
        return false;
    }
    set[a] = b;
    tamari.push_back(ari.peso);
    return true;
}

bool ismin(coor a, coor b){
    return a.peso < b.peso;
}

int main(){
	int n,s,p,x,y;
	cin>>n;
	while(n--){
		cin>>s>>p;
		for(int i=0; i<p; i++){
			cin>>x>>y;
			graf.push_back({x, y});
			set[i] = i;
		}
        for (int i=0; i<p; i++){
            for (int j=i+1; j<p; j++){
                double dist = sqrt(pow(graf[i].a-graf[j].a, 2) + pow(graf[i].b-graf[j].b, 2));
                arista.push_back({i, j, dist});
            }
        }		
  		sort(arista.begin(), arista.end(), ismin);
        vector<float> tamx;
        for (int i=0, nX=0; nX!=p-1; i++){
            if (join(arista[i],tamx)){
            	nX++;
            }
        }
        printf("%.2f\n",tamx[p - s - 1]);
        arista.clear();
        graf.clear();
	}
	return 0;
}