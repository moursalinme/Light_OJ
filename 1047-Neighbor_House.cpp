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

void solve () {
    int n;
    cin >> n;
    vector<vector<int>> rgb (n, vector<int> (3, 0));

    for (auto& i: rgb) {
        for (int& j : i) { 
            cin >> j;
        }
    }
    for (int i = 1; i < n; ++i) {
        rgb[i][0] += min (rgb[i-1][1], rgb[i-1][2]);
        rgb[i][1] += min (rgb[i-1][0], rgb[i-1][2]);
        rgb[i][2] += min (rgb[i-1][0], rgb[i-1][1]);
    }
    --n;
    cout << min ({rgb[n][0], rgb[n][1], rgb[n][2]}) << endl;
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