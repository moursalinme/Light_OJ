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

struct SuffixArray {
    string s;
    vector<int> sa, pos, temp, lcp;
    int n;

    SuffixArray (string _s) { // complexity O(nLog^2(n)) 
        s = _s; s += '$';
        n = s.size();
        sa = pos = temp = vector<int> (n);

        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            pos[i] = s[i];
        }

        int k;
        auto comp = [&] (int i, int j) {
            if (pos[i] == pos[j]) {
                if (i + k < n && j + k < n) return pos[i + k] < pos[j + k];
                return i > j;
            }
            return pos[i] < pos[j];
        };

        for (k = 1; k < n; k <<= 1) {
            sort (sa.begin(), sa.end(), comp);
            temp[0] = 0;
            for (int i = 1; i < n; ++i) {
                temp[i] = temp[i - 1] + comp(sa[i - 1], sa[i]);
            }
            for (int i = 0; i < n; ++i) pos[sa[i]] = temp[i];
            if (temp[n - 1] == n - 1) break;

        }
    }

    void buildLCP () { // complexity : O(n)
        lcp.resize(n);

        for (int i = 0, k = 0; i < n; ++i) {
            if (pos[i] != n - 1) {
                for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k];) ++k;
            }
            lcp[pos[i]] = k;
            if (k) --k;
        }
    }
    
};

void solve (int testNo)
{
    string s; cin >> s;
    int p, q; cin >> p >> q;

    SuffixArray X(s);
    X.buildLCP();
    auto& SA = X.sa;
    auto& LCP = X.lcp;
    int n = s.size(), ans = 0;

    for (int i = 0; i < n; ++i) {
        int y = min (n - SA[i + 1], q) - max (LCP[i], p - 1);
        ans += max (0, y);
    }

    cout << ans << endl;

}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        cout << "Case " << i << ": ";
        solve (i);
    }

    return 0;
}
