#include <bits/stdc++.h>
using namespace std;

class RUPQ
{
public:
    vector<int> arr;
    vector<int> st;
    int n;

    RUPQ(int n)
    {
        this->n = n;
        arr = vector<int>(n, 0);
        st = vector<int>(4 * n, 0);
    }
    // NOTHING TO DO HERE NOW ATLEAST
    void build()
    {
    }

    // RANGE UPDATE
    void update(int l, int r, int pos, int ql, int qr, int x)
    {
        if (l > qr || r < ql)
        {
            return;
        }
        if (l >= ql && r <= qr)
        {
            st[pos] += x;
            return;
        }
        int mid = (l + r) / 2;
        update(l, mid, 2 * pos + 1, ql, qr, x);
        update(mid + 1, r, 2 * pos + 2, ql, qr, x);
    }

    // POINT QUERY
    int search(int l, int r, int pos, int idx)
    {
        if (r < idx || l > idx)
        {
            return 0;
        }
        if (l == r && l == idx)
        {
            return st[pos];
        }
        int mid = (l + r) / 2;
        return st[pos] + search(l, mid, 2 * pos + 1, idx) + search(mid + 1, r, 2 * pos + 2, idx);
    }

    // Get INDEX
    int getIndex(int idx)
    {
        return arr[idx] + search(0, this->n, 0, idx);
    }
};