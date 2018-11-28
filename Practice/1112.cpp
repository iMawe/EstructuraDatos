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
    int from, to, t, cost;
    while(!Q.empty()){
        from = Q.top().first;
        cost = Q.top().second;
        Q.pop();

        if(dist[from] == cost && dist[from] <= T)
            for(int i = 0; i < (int) g[from].size(); i++){
                to = g[from][i].first;
                t = g[from][i].second;
                if(dist[from] + t < dist[to]){
                    dist[to] = dist[from] + t;
                    Q.push(pii(to, dist[to]));
                }
            }
    }

    int mices = 0;
    for(int i = 1; i <= N; i++) if(dist[i] <= T) mices += 1;
    return mices;
}
int main(){
    int E, M;
    int test, from, to, t;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d %d", &N, &E, &T);
        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &from, &to, &t);
            g[to].push_back(pii(from, t));
        }
    printf("%d\n", dijkstra(E));
    if(test)puts("");
    for(int i = 1; i <= N; i++) g[i].clear();
    }

	return 0;
}