#include <iostream>
#include <vector>

using namespace std;
inline void in(int &n) { scanf("%d", &n);}

const int nax = 5000007;
vector<unsigned long long> phi(nax+7);

void _phi() {
    for (int i = 0; i < nax; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i < nax; ++i) {
        if(phi[i] == i) {
            for (int j = i; j < nax; j += i) {
                phi[j] -= phi[j]/i;
            }
        }
    }
    for (int i = 1; i < nax; ++i) {
        phi[i]*= phi[i];
        phi[i] += phi[i-1];
    }
}

int main()
{
    _phi();
    int t, tc = 0;
    in(t);

    while(tc++ < t) {
        int a, b;
        in(a);in(b);
        printf("Case %d: %llu\n", tc, phi[b] - phi[a-1]);
    }
    return 0;
}