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

const int mxn = 502;
char G[mxn][mxn];
int n, m, q;
int cnt[mxn][mxn];
const int vag = mxn * mxn;
int collect[vag];
int idx_now = 0;
int cnt_coin = 0;

void dfs (int i , int j) {
	if (i < 1 || j < 1 || j > m || i > n || G[i][j] == '#' || G[i][j] == 'x') {
		return;
	}
	cnt[i][j] = idx_now;
	cnt_coin += (G[i][j] == 'C');
	G[i][j] = 'x';
	dfs(i, j + 1);
	dfs(i, j - 1);
	dfs(i + 1, j);
	dfs(i - 1, j);
}

void solve () {
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		collect[i + 1] = 0;
		for (int j = 1; j <= m; ++j) {
			G[i + 1][j] = s[j - 1];
			cnt[i + 1][j] = 0;
		}
	}
	out(n, m, q);
	memset(collect, 0, sizeof(collect));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (G[i][j] != 'x' && G[i][j] != '#') {
				dfs (i, j);
				collect[idx_now] = cnt_coin;
				out(i, j, idx_now, cnt_coin);
				cnt_coin = 0;
				++idx_now;
			}
		}
	}
	while (q--) {
		int x, y; cin >> x >> y;
		out(x, y, cnt[x][y]);;
		cout << collect[cnt[x][y]] << endl;
	}

}	

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cout << "Case " << i << ":\n";
        solve ();
    }

}