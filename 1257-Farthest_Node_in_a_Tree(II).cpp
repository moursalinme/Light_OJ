#include <bits/stdc++.h>
using namespace std; 

vector<pair<int, int>> tree[30005];
vector<int> dist1(30005), dist2(30005); 
bool vis[30005];
int mxd, mx_node = -1;

int dfs (int n, int dist = 0) {
    vis[n] = 1;
    for (auto j : tree[n]) {
        if (!vis[j.first]) {
            dfs (j.first, dist + j.second);
        }
    }
    if (dist > mxd) { 
        mxd = dist;
        mx_node = n;
    }
}

int dfs (int n, int dist, vector<int>& ara) {
    vis[n] = 1;
    for (auto j : tree[n]) {
        if (!vis[j.first]) {
            dfs (j.first, dist + j.second, ara);
        }
    }
    ara[n] = dist;
}

void rset () {
    memset (vis, 0, sizeof (vis));
    mx_node = -1, mxd = 0;
}

void solve () {
    int n, u, v, w;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        tree[u].push_back ({v, w});
        tree[v].push_back ({u, w});
    }

    rset ();
    dfs (0);
    int st = mx_node;
    rset ();
    dfs (st);
    int end = mx_node;

    rset ();
    dfs (st, 0, dist1);
    rset ();
    dfs (end, 0, dist2);

    for (int i = 0; i < n; ++i) {
        cout << max (dist1[i], dist2[i]) << endl;
    }

    for (int i = 0; i <= n; ++i) {
        tree[i].clear ();
        dist1[i] = 0;
        dist2[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);

    int tt = 1, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ <<   ":\n";
        solve ();
    }
    return 0;
}