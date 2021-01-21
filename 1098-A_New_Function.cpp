#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define _rp replace (_N.begin(), _N.end(), ',', ' ');
#define itrt istream_iterator<string>
#define out(_...) {string _N = #_; _rp; stringstream ss(_N); itrt it(ss);debug(it, _);}
inline void debug(itrt it) { cerr << endl;}
template <typename T, typename... X>
inline void debug(itrt it, T val, X ..._value) {
    cerr << "[" << *it << ": " << val << "] ";  debug(++it, _value...);
}
#else 
#define out(...)
#endif

void solve () {
    int n;
    cin >> n;
    int lim = sqrt (n) + 1;

    int64_t answer = 0;

    for (int i = 2; i * i <= n; ++i) {
        int64_t sum1, sum2;
        sum1 = n / i;
        sum1 = (sum1 * (sum1 + 1)) / 2;
        sum2 = i * (i-1) / 2;
        // out (sum1, sum2, answer);
        answer += sum1 - sum2;
        sum2 = (n / i) - i;
        if (sum2 >= 0 ) answer += (sum2 * i);
        // out (sum2, answer);

    }
    cout << answer << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tt = 1, tc = 1;
    cin >> tt;
    
    while (tt--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }

    return 0;
}