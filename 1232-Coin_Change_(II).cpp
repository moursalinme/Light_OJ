#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iterator>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
#ifdef LOCAL
#define _rp replace (_N.begin(), _N.end(), ',', ' ');
#define itrt istream_iterator<string>
#define out(_...) {string _N = #_; _rp; stringstream ss(_N); itrt it(ss);debug(it, _);}
inline void debug(itrt it) { cerr << endl;}
template <typename T, typename... X>
inline void debug(itrt it, T val, X ..._value) {
    cerr << "[" << *it << ": " << val << "] ";  
    debug(++it, _value...);
}
#else 
#define out(...)
#endif

void solve() {
    int n, t, M = 100000007;
    cin >> n >> t;
    vector<int> ar(n+1);

    for (int i = 0; i < n; ++i) 
        cin >> ar[i+1];

    vector<long long> dp(t+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = ar[i]; j <= t; ++j) {
            if (j - ar[i] >= 0) 
                dp[j] += dp[j-ar[i]];
            if (dp[j] >= M) 
                dp[j] -= M;
        }
    }
    cout << dp[t] << endl;
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1, tc = 1;
    cin >> t;

    while(t--) {
        cout << "Case " << tc++ << ": ";
        solve();
    }
    return 0;
}
