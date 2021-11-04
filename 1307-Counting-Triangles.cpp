#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #include "dbg.h"
#else
    #define out(...) 
#endif

void solve () {
    int n; cin >> n; 
    vector<int> ar (n);

    for (int& i : ar) 
        cin >> i;

    sort (ar.begin(), ar.end());
    int ways = 0;
    out (ar);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int twoSum = ar[i] + ar[j];
            int idx = upper_bound (ar.begin(), ar.end(), twoSum - 1) - ar.begin() - 1;
            if (idx > j) ways += idx - j;
            out (i, j, twoSum, idx);
        }
    }

    cout << ways << '\n';
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