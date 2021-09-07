#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #include "dbg.h"
#else
    #define out(...) 
#endif

bool is_leap_year (long long n) {
    return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}

int cnt (long long n) {
    int A = (n / 400 + (n / 4 - n / 100));
    return A;
}

void solve () { 
    long long int fy, sy, fd, sd;
    char ch;
    string fm, sm;

    cin >> fm >> fd >> ch >> fy;
    cin >> sm >> sd >> ch >> sy;

    int ans = cnt (sy) - cnt (fy - 1);

    if (is_leap_year (fy)) {
        if (fm != "January" && fm != "February") --ans;
    }

    if (is_leap_year (sy)) {
        if (sm == "January")                    --ans;
        else if (sm == "February" && sd < 29)   --ans;
    }
    cout << max (0, ans) << '\n';
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