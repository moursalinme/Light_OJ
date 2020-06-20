#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false);cin.tie(0);
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
inline void prin(T n) {
    if (n > 9) prin(n / 10); putchar(char(n % 10 + '0'));
}  
 
template<typename t>
inline void print(t x) {
    if (x < 0) putchar('-'), x = -x; prin(x);
}
 
template<typename T>
inline void in(T&n) {
    n=0; char ch; while(ch=getchar(), ch <=' '); bool sign(ch== '-');
    if(sign)ch = getchar(); n = ch -'0';
    while(ch=getchar(), (ch >='0' && ch <='9')) n=(n*10)+(ch-'0'); sign?n =-n :1;  
}
 
const int mx = 1e5+7;
int tree[3 * mx];
int ara[mx];
int inf = 1e9;
 
void maketree(int cur, int i, int j) {
    if(i == j) {
        tree[cur] = ara[i];
        return;
    }
    int left = (cur << 1);
    int right = left+ 1;
    int mid  = ((i +  j) >> 1);
    maketree(left, i, mid);
    maketree(right, mid+ 1, j);
    tree[cur] = min( tree[left] , tree [right]);
    return;
}

ll sum(int cur, int low, int high, int i, int j) {
    if(i > high || j < low) {
        return inf;
    }
    if(low >= i && high <= j) {
        return tree[cur];
    }
    int left = (cur << 1);
    int right = left + 1;
    int mid = ((low + high) >> 1);
    ll sum1, sum2;
    sum1 = sum(left, low, mid, i, j);
    sum2 = sum(right, mid+1, high, i, j);
    return min(sum1 , sum2);
}
 
int main()
{
    int t;
    in(t);

    for(int tc = 1; tc <= t; ++tc) {
        int sz;
        in(sz);
        int quri;
        cin >> quri;

        for(int i = 1; i <= sz; ++i) {
            in(ara[i]);
        }
        maketree(1,1,sz);
        cout << "Case " << tc <<":" << endl;
 
        while(quri--) {
            int l, h;
            in(l), in(h);
            cout << sum(1,1, sz,l, h) << endl;
        }
    }
    return 0;
}