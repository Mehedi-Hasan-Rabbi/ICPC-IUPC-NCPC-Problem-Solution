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
 
const int MOD = 998244353;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/

const int N = 2e5 + 10;

int fact[N], ifac[N];

int modpow(int a, int e)
{
    int r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    ifac[N - 1] = modpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
}

int nCr(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    for (char c : s)
        if (c == '1')
            ++k;

    if (k <= 1)
    {
        cout << 0 << "\n";
        return;
    }

    int ways = nCr(n, k);
    int num = (((k % MOD) * ((n - k) % MOD)) % MOD * ((k - 1) % MOD)) % MOD;
    int den = (2 * (k + 1)) % MOD;
    int invd = modpow(den, MOD - 2);
    int ans = ways * (num % MOD) % MOD * invd % MOD;
    cout << ans << "\n";
}
 
int main(void) {
    efficient();
    
    precompute();
 
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