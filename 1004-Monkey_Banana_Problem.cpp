#include <iostream>
#include <vector>
 
using namespace std;
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
inline void in(int &n) { scanf("%d", &n);}
 
void run() {
    int row;
    in(row);
    int lim = (2*row)-1;
    vector<vector<int>> ara(lim+4, vector<int> (row+4, 0));
 
    for (int i = 1, cnt = 1; i <= lim; ++i) {
        if(i <= row) {
            for (int j = 1; j <= i; ++j) {
                in(ara[i][j]);
            }
        }
        else {
            for (int j = ++cnt; j <= row; ++j) {
                in(ara[i][j]);
            }
        }
    }
 
    int answer = -1;
    for (int i = 1, cnt = 1; i <= lim; ++i) {
        if(i <= row) {
            for (int j = i; j >= 1; --j) {
                ara[i][j] += max(ara[i-1][j], ara[i-1][j-1]);
                answer = max(answer, ara[i][j]);
            }
        }
        else {
            for (int j = row; j > cnt; --j) {
                ara[i][j] += max(ara[i-1][j], ara[i-1][j-1]);
                answer = max(answer, ara[i][j]);
            }
        }
    }
    printf("%d\n", answer);
}
 
int main()
{
    int t = 1, tc = 0;
    in(t);

    while(tc++ < t) {
        printf("Case %d: ", tc);
        run();
    }
    return 0;
}