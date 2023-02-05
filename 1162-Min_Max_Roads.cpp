#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second

const int N = 1e5+7;
const int LG = 18;
vector<pair<int, int>> g[N];
int min_dp[LG][N];
int max_dp[LG][N];
int par[LG][N];
int depth[N];

void dfs (int u, int parent) {
    for (auto v : g[u]) {
        if (v.ff != parent) {
            depth[v.ff] = depth[u] + 1;
            min_dp[0][v.ff] = v.ss;
            max_dp[0][v.ff] = v.ss;
            par[0][v.ff] = u;
            dfs(v.ff, u);
        }
    }
}

void LCA(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    } 
    int diff = depth[v] - depth[u];
    int mn_ans = 1e9, mx_ans = -1e9;
    for (int i = LG - 1; i >= 0; --i) {
        if (diff & (1 << i)) {
            mn_ans = min (mn_ans, min_dp[i][v]);
            mx_ans = max (mx_ans, max_dp[i][v]);
            v = par[i][v];
        }
    }
    if (u == v) {
        cout << mn_ans << " " << mx_ans << endl;
        return;
    }
    for (int i = LG - 1; i >= 0; --i) {
        if (par[i][v] != par[i][u]) {
            mn_ans = min (mn_ans, min_dp[i][u]);
            mn_ans = min (mn_ans, min_dp[i][v]);
            mx_ans = max (mx_ans, max_dp[i][u]);
            mx_ans = max (mx_ans, max_dp[i][v]);

            v = par[i][v];
            u = par[i][u]; 
        }
    }
    mn_ans = min (mn_ans, min_dp[0][u]);
    mn_ans = min (mn_ans, min_dp[0][v]);
    mx_ans = max (mx_ans, max_dp[0][u]);
    mx_ans = max (mx_ans, max_dp[0][v]);
    cout << mn_ans << " " << mx_ans << endl;
}

signed main () {
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n; cin >> n;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < LG; ++j) {
                min_dp[j][i] = 1e9;
                max_dp[j][i] = -1e9;
                par[j][i] = 0;
            }
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        depth[1] = 0;
        dfs(1, 0);
        for (int i = 1; i < LG; ++i) {
            for (int j = 1; j <= n; ++j) {
                par[i][j] = par[i - 1][par[i - 1][j]];
            }
        }
        for (int i = 1; i < LG; ++i) {
            for (int j = 1; j <= n; ++j) {
                min_dp[i][j] = min (min_dp[i - 1][j], min_dp[i - 1][par[i - 1][j]]);
                max_dp[i][j] = max (max_dp[i - 1][j], max_dp[i - 1][par[i - 1][j]]);
            }
        }
        cout << "Case " << tc << ":\n"; 
        int q; cin >> q;
        while (q--) {
            int u, v; cin >> u >> v;
            LCA(u, v);
        }
    }
}