#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
int n , k;
vector<int> arr; ll dp[N];

ll solve(int i) {
    if (i == n - 1) return 0;
    if (dp[i] != -1) return dp[i];

    dp[i] = INT_MAX;

    for (int j = 1; j <= k ; j++) {
        if (i + j <= n - 1) {
            dp[i] = min(dp[i], solve(i + j) + abs(arr[i + j] - arr[i]));
        }
    }
    return dp[i];
}

int main() {
    cin >> n >> k;
    arr.resize(n);
    memset(dp , -1 ,  sizeof(dp));

    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << solve(0) << endl;
    return 0;
}
