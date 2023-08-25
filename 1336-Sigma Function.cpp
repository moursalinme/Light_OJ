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
using Long = long long;

void solve (int testNo) 
{
	i64 n; cin >> n;
	cout << n - (int)sqrt(n) - (int)sqrt(n / 2) << endl;
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
