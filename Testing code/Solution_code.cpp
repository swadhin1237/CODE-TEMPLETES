#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 200010;

int inf = 1e9;
int mod = 1e9 + 7;

ll tree[4 * N];

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

ll query(int node, int start, int end, int l, int r)
{
    if (start > r || end < l)
        return 0;
    if (start >= l && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

signed main()
{
    // freopen("IN", "r", stdin);
    // freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        update(1, 0, n - 1, i, x);
    }

    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            a--;
            update(1, 0, n - 1, a, b);
        }
        else
        {
            a--;
            b--;
            cout << query(1, 0, n - 1, a, b) << "\n";
        }
    }
    return 0;
}