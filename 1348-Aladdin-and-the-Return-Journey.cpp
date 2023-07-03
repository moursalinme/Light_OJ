#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define out(...) 
#endif

#define endl '\n'
#define ff first
#define ss second
using i64 = long long;

const int N = 30000 + 5;
const int LG = 16;

vector<int> g[N];
int st[N * 2], fn[N * 2], val[N], par[N][LG], flat[2 * N], depth[N];
int clk;

void dfs (int u, int p = 0) {
    st[u] = ++clk;
    par[u][0] = p;
    flat[clk] = val[u];
    depth[u] = depth[p] + 1;

    for (int v : g[u]) {
        if (v ^ p) dfs (v, u);
    }
    fn[u] = ++clk;
    flat[clk] = -val[u];
}

int tree[8 * N];

void build (int r, int l = 1, int cur = 1) {
    if (l == r) {
        tree[cur] = flat[l];
        return;
    }
    int m = (r + l) / 2, ci = cur * 2;
    build (m, l, ci);
    build (r, m + 1, ci + 1);
    tree[cur] = tree[ci] + tree[ci + 1]; 
}

void update (int cur, int l, int r, int point, int vx) {
    if (l > point || point > r) return;
    if (l >= point && r <= point) {
        tree[cur] = vx;
        return;
    }
    int m = (r + l) / 2, ci = cur * 2;
    point <= m ? update (ci, l, m, point, vx) : update (ci + 1, m + 1, r, point, vx);
    tree[cur] = tree[ci] + tree[ci + 1]; 
}

void update (int u, int x) {
    update (1, 1, clk, st[u], x);
    update (1, 1, clk, fn[u], -x);
    val[u] = x;
}

int get (int cur, int l, int r, int i, int j) {
    if (r < i || j < l) return 0;
    if (l >= i and r <= j) return tree[cur];
    int m = (r + l) / 2, ci = cur * 2;
    return get (ci, l, m, i, j) + get (ci + 1, m + 1, r, i, j);
}

int LCA (int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int d = depth[v] - depth[u];
    for (int i = LG - 1; i >= 0; --i) {
        if (d & (1 << i)) {
            v = par[v][i];
        }
    }
    if (u == v) return u;
    for (int i = LG - 1; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void printval (int u, int v) {
    int lca = LCA (u, v);
    int x = get (1, 1, clk, st[lca], st[u]);
    int y = get (1, 1, clk, st[lca], st[v]);
    cout << x + y - val[lca] << endl;
}


void solve (int test_no) 
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> val[i];

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v; ++u, ++v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    clk = 0;
    dfs (1);

    for (int j = 1; j < LG; ++j) {
        for (int i = 1; i <= n; ++i) {
            par[i][j] = par[par[i][j-1]][j - 1];
        }
    }

    build (clk);
    int m; cin >> m;
    cout << "Case " << test_no << ":\n";
    
    while (m--) {
        int type, node, to; cin >> type >> node >> to;
        if (type ^ 1)   printval(++node, ++to);
        else            update(++node, to);
    }

    for (int i = 0; i <= n; ++i) {
        g[i].clear();
        for (int j = 0; j < LG; ++j) 
            par[i][j] = 0;
    }
}   

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) { 
        solve (i);
    }
    
    return 0;
}
