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
    string s;
    cin >> s;

    n = s.size();
    vector<int> tree (n+1, 0);

    auto add = [&] (int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += (idx & (-idx));
        }
    };

    auto update = [&] (int _l, int _r) {
        add (_l, 1);
        add (_r + 1, -1);
    };

    auto sum = [&] (int idx) {
        int sums = 0;
        while (idx > 0) {
            sums += tree[idx];
            idx -= (idx & -idx);
        }
        return sums;
    };

    char ch;
    int l, r, cur, q;
    cin >> q;

    while (q--) {
        cin >> ch;
        
        if (ch == 'I') {
            cin >> l >> r;
            update (l, r);
        }
        else {
            cin >> l;
            cur = s[l-1] - '0';
            r = sum (l) % 2;
            cout << (cur ^ r) << endl;
        }
    }
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt = 1, tc = 1;
    cin >> tt;

    while(tt--) {
        cout << "Case " << tc++ << ":\n";
        solve();
    }
    return 0;
}
