#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline void in(int &n) { scanf("%d", &n);}

int answer, n, base;
const int nax = 1e6+7;
vector<double> lg(nax);

void precal() {
    for (int i = 1; i < nax; ++i) {
        lg[i] = lg[i-1] + log10(i);
    }
}

int main()
{
    int t, tc = 0;
    in(t);
    precal();

    while(tc++ < t) {
        in(n), in(base);
        double x = lg[n];
        x += 0.00000001;
        answer = x / log10(base) + 1;
        printf("Case %d: %d\n", tc, answer);
    }
    return 0;
}