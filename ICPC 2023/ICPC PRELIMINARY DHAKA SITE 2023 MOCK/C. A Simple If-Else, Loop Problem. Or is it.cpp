// In the name of Allah the merciful.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define show(x) cout << #x << " : " << x << endl
#define showtwo(x, y) cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a) a.begin(), a.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define input_arr(vec)    \
    for (auto &&it : vec) \
    {                     \
        cin >> it;        \
    }
#define display_arr(vec)   \
    for (auto &&it : vec)  \
    {                      \
        cout << it << " "; \
    }                      \
    cout << endl;
#define files                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define efficient()               \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
ll lcm(ll a, ll b) { return abs(a) * (abs(b) / gcd(a, b)); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;
    vll a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(all(a));

    ll tot_pair = (((n - 1) * ((n - 1) + 1)) / 2);

    ll l = 1, r = n;
    ll count_y = 0;
    while (l < r)
    {
        ll sum = a[l] + a[r];

        if (sum > y)
            r--;
        else
        {
            count_y += r - l;
            l++;
        }
    }

    l = 1, r = n;
    ll above_x = 0;
    while (l <= r)
    {
        ll sum = a[l] + a[r];

        if (sum < x)
        {
            above_x += n - r;
            l++;
        }
        else
            r--;
        if (l == r)
        {
            ll test = n - r;
            ll left = ((test * (test + 1)) / 2);
            above_x += left;
            break;
        }
    }
    ll ans = count_y - (tot_pair - above_x);
    cout << ans << endl;
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
