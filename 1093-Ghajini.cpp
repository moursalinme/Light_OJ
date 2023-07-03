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

const int N = 1E5 + 5;

int val[N];
int treemx[4 * N];
int treemn[4 * N];

void build (int r, int l = 1, int cur = 1) {
    if (l == r) {
        treemx[cur] = val[l];
        treemn[cur] = val[l];
        return;
    }
    int m = (r + l) / 2, ci = cur * 2;
    build (m, l, ci);
    build (r, m + 1, ci + 1);
    treemx[cur] = max(treemx[ci], treemx[ci + 1]); 
    treemn[cur] = min(treemn[ci], treemn[ci + 1]); 
}

int findmax (int cur, int l, int r, int i, int j) {
    if (i > r || l > j) return -1E9;
    if (l >= i && r <= j) return treemx[cur];
    int ci = cur * 2, m = (l + r) / 2;
    return max(findmax(ci, l, m, i, j), findmax(ci + 1, m + 1, r, i, j));
}

int findmin (int cur, int l, int r, int i, int j) {
    if (i > r || l > j) return 1E9;
    if (l >= i && r <= j) return treemn[cur];
    int ci = cur * 2, m = (l + r) / 2;
    return min(findmin(ci, l, m, i, j), findmin(ci + 1, m + 1, r, i, j));
}

void solve (int test_no) 
{
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; ++i) 
        cin >> val[i];

    build (n);
    int ans = 0;

    for (int i = 1; i < n; ++i) {
        int l = min (i + d - 1, n);
        int mx = findmax(1, 1, n, i, l);
        int mn = findmin(1, 1, n, i, l);
        ans = max (ans, mx - mn);
    }
    cout << "Case " << test_no << ": " << ans << endl;
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
