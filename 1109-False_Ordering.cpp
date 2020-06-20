#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline void in(int &n) { scanf("%d", &n);}

int main() 
{
    int t, tc = 0, N;
    in(t);
    vector<pair<int, int>> div(1001);

    for (int i = 1; i < 1001; ++i) {
        div[i].second = i;
        for (int j = i; j < 1001; j+= i) {
            div[j].first++;
        }
    }

    sort(div.begin(), div.end(), [&] (pair<int, int> &a, pair<int, int> &b) {
        if(a.first < b.first) return a < b;;
        if(a.first == b.first) return a.second > b.second;
        return b > a;
    });

    while(tc++ < t) {
        in(N);
        printf("Case %d: %d\n", tc, div[N].second);
    }
}