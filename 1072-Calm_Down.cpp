#include <iostream>
#include <cmath>
using namespace std;

inline void in(int &n) {scanf("%d", &n);}
const double pi = acos(-1);

int main() 
{
    int t, tc = 0;
    in(t);
    double R, answer;
    int n;

    while(tc++ < t) {
        scanf("%lf", &R);
        in(n);
        answer = sin(pi/n);
        answer = (R*answer) / (1+answer);
        printf("Case %d: %.8lf\n", tc, answer);
    }
    return 0;
}