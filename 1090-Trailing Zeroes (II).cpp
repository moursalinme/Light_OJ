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

void solve (int testNo)
{
	int n, r, p, q; cin >> n >> r >> p >> q;

	auto countx = [&] (int n, int x) {
		int ret = 0;
		int d = x;
		while (d <= n) ret += n / d, d *= x; 
		return ret;
	};

	int n2 = countx(n, 2);
	int n5 = countx(n, 5);
	int r2 = countx(r, 2);
	int r5 = countx(r, 5);
	int n_r2 = countx(n-r, 2);
	int n_r5 = countx(n-r, 5);

	auto count = [&] (int x, int y) {
		int ret = 0;
		while (x % y == 0) ret ++, x /= y;
		return ret;
	};
	
	int p2 = count(p, 2) * q;
	int p5 = count(p, 5) * q;
	int ans = max (0, min (n2 - r2 - n_r2 + p2, n5 - r5 - n_r5 + p5));

	cout << ans << endl;
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	cin >> tc;

	for (int i = 1; i <= tc; ++i) {
		cout << "Case " << i << ": ";
		solve (i);
	}

	return 0;
}
