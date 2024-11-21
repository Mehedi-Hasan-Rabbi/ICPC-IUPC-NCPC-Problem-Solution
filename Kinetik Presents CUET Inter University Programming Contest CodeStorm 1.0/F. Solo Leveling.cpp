// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }
 
int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
        ll n, p, x, a;
    cin >> n >> p >> x >> a;

    p += x;

    vector <ll> v(n + 1, 0), pre(n + 3, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll big_sum = 0;

    for (int i = 1; i <= a; i++) {
        pq.push(v[i]);
        big_sum += v[i];
    }

    ll ans = a;

    for (int i = a + 1; i <= n; i++) {
        if (!pq.empty()) {
            if (v[i] > pq.top()) {
                ll x = pq.top(); pq.pop();
                big_sum -= x;
                big_sum += v[i];
                pq.push(v[i]);
            }
        }

        ll need_p = pre[i] - big_sum;
        if (need_p <= p) {
            ans++;
        }
        else {
            break;
        }
    }

    cout << ans << '\n';
}
 
int main(void) {
    // efficient();
 
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
 
    return 0;
    // Every problem has its weakness.
    // This problem's weakness is...the existence of me!
}