#include <iostream>
#include <ctime>
#include <vector>
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
void print(T n) {
    if(n < 0) putchar('-'), n=-n; if(n > 9) print(n/10); putchar(char(n%10 + '0'));
}
 
template<typename T>
void in(T &n) {
    n=0; char ch; while(ch=getchar(), ch <=' '); bool sign(ch== '-'); if(sign)ch = getchar(); n = ch -'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;  
}
 
const int mx = 1e5+7;
vector<int> ara(mx);
vector<int> ft(mx);
 
void update(int idx, int val, int lim) {
    while(idx <=lim) {
        ft[idx] += val;
        idx += (idx & (-idx));
    }
}
 
ll sum(int idx) {
    ll sum = 0;
    while(idx > 0) {
        sum += ft[idx];
        idx -= (idx &(-idx));
    }
    return sum;
}
 
int main()
{
    // fast;
#ifndef ONLINE_JUDGE
    double st = clock();
    freopen("input.txt", "r", stdin);
#endif
    
    int t;
    in(t);
 
    for(int cs = 1; cs <= t; ++cs) {
        int sz, qury, qt, hi, lo;
        in(sz); in(qury);
 
        for(int i=1; i<=sz; ++i) {
            cin >> ara[i];
            update(i, ara[i], sz+1);
        }
        printf("Case %d:\n", cs);
 
        while(qury--) {
            in(qt); in(lo);
 
            if(qt == 1)  {
                update(lo+1, -ara[lo+1], sz+1);
                print(ara[lo+1]);
                ara[lo+1] = 0;
                puts("");
            }
            else if(qt == 2) {
                in(hi);
                update(lo+1, hi, sz+1);
                ara[lo+1] += hi;
            }
            else {
                in(hi);
                print((ll) sum(hi+1) -  sum(lo));
                puts("");
            }
        }
        if(cs != t) {
            fill(all(ara), 0);
            fill(all(ft), 0);
        }
    }
 
#ifndef ONLINE_JUDGE
    double en = clock();
    cerr << endl << "time = " << (en - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}