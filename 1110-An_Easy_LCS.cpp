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

string a, b;
int as, bs;
string dp[105][105];

string minstr (const string x, const string y) {
    if (x.size() != y.size()) {
        return x.size() > y.size() ? x : y;
    } 
    int sz = x.size();

    for (int i = 0; i < sz; ++i) {
        if (x[i] != y[i]) {
            return x[i] < y[i] ? x : y;
        }
    }
    return x;
}

string lcs (int i, int j) {
    if (i == as || j == bs) {
        return "";
    }
    if (dp[i][j] != "-1") {
        return dp[i][j];
    }
    string cnt = "";

    if (a[i] == b[j]) {
        cnt = a[i] + lcs (i+1, j+1);
    }
    else {
        string cnt1, cnt2;
        cnt1 = lcs (i+1, j);
        cnt2 = lcs (i, j+1);
        cnt = minstr (cnt1, cnt2);
    }
    return dp[i][j] = cnt;
}

void solve () {
    cin >> a >> b;
    as = a.size(), bs = b.size();
    
    for (int i = 0; i <= 101; ++i) {
        for (int j = 0; j <= 101; ++j) {
            dp[i][j] = "-1";
        }
    }
    
    string ans = lcs (0, 0);
    cout << (ans.size() ? ans : ":(") << endl;
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