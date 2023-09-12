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

const int N = 12;
vector<int> ar;
int mod;
int last;
i64 dp[N][2][2][N];

i64 call (int pos, int small, int placed, int zr) {

        if (pos == last) return zr;
        if (dp[pos][small][placed][zr] != -1) return dp[pos][small][placed][zr];

        i64 ret = 0;

        int limit = ar[pos];
        if (small) limit = 9;

        for (int i = 0; i <= limit; ++i) {
                if (placed) ret += call (pos + 1, small | (i < ar[pos]), 1, zr + (i == 0));
                else ret += call(pos + 1, small | (i < ar[pos]), (i != 0), zr);
        }

        return dp[pos][small][placed][zr] = ret;
}

void addDigit (i64 n) {
        if (n == -1) {
                last = 0;
                return;
        }
        vector<int> v;
        while (n > 0) {
                v.push_back(n % 10);
                n /= 10;
        }
        reverse (v.begin(), v.end());
        ar = v;
        last = v.size();
        memset(dp, -1, sizeof dp);
}

void solve (int testNo) 
{       
        i64 a, b; cin >> a >> b;


        addDigit(b);
        i64 ans = call(0, 0, 0, 0) + (a == 0);

        addDigit(a - 1);
        i64 ans2 = call(0, 0, 0, 0);

        // out(ans, ans2);
        cout << ans - ans2 << endl;
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
