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

const int mxn = 1000 + 7;
int n, m; 
vector<int> g[mxn];
vector<bool> vis(mxn);
int money[mxn];

pair<int, int> dfs(int u) {
	vis[u] = 1;
	pair<int, int> ret = {1, money[u]};
	for (int i : g[u]) {
		if (!vis[i]) {
			pair<int, int> got = dfs(i);
			ret.ff += got.ff;
			ret.ss += got.ss;
		}
	}
	return ret;
}

void solve () {

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> money[i];
		vis[i] = 0;
		g[i].clear();
	}
	while(m--) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool ok = 1;;
	int avg = -1;

	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			pair<int , int> got = dfs(i);
			if (got.ss % got.ff) {
				ok = 0;
				break;
			}
			if (avg == -1) avg = got.ss / got.ff;
			else if (avg != (got.ss / got.ff)) {
				ok = 0;
				break;
			}
		}
	}
	if (ok) cout << "Yes\n";
	else cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cout << "Case " << i << ": ";
        solve ();
    }

}