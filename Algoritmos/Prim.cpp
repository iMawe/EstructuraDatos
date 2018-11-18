#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector < pair <int, pair <int, int> > > graph, mst;
int N;

int prim(int n) {
    int total = 0;
    
    bool intree[100];
    for( int i=0; i<N; i++ ) {
        intree[i] = false;
    }
    while( !intree[n] ) {
        intree[n] = true;
    
        int w = 99999;
        int min = -1;
        int min_next;
        for( int i=0; i<graph.size(); i++ ){
            if( graph[i].second.first == n || graph[i].second.second == n ){ 
                int next;
                if( graph[i].second.first == n ) next = graph[i].second.second;
                else next = graph[i].second.first;
                
                if( !intree[next] && graph[i].first<w ){
                    w = graph[i].first;
                    min =  i;
                    min_next = next;
                }
            }
        }
        
        if( min != -1 ){
            n = min_next;
            mst.push_back( graph[min] );
            total += graph[min].first;
        }
    }
    
    return total;    
}

int main()
{
    int E;
	cin>>N>>E;
    
    for(int i=0; i<E; i++) {
        char u, v;
        int w;
        cin>>u>>v>>w;       
        graph.push_back( make_pair(w, make_pair(u-'A',v-'A') ) );
    }

    int total = prim(0);
    for( int i=0; i<mst.size(); i++ ) {
        printf("%c %c %d\n", mst[i].second.first+'A', mst[i].second.second+'A', mst[i].first );
    }
    
    cout<<total;

    return 0;
}