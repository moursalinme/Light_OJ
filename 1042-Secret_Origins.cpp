#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
 
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
 
template<typename T>
void print(T n) {
    if(n < 0) putchar('-'), n=-n; if(n > 9) print(n/10); putchar(char(n%10 + '0')); return;
}
 
template<typename T>
void in(T &n) {
    n=0; char ch; while(ch=getchar(), ch <=' '); bool sign(ch== '-');
    if(sign)ch = getchar(); n = ch -'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1; return;
}
 
int main()
{
        // fast;
#ifndef ONLINE_JUDGE
    double st = clock();
    // freopen("input.txt", "r", stdin);
#endif

    int t;
    in(t);
 
    for(int cs = 1; cs <= t; ++cs) {
        int n;
        in(n);
        vector<int> bin;
 
        for(; n;) {
            if(n&1) bin.pb(1);
            else bin.pb(0);
            n>>=1;
        }
        bin.pb(0);
        reverse(all(bin));
        next_permutation(all(bin));
        int ans = 0, zog =1;
 
        for(int i = bin.size()-1; i>=0; --i) {
            if(bin[i]) ans += zog;
            zog<<=1;
        }    
        printf("Case %d: %d\n", cs, ans);
        bin.clear();
    }
 
#ifndef ONLINE_JUDGE
    double en = clock();
    cerr << endl << "time = " << (en - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}