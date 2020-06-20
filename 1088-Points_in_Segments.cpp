#include <iostream>
#include <climits>
#include <ctime>
#include <vector>
#include <algorithm>
 
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
template<typename T>
void print(T n) {
    if(n < 0) putchar('-'),n=-n;int ara[20],i{};while(n>9)ara[i++]=n%10,n/=10;
    ara[i]=n;while(i-->-1) putchar((char)ara[i+1] + '0');
}
 
template<typename T>
void in(T &n) {
    n=0;char ch;while(ch=getchar(),ch<=' ');bool sign(ch=='-');if(sign)ch=getchar();n=ch-'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;
}
 
int lb(int n, vector<int> &v) {
    int lo = 0, hi = v.size()-1, mid;
 
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(v[mid] == n)     hi = mid-1;
        else if(v[mid] > n) hi = mid-1;
        else                lo = mid+1;                    
    }
    return lo;
}
 
int ub(int n, vector<int> &v) {
    int lo = 0, hi = v.size()-1, mid;
 
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(v[mid] == n)     lo = mid+1;
        else if(v[mid] > n) hi = mid-1;
        else                lo = mid+1;                    
    }
    return lo;
}
 
int main()
{
#ifndef ONLINE_JUDGE
    double st = clock();
    freopen("input.txt", "r", stdin);
#endif
 
    int t; in(t);
 
    for(int cs = 1; cs <=t; ++cs) {
        int hi, lo, n, q;
        in(n), in(q);
        vector<int> v(n);
        printf("Case %d:\n",cs);
 
        for(int i=0; i < n; ++i)
            cin >> v[i];
 
        while(q--) {
            in(lo);in(hi);
            lo = lb(lo, v);
            hi = ub(hi, v);
            print(hi-lo);
            puts("");
        }
    }
 
#ifndef ONLINE_JUDGE
    cerr << "\n" << "time = " << (clock() - st) / CLOCKS_PER_SEC << "\n";
#endif
    return 0;
}