#include <bits/stdc++.h>

using namespace std;

template <typename T>
class segmentTree
{
public:
    vector<T> st;
    vector<T> arr;
    segmentTree(int n)
    {
        st = vector<T>(4 * n);
        arr = vector<T>(n);
    }
    // BUILD TREE
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
        // LOGIC
    }
    // POINT UPDATE
    void update(int l, int r, int pos, int idx, T x)
    {
        if (r < idx || l > idx)
        {
            return;
        }
        if (l == r && l == idx)
        {
            st[pos] = arr[l] = x;
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, 2 * pos + 1, idx, x);
        update(mid + 1, r, 2 * pos + 2, idx, x);
        // LOGIC
    }
    // FIND ANSWER FOR QUERY
    T search(int l, int r, int pos, int ql, int qr)
    {
        if (l > qr || r < ql)
        {
            // RETURN THE RELEVENT STUFF
            return 0;
        }
        if (l >= ql && r <= qr)
        {
            return st[pos];
        }
        int mid = (l + r) / 2;
        // LOGIC TO SEARCH
    }
};

void solve()
{
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}