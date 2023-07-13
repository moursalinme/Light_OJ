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

void solve (int test_no) {
    i64 total, left; cin >> total >> left;
    i64 eaten = total - left;

    set<i64> divs;
    for (i64 i = 1; i * i <= eaten; ++i) {
        if (eaten % i == 0) {
            if (i > left) divs.insert(i);
            if (eaten / i > left) divs.insert(eaten / i);
        }
    }
    if (divs.empty()) {
        cout << " impossible\n";
        return;
    }
    for (auto i : divs) 
        cout << ' ' << i;
    cout << endl;;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) { 
        cout << "Case " << i << ":";
        solve (i);
    }
    
    return 0;
}
