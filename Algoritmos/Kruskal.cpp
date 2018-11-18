#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector < pair <int, pair <int, int> > > graph, mst;
int N;

int root(int n, int *parent){
    while( n != parent[n] ){
        n = parent[n];
    }
    return n;
}

int kruskal() {
    int total = 0;    
    int parent[100];
    
    for( int i=0; i<N; i++ ){
        parent[i] = i;
    }
    sort( graph.begin(), graph.end() );
   
    for( int i=0; i<graph.size(); i++ ){
        int ru = root( graph[i].second.first, parent );
        int rv = root( graph[i].second.second, parent );
        if( ru != rv ) {
            mst.push_back( graph[i] );
            parent[ru] = parent[rv];
            total += graph[i].first;
        }        
    }   
    return total;
}


int main()
{
	int E;
	cin>>N>>E;
    
    for(int i=0; i<E; i++){
        char u, v;
        int w;
        cin>>u>>v>>w;        
        graph.push_back( make_pair(w, make_pair(u-'A',v-'A') ) );
    }
    int total = kruskal();
    for( int i=0; i<mst.size(); i++ ){
        printf("%c %c %d\n", mst[i].second.first+'A', mst[i].second.second+'A', mst[i].first );
    }
    cout<<total;
    return 0;
}