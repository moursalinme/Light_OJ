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

const int N = 1E7 + 7;
int spf[N];
vector<int> primes;

void siv() {
        for (int i = 2; i < N; i++) {
                if (spf[i] == 0) {
                        spf[i] = i;
                        primes.push_back(i);
                }

                for (auto p : primes) {
                        if (i * p > N) {
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
	i64 n; cin >> n;
	while (n % 2 == 0) n /= 2;
	i64 ans = 1;

	for (int i : primes) {
		if (i > n) break;
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) ++cnt, n /= i;
			ans *=  (1LL * cnt + 1);
		}

	}

	if (n > 2) ans *= 2;

	cout << ans - 1 << endl;
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
