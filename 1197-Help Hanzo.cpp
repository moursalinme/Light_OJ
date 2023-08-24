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

const int N = 46400;
int spf[N];
vector<int> primes;

void siv() {
        for (int i = 2; i < N; i++) {
                if (spf[i] == 0) {
                        spf[i] = i;
                        primes.push_back(i);
                }

                for (auto p : primes) {
                        if (i * p >= N) {
                            break;
                        }
                        spf[i * p] = p;
                        if (p == spf[i]) {
                            break;
                        }
                }
        }
}

void solve (int testNo)
{
	int l, r; cin >> l >> r;
	
	int len = r - l + 1;
	vector<bool> foo(len, 0);
	if (l == 1) foo[0] = 1;

	for (auto p : primes) {
		i64 d = 1LL * (l / p) * p;
		if (d < l) d += p;
		d = max (d, 2LL * p);
		for (; d <= r; d += p)  foo[d - l] = 1;
	}

	int ans = 0;	
	for (bool i : foo) ans += !i;
	cout << ans << endl;
}

signed main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	cin >> tc;
	siv();

	for (int i = 1; i <= tc; ++i) {
		cout << "Case " << i << ": ";
		solve (i);
	}

	return 0;
}
