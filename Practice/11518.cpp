//iMawe
#include <iostream>
#include<string.h>
#include<stdio.h>
#include <vector>
using namespace std;

#define S 10003

vector <int> Dominos[S];
int vis[S], cn;

int dfs(int a){
    if(vis[a])return 0;
    vis[a] = 1;
    cn++;
    int sz = Dominos[a].size();
    for(int z = 0; z < sz; z++){
        int u = Dominos[a][z];
        dfs(u);
    }
    return cn;
}

int main(){
    int t, n, m, l, x, y, z;
    cin >> t;
    while(t--){
        cin >> n >> m >> l;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            Dominos[x].push_back(y);
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < l; i++){
            cn = 0;
            cin >> z;
            dfs(z);
            ans += cn;
        }
        cout << ans << endl;
        for(int i = 0; i <= n; i++)Dominos[i].clear();
    }
    return 0;
}