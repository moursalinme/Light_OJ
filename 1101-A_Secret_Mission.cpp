/*
    Light OJ 1101 : A Secret Mission 
    Problem Link  : https://lightoj.com/problem/a-secret-mission
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define out(...) 42;
#endif

#define endl '\n'
#define ff first
#define ss second

const int N = 2e5+7;
const int LG = 19;

struct edge {
    int u, v, w;
    bool operator < (edge ed) const {
        return ed.w > w;
    }
};

vector<edge> ed(N);
vector<pair<int, int>> g[N];
int max_dp[LG][N];
int par[LG][N];
int depth[N];
int pare[N];

int find_par(int x) {
    return pare[x] == x ? x : pare[x] = find_par(pare[x]);
}

void dfs (int u, int parent) {
    for (auto v : g[u]) {
        if (v.ff != parent) {
            depth[v.ff] = depth[u] + 1;
            max_dp[0][v.ff] = v.ss;
            par[0][v.ff] = u;
            dfs(v.ff, u);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    } 
    int diff = depth[v] - depth[u];
    int mx_ans = -1e9;
    for (int i = LG - 1; i >= 0; --i) {
        if (diff & (1 << i)) {
            mx_ans = max (mx_ans, max_dp[i][v]);
            v = par[i][v];
        }
    }
    if (u == v) {
        return mx_ans;
    }
    for (int i = LG - 1; i >= 0; --i) {
        if (par[i][v] != par[i][u]) {
            mx_ans = max (mx_ans, max_dp[i][u]);
            mx_ans = max (mx_ans, max_dp[i][v]);
            v = par[i][v];
            u = par[i][u]; 
        }
    }
    mx_ans = max (mx_ans, max_dp[0][u]);
    mx_ans = max (mx_ans, max_dp[0][v]);
    return mx_ans;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m; cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < LG; ++j) {
                max_dp[j][i] = -1e9;
                par[j][i] = 0;
            }
            g[i].clear();
            pare[i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            cin >> ed[i].u >> ed[i].v >> ed[i].w;
        }
        sort (ed.begin() + 1, ed.begin() + m + 1);
        long long mst = 0;
        for (int i = 1; i <= m; ++i) {
            edge cur = ed[i];
            int p = find_par(cur.u);
            int q = find_par(cur.v);
            if (p != q) {
                mst += cur.w;
                pare[p] = q;
                g[cur.u].push_back({cur.v, cur.w});
                g[cur.v].push_back({cur.u, cur.w});
            }
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
                max_dp[i][j] = max (max_dp[i - 1][j], max_dp[i - 1][par[i - 1][j]]);
            }
        }
        int q; cin >> q;
        cout << "Case " << tc << ":\n";
        while (q--) {
            int u, v; cin >> u >> v;
            cout << LCA(u, v) << endl;
        }
    }
}