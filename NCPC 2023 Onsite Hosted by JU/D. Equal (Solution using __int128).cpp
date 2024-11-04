// In the name of Allah the merciful.
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

const ll MOD = 1e9 + 7; // 1000000007;
const double PI = acos(-1);
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}

/*---------------------------------------------------------------------------------------------------------------*/

// Function to read __int128 from standard input
istream &operator>>(istream &in, __int128 &num) {
    string s;
    in >> s;
    num = 0;
    bool negative = (s[0] == '-');
    for (int i = negative ? 1 : 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    if (negative) num = -num;
    return in;
}

// Function to print __int128 to standard output
ostream &operator<<(ostream &out, __int128 num) {
    if (num == 0) return out << "0";
    if (num < 0) {
        out << '-';
        num = -num;
    }
    string s;
    while (num > 0) {
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}

void solve() {
    __int128 a, b, c, d;
    cin >> a >> b >> c >> d;

    // Check if a * d == b * c using __int128
    __int128 left = a * d;
    __int128 right = b * c;

    cout << ((left == right) ? "Equal" : "Not Equal") << '\n';
}

int main(void) {
    efficient();

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