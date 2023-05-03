#include<bits/stdc++.h>
using namespace std;
const int SIZE = 100005;
int st[4 * SIZE];
int arr[SIZE];

void build(int l,int r,int pos)
{
    if(l==r)
    {
        st[pos] = arr[l];
    }
    build(l, mid, 2 * pos + 1);
    build(mid + 1, r, 2 * pos + 2);

    //LOGIC
    
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}