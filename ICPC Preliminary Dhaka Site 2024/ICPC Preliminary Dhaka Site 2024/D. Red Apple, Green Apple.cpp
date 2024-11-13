#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 300000;

// Function to compute a^b % MOD
long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// Function to compute modular inverse of a number mod MOD
long long mod_inv(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

int main() {
    int n;
    cin >> n;
    vector<long long> red(n), green(n);

    // Read red apple weights
    for (int i = 0; i < n; ++i) {
        cin >> red[i];
    }

    // Read green apple weights
    for (int i = 0; i < n; ++i) {
        cin >> green[i];
    }

    long long total_weight = 0;
    for (int i = 0; i < n; ++i) {
        total_weight += (red[i] + green[i]);
        total_weight %= MOD;
    }

    total_weight = (total_weight * mod_inv(2, MOD)) % MOD;

    for (int k = 1; k <= n; ++k) {
        long long result = (total_weight * k) % MOD;
        result = (result * mod_inv(n, MOD)) % MOD;
        cout << result;
        if (k < n) cout << " ";
    }
    cout << endl;

    return 0;
}
