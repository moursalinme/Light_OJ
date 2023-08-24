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
    i64 n; cin >> n;
    bool sign = n < 0;

    for (int power = 32; power > 0; --power) {
        if (sign && !(power & 1)) continue;

        i64 lo = 2, hi = abs(n);
        while (lo <= hi) {
            i64 mid = (lo + hi) / 2;
            i64 num = 1;
            if (sign) mid *= -1;

            for (int i = 1; i <= power; ++i) {
                num *= mid;
                if (num > n && !sign) break;
                if (num < n && sign) break;
            }

            if (sign && num >= 0) num /= mid;

            mid = abs(mid);
            if (num == n) {
                cout << power << endl;
                return;
            }

            if (sign) {
                if (num < n) hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (num > n) hi = mid - 1;
                else lo = mid + 1;

            }
        }
    } 
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
