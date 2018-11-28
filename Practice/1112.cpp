//iMawe
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef pair < int, int > pii;
#define Inf 0x3f3f3f3f
vector <pii> g[101];
int dist[101], T, N;

int dijkstra(int src ){
    priority_queue < pii > Q;
    for(int i = 1; i <= N; i++) dist[i] = Inf;
    Q.push( pii(src, 0));
    dist[src] =0;
    int a, b, t, c;
    while(!Q.empty()){
        a = Q.top().first;
        c = Q.top().second;
        Q.pop();

        if(dist[a] == c && dist[a] <= T)
            for(int i = 0; i < (int) g[a].size(); i++){
                b = g[a][i].first;
                t = g[a][i].second;
                if(dist[a] + t < dist[b]){
                    dist[b] = dist[a] + t;
                    Q.push(pii(b, dist[b]));
                }
            }
    }

    int mices = 0;
    for(int i = 1; i <= N; i++) if(dist[i] <= T) mices += 1;
    return mices;
}
int main(){
    int E, M, n, a, b, t;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &N, &E, &T);
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &a, &b, &t);
            g[b].push_back(pii(a, t));
        }
    printf("%d\n", dijkstra(E));
    if(n)puts("");
    for(int i = 1; i <= N; i++) g[i].clear();
    }

	return 0;
}