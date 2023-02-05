#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define out(...) 
#endif

#define endl '\n'
#define ff first
#define ss second

const int N = 1e5 + 7;
const int LG = 19;
vector<pair<int, int>> g[N];
int depth[N];
int par[LG][N];
int max_dp[LG][N];;
int min_dp[LG][N];


void dfs (int u, int parent) {
    for (auto i : g[u]) {
        if (i.ff != parent) {
            min_dp[0][i.ff] = i.ss;
            max_dp[0][i.ff] = i.ss;
            par[0][i.ff] = u; 
            
            depth[i.ff] = depth[u] + 1;
            dfs(i.ff, u); 
        }
    }
}

pair<int, int> lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    int mn = 1e9, mx = -1e9;
    for(int i = LG - 1; i >= 0; i--) {
        if(depth[v] - (1 << i) >= depth[u]) {
            mn = min (min_dp[i][v], mn);
            mx = max (max_dp[i][v], mx);
            v = par[i][v];
        }
    }
    if(v == u) {
        return {mn, mx};
    }
    for(int i = LG - 1; i >= 0; i--) {
        if(par[i][u] != par[i][v]) {
            mn = min(mn, min_dp[i][u]);
            mn = min(mn, min_dp[i][v]);
            mx = max(mx, max_dp[i][u]);
            mx = max(mx, max_dp[i][v]);
            u = par[i][u];
            v = par[i][v];
        }
    }
    mn = min(mn, min_dp[0][u]);
    mn = min(mn, min_dp[0][v]);
    mx = max(mx, max_dp[0][v]);
    mx = max(mx, max_dp[0][u]);
    return {mn, mx};
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        depth[i] = 0;
        min_dp[0][0] = -1e9;
        max_dp[0][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int p, q, w; cin >> p >> q >> w;
        g[p].push_back({q, w});
        g[q].push_back({p, w});
    }

    par[0][1] = 0;
    depth[1] = 0;
    min_dp[0][1] = 1e7;
    max_dp[0][1] = 0;
    dfs (1, 0);
    for(int i = 1; i < LG; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    for(int i = 1; i < LG; i++) {
        for(int j = 1; j <= n; j++) {
            max_dp[i][j] = max(max_dp[i - 1][j], max_dp[i - 1][par[i - 1][j]]);
            min_dp[i][j] = min(min_dp[i - 1][j], min_dp[i - 1][par[i - 1][j]]);
        }
    }
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        auto x = lca(u, v);
        cout << x.ff << " " << x.ss << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; ++i) { 
        cout << "Case " << i << ":\n";
        solve ();
    }

}