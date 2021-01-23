#include <iostream>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iterator>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std; 

const int mx = 300007;
vector<pair<int, int>> g[mx];
int vis[mx];
int64_t ans, mxd = 0;

void dfs (int n, int dist) {
    vis[n] = 1;

    for (auto i : g[n]) {
        if (!vis[i.first]) {
            dfs (i.first, dist + i.second);
        }
    }
    if (dist > mxd) {
        mxd = dist;
        ans = n;
    }
}

void solve () {
    int n, u, v, w;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> w;
        g[u].push_back ({v, w});
        g[v].push_back ({u, w});
    }
    
    mxd = 0;
    memset (vis, 0, sizeof (vis));
    dfs (0, 0);
    mxd = 0;
    memset (vis, 0, sizeof (vis));
    dfs (ans, 0);
    cout << mxd << endl;

    for (int i = 0; i <= n; ++i) 
        g[i].clear ();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);

    int tt = 1, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ <<   ": ";
        solve ();
    }
    return 0;
}