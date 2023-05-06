#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200200;

int arr[N];
int st[4 * N];

// BUILD
void build(int l, int r, int pos)
{
    if (l == r)
    {
        st[pos] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, 2 * pos + 1);
    build(mid + 1, r, 2 * pos + 2);
    st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
}

// UPDATE
void update(int l, int r, int pos, int idx, int x)
{
    if (l > idx || r < idx)
        return;
    if (l == r && l == idx)
    {
        st[pos] = arr[l] = x;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, 2 * pos + 1, idx, x);
    update(mid + 1, r, 2 * pos + 2, idx, x);
    st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
}

// FIND
int search(int l, int r, int pos, int ql, int qr)
{
    if (l > qr || r < ql)
        return 0;
    if (r <= qr && l >= ql)
    {
        return st[pos];
    }
    int mid = (l + r) / 2;
    return search(l, mid, 2 * pos + 1, ql, qr) + search(mid + 1, r, 2 * pos + 2, ql, qr);
}
// POINT UPDATE RANGE QUERIES
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(0, n - 1, 0);
    int c;
    while (q--)
    {
        cin >> c;
        if (c == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            update(0, n - 1, 0, a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << search(0, n - 1, 0, a, b) << endl;
        }
    }
    return 0;
}