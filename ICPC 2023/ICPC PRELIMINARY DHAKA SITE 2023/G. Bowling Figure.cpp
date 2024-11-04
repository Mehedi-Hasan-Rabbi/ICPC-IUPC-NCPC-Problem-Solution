// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define endl               '\n'
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define show(x)            cout << #x << " : " << x << endl
#define showtwo(x, y)      cout << #x << " : " << x << " " << #y << " : " << y << endl
#define all(a)             a.begin(),a.end()
#define pb                 push_back
#define pf                 push_front
#define mp                 make_pair
#define ff                 first
#define ss                 second
#define input_arr(vec)     for(auto &&it:vec) {cin >> it;}
#define display_arr(vec)   for (auto &&it : vec){cout << it << " ";} cout << endl;
#define files              freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);

/*---------------------------------------------------------------------------------------------------------------*/

void solve()
{
    string s; cin >> s;

    int len = s.size(), first, second;

    first = len / 6;
    second = len % 6;

    int run = 0, wicket = 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i]!='W') {
            run += (s[i] - '0');
        }
        else {
            wicket++;
        }
    }
    if(first == 0) cout << first << "." << second << " Over ";
    else if(first == 1 && second == 0) cout << first << "." << second <<" Over ";
    else if(first >= 1) cout << first << "." << second << " Overs ";

    if(run == 0 || run == 1) cout << run <<" Run ";
    if(run >= 2) cout << run << " Runs ";

    if(wicket == 0 || wicket == 1) cout << wicket << " Wicket.\n";
    if(wicket >= 2) cout << wicket << " Wickets.\n";
}

int main(void)
{
    efficient();

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}
