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

const int N = 1E6 + 7;
int spf[N];
vector<int> primes;

void siv () {
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

vector<i64> getFacts (i64 n) {
	vector<i64> ret;

	if (n <= 1E6) {
		while (n > 1) {
			int d = spf[n];
			while(n % d == 0) n /= d, ret.push_back(d);
		}
	} else {

		for (int i : primes) {
			if (i > n) break;
			if (n % i == 0) {
				while (n % i == 0) n /= i, ret.push_back(i);
			}
		}
		if (n > 1) ret.push_back(n);
	}
	return ret;
}

i64 power (i64 a, i64 b) {
	i64 ret = 1;
	while (b > 0) {
		if (b & 1) {
			ret = ret * a;
		}
		b >>= 1;
		a = a * a;
	}
	return ret;
} 


void solve (int testNo) 
{
	i64 a, b, L; cin >> a >> b >> L;
	i64 lcm = (a * b) / __gcd(a, b);

	vector<i64> fa = getFacts(lcm);
	vector<i64> fl = getFacts(L);
	map<i64, int> mpL, mpA;

	for (auto i : fl) mpL[i]++;
	for (auto i : fa) mpA[i]++;

	for (auto i : fa) {
		if (mpA[i] >= mpL[i]) mpL[i] = 0;
	}

	i64 ans = 1;
	for (auto i : mpL) if (i.ss > 0) {
		 ans *= power(i.ff, i.ss);
	}

	if (ans * lcm / __gcd(ans, lcm) != L) {
		cout << "impossible\n";
		return;
	} 

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
