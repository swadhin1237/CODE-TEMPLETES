#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, q;
    n = (rand()) % 100000;
    q = (rand()) % 100000;

    cout << n << " " << q << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (rand()) % 10000000 << " ";
    }
    cout << endl;

    while (q--)
    {
        int c = (rand()) % 2;
        c++;
        if (c == 1)
        {
            int a, b;
            a = (rand()) % n;
            b = (rand()) % 10000000;
            cout << c << " " << ++a << " " << b << endl;
        }
        else
        {
            int a, b;
            a = (rand()) % (n - 1);
            while ((b = (rand()) % n) <= a)
            {
            }
            cout << c << " " << ++a << " " << ++b << endl;
        }
    }
}
