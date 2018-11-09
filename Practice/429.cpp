//iMawe
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <queue>
using namespace std;

#define tam 205
int n;
bool wrds[tam][tam];
string word[tam];
map <string, int> LoL;

bool Comp(string a, string b) {
    if (a.length() != b.length()) return false;
    int dif = 0;
    for (int i=0, sizes = a.length(); i<sizes; i++)
        if (a[i] != b[i]) {
            dif++;
            if (dif > 1) return false;
        }
    return true;
}

void Convert() {
    for (int i=0; i<n; i++) {
        wrds[i][i] = true;
        for (int j=i+1; j<n; j++)
            wrds[i][j] = wrds[j][i] = Comp(word[i], word[j]);
    }
}

int bfs(int s, int f) {
    if (s==f) return 0;
    int lvl[n];
    queue<int> Queue;
    for (int i=0; i<n; i++)
        lvl[i] = 0;
    Queue.push(s);
    lvl[s] = 1;
    while (!Queue.empty()) {
        int u = Queue.front();
        Queue.pop();
        for (int v=0; v<n; v++)
            if (lvl[v]==0 && wrds[u][v]) {
                if (v==f) return lvl[u];
                lvl[v] = lvl[u]+1;
                Queue.push(v);
            }
    }
}

int main() {
    int c;
    string tmp, a, b;
    scanf("%d", &c);
    while (c--) {
        LoL.clear();
        n = 0;
        while (1) {
            cin >> word[n];
            if (word[n] == "*") break;
            LoL[word[n]] = n;
            n++;
        }
        Convert();
        getline(cin, tmp);
        while (getline(cin, tmp)) {
            if (tmp == "") break;
            for (int i=0, sizet=tmp.length(); i<sizet; i++)
                if (tmp[i] == ' ') {
                    a = tmp.substr(0, i);
                    b = tmp.substr(i+1, sizet);
                    break;
                }
            cout << tmp << " " << bfs(LoL[a], LoL[b]) << endl;
        }
        if (c) printf("\n");
    }
}

