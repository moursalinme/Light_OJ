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

bool get(vector<int> &v, int n, int target) {
	vector<int> ms;
	int k = -1;

	for (int i = 0; i < n; ++i) {
		auto it = lower_bound(ms.begin(), ms.end(), v[i]);
		if (it == ms.end()) ms.push_back(v[i]);
		else {
			int idx = it - ms.begin();
			ms[idx] = v[i];
		}
		if ((int)ms.size() == target) {
			k = i;
			break;
		}
	}

	if (k == -1) return 0;
	ms.clear();

	for (int i = n - 1; i >= k; --i) {
		auto it = lower_bound(ms.begin(), ms.end(), v[i]);
		if (it == ms.end()) ms.push_back(v[i]);
		else {
			int idx = it - ms.begin();
			ms[idx] = v[i];
		}
	}

	return (int) ms.size() >= target;
} 

void solve (int testNo) {
	int n; cin >> n;
	vector<int> v(n);

	for (int& i : v) cin >> i;

	int lo = 1, hi = (n + 1) / 2;
	int ans = 1;
	
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (get(v, n, mid)) {
			lo = mid + 1;
			ans = max (ans, mid);
		} else hi = mid - 1;
	}
	cout << ans * 2 - 1 << endl;
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
