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
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = "#" + s;

    map<int, set<int>> freq;
    for (int i = 1; i <= n; i++)
        freq[s[i]].insert(i);
    
    while (q--) {
        char ch; cin >> ch;

        int idx = INT32_MAX;
        for (char c = 'a'; c < ch; c++) {
            if (freq[c].size() != 0)
                idx = min(idx, *freq[c].begin());
        }

        if (idx != INT32_MAX) {
            for (char c = 'a'; c < ch; c++) {
                if (freq[c].size() != 0 and *freq[c].begin() == idx) {
                    cout << idx << endl;
                    freq[ch].insert(idx);
                    freq[c].erase(idx);
                    break;
                }
            }
        }
        else if (idx == INT32_MAX and freq[ch].size() > 0) {
            idx = *freq[ch].begin();
            cout << idx << endl;
        }
        else {
            cout << n << endl;
            for (char c = ch; c <= 'z'; c++) {
                if (freq[c].size() != 0 and *freq[c].rbegin() == n) {
                    freq[ch].insert(n);
                    freq[c].erase(n);
                    break;
                }
            }
        }
        
    }
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