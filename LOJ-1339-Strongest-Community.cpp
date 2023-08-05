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

const int N = 1E5 + 7;
int foo[N];
int tree[4 * N];

void build (int node, int l, int r) {
	if (l == r) {
		tree[node] = foo[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 | 1, mid + 1, r);
	tree[node] = max (tree[node * 2], tree[node * 2 | 1]);
}

int qry (int node, int l, int r, int i, int j) {
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return tree[node];
	int mid = (l + r) / 2;
	return max (qry(node * 2, l, mid, i, j), qry(node * 2 | 1, mid + 1, r, i, j));
}

void solve (int testNo) {
	int n, c, q; cin >> n >> c >> q;
	int ar[n + 1];

	for (int i = 1; i <= n; ++i) 
		cin >> ar[i];


	int id[n + 1] = {0};
	int idx = 1;
	int first[n + 1] = {0};
	foo[1] = 1, id[1] = 1; first[ar[1]] = 1;

	for (int i = 2; i <= n; ++i) {
		if (ar[i - 1] == ar[i]) first[ar[i]] = first[ar[i - 1]],foo[idx]++;
		else foo[++idx] = 1, first[ar[i]] = i;
		id[ar[i]] = idx;
	}

	build (1, 1, c);
	while (q--) {
		int l, r; cin >> l >> r;

		if (id[ar[l]] == id[ar[r]]) cout << r - l + 1 << endl;
		else {
			int age = (first[ar[l]] + foo[id[ar[l]]] - l);
			int pore = (r - first[ar[r]] + 1);
			int majhe = 0;
			l = id[ar[l]], r = id[ar[r]]; ++l, --r;
			if (l <= r) majhe = qry (1, 1, c, l, r);
			cout << max ({age, majhe, pore}) << endl;;
		}
	}
}   

signed main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 

	int tc = 1;
	cin >> tc;

	for (int i = 1; i <= tc; ++i) { 
		cout << "Case " << i << ":\n"; 
		solve (i);
	}
	
	return 0;
}
