#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
vector<int> adj[10007], vis;
int cs = 1;
bool drunk = 1;

void dfs(int v) {
    vis[v] = 1;

    for (int i : adj[v]) {
        if(vis[i] == 1) {
            drunk = 0;
            return;
        }
        else if(vis[i] == 0) {
            dfs(i);
        }
    }
    vis[v] = 2;
}

void solve() {
    int m, no = 1;
    cin >> m;
    string a, b;

    while(m--) {
        cin >> a >> b;
        if(mp[a] == 0)  mp[a] = no++;
        if(mp[b] == 0)  mp[b] = no++;
        adj[mp[a]].push_back(mp[b]);
    }

    vis.resize(no);
    fill(vis.begin(), vis.end(), 0);

    for (int i = 1; i < no; ++i) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }

    if(drunk)   printf("Case %d: Yes\n", cs++);
    else        printf("Case %d: No\n", cs++);

    mp.clear();
    for (int i = 0; i < no; ++i) {
        adj[i].clear();
    }
    drunk = 1;
}

int main() 
{
    int t = 1;
    cin >> t;
    
    while(t--) {
        solve();
    }
    return 0;
}