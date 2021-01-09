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
inline void debug(itrt it) { cout << endl;}
template <typename T, typename... X>
inline void debug(itrt it, T val, X ..._value) {
    cout << "[" << *it << ": " << val << "] ";  
    debug(++it, _value...);
}
#else 
#define out(...)
#endif

vector<int> vec;
int dp[101][101], n, w, k, x;

int cal (int pos, int moves) {
    if (moves == 0 || pos >= n) {
        return 0;
    }
    if (dp[pos][moves] != -1) {
        return dp[pos][moves];
    }
    int hi = upper_bound (vec.begin(), vec.end(), vec[pos]+w) - vec.begin();
    int cnt = hi - pos;
    int tot = cnt + cal(hi, moves-1);
    tot = max (tot, cal (pos+1, moves));

    return dp[pos][moves] = tot;
}

void solve () {
    cin >> n >> w >> k;
    vec.resize(n);

    for (int i = 0; i < n; ++i) 
        cin >> x >> vec[i];

    sort (vec.begin(), vec.end());
    memset (dp, -1, sizeof(dp));

    cout << cal (0, k) << endl;
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