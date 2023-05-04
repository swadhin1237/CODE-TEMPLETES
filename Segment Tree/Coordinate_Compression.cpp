#include <bits/stdc++.h>
#define int long long
const int mod = 1000000007;
using namespace std;
// CLASS RELATED TO CORDINATE COMPRESSION
class CMP
{
private:
    map<int, int> compVal;
    vector<int> rev;
    int count;

public:
    void add(int x)
    {
        compVal[x];
    }
    void build()
    {
        count = 0;
        compVal[-mod * mod];
        compVal[mod * mod];
        for (auto &v : compVal)
        {
            rev.push_back(v.first);
            v.second = cnt++;
        }
    }
    // Get the Compress Val
    inline int getComp(int x)
    {
        return compVal[x];
    }
    // Get the Original Val
    inline int getOriginal(int x)
    {
        return rev[x];
    }
    // get Prev
    int getPrev(int x)
    {
        auto it = compVal.upper_bound(x);
        it--;
        return it->second;
    }
    // get Next
    int getNext(int x)
    {
        auto it = compVal.lower_bound(x);
        return it->second;
    }
};
void solve()
{
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}