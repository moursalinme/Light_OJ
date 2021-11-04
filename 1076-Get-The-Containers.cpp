#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "dbg.h"
#else
	#define out(...) 
#endif

int n, m;
vector<int> milk;

void solve () {
	cin >> n >> m;
	milk.resize(n);
	int64_t tot = 0;

	for (int& i : milk) 
		cin >> i, tot += i;

	int lo = 1, hi = tot;
	int ans = -1;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 1;
		int64_t sum = 0;
		bool f = 0;

		for (int i = 0; i < n; ++i) {
			if (milk[i] > mid) {
				f = 1;
				break;
			}
			if (sum + milk[i] <= mid) sum += milk[i];
			else sum = milk[i], ++cnt; 
		}

		if (f) {
			lo = mid + 1;
			continue;
		}

		if (cnt <= m) {
			ans = mid;
			hi = mid - 1;
		} 
		else lo = mid + 1;
	}

	out (milk);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int tc = 1;
	cin >> tc;

	for (int i = 1; i <= tc; ++i) {
		cout << "Case " << i << ": ";
		solve ();
	}
}