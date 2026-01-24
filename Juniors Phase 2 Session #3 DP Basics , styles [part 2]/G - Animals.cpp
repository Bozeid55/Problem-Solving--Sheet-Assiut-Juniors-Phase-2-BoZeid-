// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 105 , W = 1e4 + 5, oo = LLONG_MIN;

int n , x;
vector <int> arr;
ll dp[N][W];

ll rec (int idx , int cnt) {
    if (cnt < 0) return oo;
    if (idx >= n) return (cnt < 0 ? oo : 0);

    ll &ret = dp[idx][cnt];
    if (~ret) return ret;

    ret = oo;
    ret = max(ret , rec(idx + 1 , cnt));
    ret = max(ret , rec(idx + 1 , cnt - (arr[idx] * (n - idx))) + 1);

    return ret;
}

void solve() {
    cin >> n >> x;
    arr.resize(n); input(arr);


    cout << rec(0 , x) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("input.txt" , "r", stdin);
    //freopen("output.txt" , "w", stdout);


    int t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}
