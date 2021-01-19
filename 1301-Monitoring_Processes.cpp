#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <sstream>
#include <iterator>
#include <queue>
#include <bitset>
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
    vector<pair<int, int>> v (n);

    for (pair<int, int>& i : v) {
        cin >> i.first >> i.second;
    }

    sort (v.begin(), v.end(), [&] (const pair <int, int> a, const pair <int, int> b) {
        if (a.first == b.first) 
            return a.second > b.second;
        return a.first < b.first;
    });

    int cnt = 1, mx_til_now = v[0].second, ans = 1;
    priority_queue <int, vector<int>, greater <int>> q;
    q.push (v[0].second);

    for (int i = 1; i < n; ++i) {
        while (!q.empty () && q.top() < v[i].first) {
            --cnt;
            q.pop ();
        }
        if (v[i].first <= mx_til_now || q.empty()) {
            ++cnt;
        }
        q.push (v[i].second);

        mx_til_now = max (mx_til_now, v[i].second);
        ans = max (ans, cnt);
        out (ans, cnt, mx_til_now);
    }
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);
    
    int tt = 1, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}