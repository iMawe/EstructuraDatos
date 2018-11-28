//iMawe
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

vector<string> modd;
map<string, int> mmp;
vector<int> edge[1001], ans1;
bool visited[1001];
map<int, string> mmp1;


void dfs(int n){
    visited[n] = 1;
    for(int i=0; i<edge[n].size(); i++){
        int v = edge[n][i];
        if(visited[v] == 0) dfs(v);
    }
    ans1.push_back(n);
}
int main(){
    int t = 0;
    int n, m, cnt = 0;
    string s, s1;
    while(scanf("%d",&n) != EOF){
        if(t!=0)printf("\n");
        for(int i=0;i<101;i++) edge[i].clear();
        modd.clear();
        mmp1.clear();
        mmp.clear();
        ans1.clear();
        for(int i=0; i<n; i++){
            cin>>s;
            modd.push_back(s);
            mmp[s]=i+1;
            mmp1[i+1]=s;
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            cin>>s>>s1;
            int aux = mmp[s];
            int aux1 = mmp[s1];
            edge[aux1].push_back(aux);
        }
        memset(visited,0,sizeof visited);
        for(int i=0; i<n; i++){
            if(visited[i+1] == 0){
                cnt = 0;
                dfs(i + 1);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", ++t);
        for(int i=0; i<n; i++) cout<<" "<<mmp1[ans1[i]]; printf(".\n");
    }

    return 0;
}