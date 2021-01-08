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
    cerr << "[" << *it << ": " << val << "] ";  debug(++it, _value...);
}
#else 
#define out(...)
#endif

int64_t m, n, sz;
string s;
int64_t dp[100][100][2][2];

int64_t calc (int pos, int64_t sum, bool small, bool start) {
    if (pos == sz) {
        return sum;
    }
    if (dp[pos][sum][small][start] != -1) {
        return dp[pos][sum][small][start];
    }

    int hi = small ? 9 : s[pos] - '0';
    int64_t ret = 0;

    if (start) { // we already started counting, so i can put 0 .
        for (int i = 0; i <= hi; ++i) { 
            ret += calc (pos+1, sum + (i == 0), (small | i < hi), 1);
        }
    }
    else { // we haven't started counting, so we have two options 
           // 1. start counting now (in this case we can not put 0 in start)
           // 2. start counting from next pos

        for (int i = 1; i <= hi; ++i) { 
            ret += calc (pos+1, sum, (small | i < hi), 1);
        }
        ret += calc (pos+1, 0, 1, 0);
    }
    return dp[pos][sum][small][start] = ret;
}

int64_t forn (int64_t _n) {
    if (_n < 0) {
        return n == 0 ? 1 : 0;
    }
    memset(dp, -1, sizeof(dp));
    s = to_string(_n);
    sz = s.size();
    _n = calc (0, 0, 0, 0);
    return _n + 1;
}   

void solve () {
    cin >> m >> n;
    cout << forn(n) - forn (m-1) << endl;
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
