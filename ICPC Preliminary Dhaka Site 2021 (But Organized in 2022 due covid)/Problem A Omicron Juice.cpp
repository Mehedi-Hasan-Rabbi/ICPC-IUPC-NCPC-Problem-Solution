#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define show(x) cout << #x << " : " << x << endl
#define files freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define efficient ios::sync_with_stdio(0); cin.tie(0);


int main(void)
{
    //efficient;

    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int sum = a+b+c;

        if (sum%3 ==0)
        {
            cout << "Case " << i << ": Peaceful" << '\n';

        }
        else
            cout << "Case " << i << ": Fight" << '\n';

    }
    return 0;
}

