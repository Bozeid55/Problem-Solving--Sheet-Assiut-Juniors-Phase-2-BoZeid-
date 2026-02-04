// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define inputz(vec , x) for (int i = 0 ; i < x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e4 + 5, oo = 1e18 + 1;


void solve() {
    int n; cin >> n;
    vector <int> arr(n) , tmp, dp(n + 5 , 1); input(arr);

    //tl3t LIS eassyyy just o(n log n)
    for (int i = 0 ; i < n ; i++) {
        auto it = upper_bound(all(tmp) , arr[i]);

        if (it != tmp.end()) *it = arr[i];
        else tmp.push_back(arr[i]);


        dp[i] = tmp.size();
    }

    cout << *max_element(all(dp)); // ezz
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkkk
//    memset(dp , -1 , sizeof(dp));

    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
    }


    return 0;
}
