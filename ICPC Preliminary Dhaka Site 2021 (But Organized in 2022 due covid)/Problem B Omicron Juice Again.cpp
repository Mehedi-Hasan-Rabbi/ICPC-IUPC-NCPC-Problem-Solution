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
    efficient;

    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        vector<int> arr(3);
        for(int j=0; j<3; j++)
            cin>>arr[j];
        int k;
        cin >> k;

        sort(arr.begin(), arr.end());

        set<int> uni(arr.begin(), arr.end());

        if(uni.size()==1)
        {
            cout << "Case " << i << ": Peaceful" << '\n';
            continue;
        }

        while(true)
        {
            arr[2] -= k;
            arr[0] += k;
            if(arr[0] > arr[2])
            {
                cout << "Case " << i << ": Fight" << '\n';
                break;
            }

            sort(arr.begin(), arr.end());
            set<int> uni(arr.begin(), arr.end());

            if(uni.size()==1)
            {
                cout << "Case " << i << ": Peaceful" << '\n';
                break;
            }
        }
    }
    return 0;
}

