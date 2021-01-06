#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iterator>
#include <sstream>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
#ifdef MOURSALIN
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

struct Prime {
    int n, siz;
    vector<int> primes;
    bitset<(int) 1e3 + 7> ok;
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

Prime p(210);

struct Pfs {
    vector<pair<int,int>> col;
};

Pfs pfs[210], res[210];


void precom() {
    for (int i = 2; i < 205; ++i) {
        int now = i, j = 0;

        while(j < p.primes.size() && now > p.primes[j]) {
            if (now % p.primes[j] == 0) {
                int cnt = 0;
                while(now % p.primes[j] == 0) {
                    cnt ++;
                    now /= p.primes[j];
                }
                out(i, now, p.primes[j], cnt)
                pfs[i].col.push_back({p.primes[j], cnt});
            }
            ++j;
        }

        if (now != 1) {
            out(now, i);
            pfs[i].col.push_back({now, 1});
        } 
    }

    map<int,int> mp;
    int N = 200, now = 2;

    while(now <= N) {
        for (int i = 0; i < pfs[now].col.size(); ++i) {
            out(now, pfs[now].col[i].first, pfs[now].col[i].second);
            mp[pfs[now].col[i].first] += pfs[now].col[i].second;             
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            res[now].col.push_back({it->first, it->second});
        }
        out(now, res[now].col.size());
        ++now;
    }
}

void solve () {
    map<int, int> mp;
    int N;
    cin >> N;
    cout << N << " = ";
    int sz = res[N].col.size();

    for (int i = 0; i < sz; ++i) {
        cout << res[N].col[i].first << " (" << res[N].col[i].second << ")";
        if (i+1 == sz) {
            cout << endl;
            break;
        }
        else cout << " * ";
    }
}
 
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double st = clock();

    int t = 1, tc = 1;
    cin >> t;

    p.enlist();
    precom();

    while(t--) {
        cout << "Case " << tc++ << ": ";
        solve();
    }

    cerr << "Time = " <<  (clock() - st) / CLOCKS_PER_SEC <<  endl;
    return 0;
}
