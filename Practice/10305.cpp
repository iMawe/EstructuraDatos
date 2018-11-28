//iMawe
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

#define Max 104
using namespace std;

vector<int> List[Max];
stack<int> pila;
bool visited[Max];

void init(){
	for (int i=0; i<Max; i++){
		List[i].clear();
	}
}

void dfs(int n){
	if(visited[n]) return;
	visited[n] = true;
	for(int i=0; i<(int)List[n].size(); i++){
		dfs(List[n][i]);
	}
	pila.push(n);
}

int main(){
	int n,m;
	while ((scanf("%d %d", &n, &m) == 2) && (n||m)){
		init();
		for(int i=0; i<m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			List[a].push_back(b);
		}
		memset(visited, false, sizeof(visited));
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				dfs(i);
			}
		}
		while(!pila.empty()){
			if (pila.size() == 1) printf("%d\n", pila.top());
			else printf("%d ", pila.top());
			pila.pop();
		}
	}
	return 0;
}