#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting prev_node 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

mii dp[mx];

int solve(int u, int v, int w)
{
    int ans;
    miit prev_node = dp[u].lower_bound(w);
    if (prev_node == dp[u].begin())
    {
        ans = 1;
    }
    else
    {
        prev_node--;
        ans = (*prev_node).se + 1;
    }

    bool flag = false;
    miit next_node = dp[v].upper_bound(w);
    if (next_node == dp[v].begin())
        flag = true;
    else
    {
        next_node--;
        if ((*next_node).se < ans)
            flag = true;
    }

    if (flag)
    {
        dp[v][w] = max(dp[v][w], ans);
        miit next_node = dp[v].upper_bound(w);
        while (next_node != dp[v].end())
        {
            if ((*next_node).se <= ans)
                next_node = dp[v].erase(next_node);
            else
                break;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        int val = solve(u, v, w);
        ans = max(ans, val);
    }
    cout << ans << endl;

    return 0;
}