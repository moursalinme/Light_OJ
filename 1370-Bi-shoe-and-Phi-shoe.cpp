#include <bits/stdc++.h>
using namespace std;

struct Prime {
    int n, siz;
    vector<int> primes;
    bitset<(int) 1e6 + 7> ok;
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
    inline int xth (int x) {return primes.size() > x ? -1 : primes[x-1];}
};

Prime p ((int) 1e6+7);

void solve () {
    int64_t n, temp, res = 0;
    cin >> n;

    while (n--) {
        cin >> temp;
        int idx = lower_bound (p.primes.begin(), p.primes.end(), temp + 1) - p.primes.begin();
        res += p.primes[idx];
    }
    cout << res << " Xukha" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (0); cout.tie(0);

    int t, tc = 1;
    cin >> t;
    p.enlist ();

    while (t--) {
        cout << "Case " << tc++ << ": ";
        solve ();
    }
    return 0;
}
