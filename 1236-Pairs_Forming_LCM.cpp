#include <bits/stdc++.h>
using namespace std; 

struct Prime {
    int n, siz;
    vector<int> primes;
    bitset<(int) 1e7 + 7> ok;
    Prime () = default;
    Prime (int _n) {
        n = _n;
        ok.reset();
        ok[1] = 1;
        int lim = sqrt(n) + 1;
        for (int i = 4; i <= n; i += 2) ok[i] = 1;
        for (int i = 3; i < lim; ++i) 
            if (!ok[i]) for (int j = i * i; j <=n ; j += (i + i)) ok[j]  = 1;
    }
    inline bool is_prime (int x) {return !ok[x];}
    inline void enlist () {
        primes.push_back(2);
        for (int i = 3; i <= n; i += 2) 
            if(!ok[i]) primes.push_back(i);
        siz = primes.size();
    }
    int nowsz () {return siz;}
    inline int xth (int x) {int ssz = primes.size(); return ssz > x ? -1 : primes[x-1];}
};

Prime P ((int) 1e7+7);

void solve () {
    int64_t n, cnt = 1, po, now, psz = P.primes.size();
    cin >> n;

    for (int i = 0; i < psz &&  P.primes[i] * P.primes[i] <= n; ++i) {
        po = 0, now = P.primes[i];
        if (n % now == 0) {
            while (n % now == 0) {
                po++;
                n /= now;
            }
            cnt *=  (2 * po) + 1;
        }
    }
    if (n != 1) 
        cnt *= 3;

    cout << (cnt + 1) / 2 << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);
    
    P.enlist();

    int tt = 1, tc = 1;
    cin >> tt;

    while (tt--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}