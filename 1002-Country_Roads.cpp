/*
    Find the longest edge of the shortest path from the source node.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#include <queue>
#include <set>

using namespace std;
using vi = vector<int>;

inline void in(int &n) { 
    scanf("%d", &n);
}

void solve() {
    int u, v, w, temp, nodes, edges, src;
    in(nodes); in(edges);
    vector<int> g[nodes];
    vector<vi> cst (nodes, vi(nodes, 1e8));
    vector<int> dis(nodes, 1e9);

    while (edges--) {
        in(u); in(v); in(w);
        g[u].push_back(v);
        g[v].push_back(u);
        cst[u][v] = cst[v][u] = min(cst[u][v], w);
    }
    
    in(src);    
    priority_queue <pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    dis[src] = 0;

    while(!q.empty()) {
        pair<int, int> now = q.top();
        q.pop();
        u = now.second;
        if(dis[u] != now.first) {
            continue;
        }
        for (int i : g[u]) {
            int nax  = max(cst[u][i], dis[u]);
            if(nax < dis[i]) {
                dis[i] = nax;
                q.push({nax, i});
            }
        }
    }

    for (int i = 0; i < nodes; ++i) {
        if(dis[i] == 1e9) {
            printf("Impossible\n");
        }
        else printf("%d\n", dis[i]);
    }
}

int main() 
{
    int t, tc = 0;
    in(t);

    while(tc++ < t) {
        printf("Case %d:\n", tc);
        solve();
    }
    return 0;
}
