#include <bits/stdc++.h>

using namespace std;

class segmentTree
{
public:
    vector<int> st;
    vector<int> arr;
    segmentTree(int n)
    {
        st = vector<int>(4 * n);
        arr = vector<int>(n);
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
        st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
    }
    // Add element
    void addelement(int l, int r, int pos, int x)
    {
        if (r < x || l > x)
        {
            return;
        }
        if (l == r && l == x)
        {
            st[pos] = arr[l] = 1;
            return;
        }
        int mid = (l + r) / 2;
        addelement(l, mid, 2 * pos + 1, x);
        addelement(mid + 1, r, 2 * pos + 2, x);
        // LOGIC
        st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
    }

    //Delete element
    void deleteelement(int l, int r, int pos, int x)
    {
        if (r < x || l > x)
        {
            return;
        }
        if (l == r && l == x)
        {
            st[pos] = arr[l] = 0;
            return;
        }
        int mid = (l + r) / 2;
        deleteelement(l, mid, 2 * pos + 1, x);
        deleteelement(mid + 1, r, 2 * pos + 2, x);
        // LOGIC
        st[pos] = st[2 * pos + 1] + st[2 * pos + 2];
    }
    // Search Kth smallest
    int searchKth(int l, int r, int pos, int k)
    {
        //BASE CASE
        if (l==r)
        {
            return st[pos];
        }
        int mid = (l + r) / 2;
        // LOGIC TO SEARCH MINIMUM
        if(k<=st[2*index+1])
        {
            return searchKth(l, mid, 2 * pos + 1, k);
        }
        else
        {
            return searchKth(mid, r, 2 * pos + 2, k - st[2 * pos + 1]);
        }

        //LOGIC TO SEARCH MAX
        // if (k <= st[2 * index + 2])
        // {
        //     return searchKth(l, mid, 2 * pos + 2, k);
        // }
        // else
        // {
        //     return searchKth(mid, r, 2 * pos + 1, k - st[2 * pos + 2]);
        // }
    }
};
void solve()
{
    int n;
    cin >> n;
    //PUT VALUE IN RANGE
    segmentTree k(100005);
    while(n--)
    {
        int a;
        cin >> a;
        k.arr[a]=1;
    }
    k.build(0, 100004, 0);

    //DO YOU USUAL OPERATION....
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