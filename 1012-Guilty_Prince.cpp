#include <iostream>
#include <ctime>
 
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
 
int row, col, ans;
int vis[21][21];
char ara[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
bool is_valid (int xx, int yy) {
    return (xx >=0 && xx < row && yy >= 0 && yy < col);
}
 
void dfs(int x, int y) {
    for(int i = 0; i < 4; ++i) {
        if(is_valid(dx[i]+x, dy[i]+y) && ara[dx[i]+x][dy[i]+y] == '.' && vis[dx[i]+x][dy[i]+y] == 0) {
            ans ++;
            vis[dx[i]+x][dy[i]+y] = 1;
            dfs(dx[i]+x, dy[i]+y);
        }
    }
}
 
 
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
        scanf("%d%d", &col, &row);
        int x, y;
 
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                cin >> ara[i][j];
                if(ara[i][j] == '@') {
                    vis[i][j] = 1;
                    x = i;
                    y = j;
                }
                vis[i][j] = 0;
            }
        }
        ans = 1;
        dfs(x, y);
        printf("Case %d: %d\n", cs, ans);
    }
 
 
#ifndef ONLINE_JUDGE
    double en = clock();
    cerr << endl << "time = " << (en - st) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}