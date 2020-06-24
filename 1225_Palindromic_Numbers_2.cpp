#include <iostream>
using namespace std;

void run() {    
    int x, y, i = 0, ara[11];
    scanf("%d", &x);
    y = x;
    for (; y; ++i) {
        ara[i] = y%10;
        y/=10;
    }
    for (int j = 0; j < i; ++j) {
        y = y*10 + (ara[j]);
    }
    x == y ? puts("Yes") : puts("No");
}

int main() 
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        printf("Case %d: ", i);
        run();
    }
}