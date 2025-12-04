// In the name of Allah, the merciful.
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#ifndef ONLINE_JUDGE
#include "algo/Debug.h"
#else
#define dbg(...)
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // *X.find_by_order(n), X.order_of_key(n), *X.lower_bound(n), *X.upper_bound(n), X.erase(n)
// less<int> -> Ascending || greater<int> -> Descending || less_equal<int> -> Ascending Multiset || greater_equal<int> -> Descending Multiset
 
#define endl               '\n'
#define efficient()        ios_base::sync_with_stdio(0); cin.tie(0);
#define fraction()         cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
 
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return abs(a) * ( abs(b) / gcd ( a, b ) ); }
 
int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};
 
const ll mod = 1e9 + 7; // 1000000007;
const double PI = 3.14159265358979323846;
const double eps = 1e-9; // if (abs(a-b) < 1e-9) {a and b are equal}
 
/*---------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    ll n, m; cin >> n >> m;

    // Base Case: Odd number
    if (m % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    ll ans = 0, total = 0;
    for (ll floor = 1; floor <= 63; floor++) {
        ll room_cost = (1LL << floor);                  // Current floor single room cost
        ll full_floor_cost = room_cost * n;             // Current floor all room cost

        // If we can take all rooms, then take it.
        if (total + full_floor_cost <= m) {
            ans += n;
            total = total + full_floor_cost;
        }
        else {
            ll remaining = m - total;                   // How much money we have
            ll room = remaining / room_cost;            // How much room we can take with that money
            ans += room;
            
            remaining = remaining - (room * room_cost); // After buying room check remaning money

            // If we have remaning money then we need to leave some lower cost room to to adjust
            // money and take a room in current floor.
            // e.g. Currently at Floor = 4, remaining = 10. Then we can leave a room from 1st floor (cost: 2) and 
            // another from floor 2 (cost: 4)and 
            // add it with the reaming 10 to get 16 and take a room in floor 4.
            // We can simple do that by fining set bits in 6 = 1 1 0
            if ( (remaining % room_cost) != 0 ) {
                ll need = room_cost - remaining;

                int set_bit = 0;
                for (ll bit = 0; bit < 64; bit++) {
                    if (need & (1LL << bit))
                        set_bit++;
                }

                ans = ans - set_bit + 1;
            }
            break;
        }
    }

    cout << ans << endl;
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