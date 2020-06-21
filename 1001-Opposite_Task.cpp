#include <iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        if (n > 10)
            cout << n - 10 << " " << 10 << endl;
        else
            cout << n << " 0" << endl;
    }
    return 0;
}