/**
 *  Straight forward implementation of any pattern matching algorithm
**/

#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>
 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define endl "\n"
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
int main()
{
        // fast;
#ifndef ONLINE_JUDGE
    double st = clock();
    freopen("input.txt", "r", stdin);
#endif
 
    int t;
    scanf("%d", &t);
 
    for(int cs = 1; cs <= t; ++cs) {
        string t, p;
        cin >> t >> p;
 
        string h = p + "$" + t;
        int ms = h.size(), ps = p.size();
        vector<int> v(ms, 0);
 
        for(int i=1, x=0, y=0; i < ms; ++i) {
            v[i] = max(0, min(v[i-x], y-i+1));
            while(i + v[i] < ms && h[v[i]+i] == h[v[i]]) {
                x=i; y=v[i]+i; v[i]++;
            }
        }
 
        int cnt = 0;
        for(int i=ps; i < ms; ++i) {
            if(v[i] == ps) {
                ++cnt;
            }
        }
 
        printf("Case %d: %d\n", cs, cnt);
    }
 
#ifndef ONLINE_JUDGE
    double en = clock();
    cerr << endl << "time = " << (en - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}