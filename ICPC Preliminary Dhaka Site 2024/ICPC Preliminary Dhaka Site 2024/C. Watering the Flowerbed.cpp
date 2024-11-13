#include <bits/stdc++.h>
using namespace std;


void solve(void)
{
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        res += (k / x);
    }
    cout << res << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, Test;
    cin >> t;
    for (Test = 1; Test <= t; Test++)
    {
        cout << "Case " << Test << ": ";
        solve();
    }
    return 0;
}
