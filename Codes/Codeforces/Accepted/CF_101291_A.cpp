/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

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
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

string alpha, str;
int dp[30][60], m, n;

int lcs(int i, int j)
{
    if (i == m || j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (alpha[i] == str[j])
        return dp[i][j] = 1 + lcs(i + 1, j + 1);
    else
        return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    alpha = "abcdefghijklmnopqrstuvwxyz";
    cin >> str;
    n = str.size();
    m = 26;
    memset(dp, -1, sizeof(dp));
    int ans = 26 - lcs(0, 0);
    cout << ans << endl;

    return 0;
}
