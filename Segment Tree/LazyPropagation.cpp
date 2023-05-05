#include <bits/stdc++.h>
#define int long long
using namespace std;

template <typename T>
class node
{
public:
    T max;
    T sum;
    T lazy;
    // YOU CAN USE YOU OWN PARAMETER AS PER THE QUESTION.
};
template <typename T>
class LP
{
public:
    vector<node<T>> st;
    vector<T> arr;
    LP(int n)
    {
        st = vector<node<T>>(4 * n);
        arr = vector<T>(n);
    }
    void build(int l, int r, int pos)
    {
        // BASE CASE
        if (l == r)
        {
            st[pos].max = arr[l];
            st[pos].sum = arr[l];
            st[pos].lazy = 0;
            return;
        }

        // RECURSIVE CASE
        int mid = (l + r) / 2;
        build(l, mid, 2 * pos + 1);
        build(mid + 1, r, 2 * pos + 2);

        // COMPUTE
        st[pos].max = st[2 * pos + 1].max > st[2 * pos + 2].max ? st[2 * pos + 1].max : st[2 * pos + 2].max;
        st[pos].sum = st[2 * pos + 1].sum + st[2 * pos + 2].sum;
        st[pos].lazy = 0;
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
            st[pos].sum += (r - l + 1) * x;
            st[pos].max += x;
            st[2 * pos + 1].lazy += x;
            st[2 * pos + 2].lazy += x;
            return;
        }

        // RECURSIVE AND UPDATE
        int mid = (l + r) / 2;
        update(l, mid, 2 * pos + 1, ql, qr, x);
        update(mid + 1, r, 2 * pos + 2, ql, qr, x);
        st[pos].max = st[2 * pos + 1].max > st[2 * pos + 2].max ? st[2 * pos + 1].max : st[2 * pos + 2].max;
        st[pos].sum = st[2 * pos + 1].sum + st[2 * pos + 2].sum;
    }

    // FINDING RANGE QUERY
    node<T> search(int l, int r, int pos, int ql, int qr)
    {
        if (l > qr || r < ql)
        {
            node<T> temp;
            temp.max = -(int)(1e9 + 10);
            temp.sum = 0;
            temp.lazy = 0;
            return temp;
        }
        if (l >= ql && r <= qr)
        {
            if (st[pos].lazy)
            {
                int x = st[pos].lazy;
                st[pos].sum += (r - l + 1) * x;
                st[pos].max += x;
                st[2 * pos + 1].lazy += x;
                st[2 * pos + 2].lazy += x;
                st[pos].lazy = 0;
            }

            return st[pos];
        }
        int mid = (l + r) / 2;
        node<T> n1 = search(l, mid, 2 * pos + 1, ql, qr);
        node<T> n2 = search(mid + 1, r, 2 * pos + 2, ql, qr);

        node<T> ans;
        ans.max = n1.max > n2.max ? n1.max : n2.max;
        ans.sum = n1.sum + n2.sum;
        ans.lazy = 0;
        return ans;
    }
};