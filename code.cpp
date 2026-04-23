#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> a(n + 2);
    a[0] = 1;
    a[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // dp[i][j] is the maximum value from burning all cards in the range [i, j]
    // We use a 1D or 2D array. Given n=1000, n^2 is fine.
    static ll dp[1005][1005];
    // Initialize dp with 0
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            ll left_val = a[i - 1];
            ll right_val = a[j + 1];
            for (int k = i; k <= j; ++k) {
                ll current = dp[i][k - 1] + dp[k + 1][j] + left_val * a[k] * right_val;
                if (current > dp[i][j]) {
                    dp[i][j] = current;
                }
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
