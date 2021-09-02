#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #include "dbg.h"
#else
    #define out(...) 
#endif

void solve () { 
    int n, q; cin >> n >> q;
    vector<long long> a(n);

    for (long long& i : a) 
        cin >> i;

    long long ans = 0;

    for (int i = 0, j; i < n; ++i) {
        j = n - (i + 1);
        ans -= (a[i] * i);
        ans += (a[i] * j);
    }

    while (q--) {
        int ty; cin >> ty;

        if (!ty) {
            int pos, rep; cin >> pos >> rep;
            int i = pos, j = n - (pos + 1);
            ans += (a[i] * i);
            ans -= (a[i] * j);
            a[i] = rep;
            ans -= (a[i] * i);
            ans += (a[i] * j);
        }
        else cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cout << "Case " << i << ":\n";
        solve ();
    }
}