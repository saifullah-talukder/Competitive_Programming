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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int fx[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};

int count_good(int idx, vi &ara, int len = 4)
{
    int res = 0;
    bool good = true;

    for (int i = 0; i < 4; i++)
    {
        if (ara[idx + fx[i][0]] <= ara[idx + fx[i][1]] && ara[idx + fx[i][1]] <= ara[idx + fx[i][2]])
            good = false;
        else if (ara[idx + fx[i][0]] >= ara[idx + fx[i][1]] && ara[idx + fx[i][1]] >= ara[idx + fx[i][2]])
            good = false;

        if (i == 0 && good)
            res += 1;

        if (len != 4)
            return res;

        if (!good)
            break;
    }

    if (good)
        res += 1;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vi ara(n);
        for (int i = 0; i < n; i++)
            cin >> ara[i];

        int ans = 0;
        for (int i = 3; i < n; i++)
            ans += count_good(i - 3, ara);
        if (n >= 3)
            ans += count_good(n - 3, ara, 3);

        ans += 2 * n - 1;

        cout << ans << '\n';
    }

    return 0;
}