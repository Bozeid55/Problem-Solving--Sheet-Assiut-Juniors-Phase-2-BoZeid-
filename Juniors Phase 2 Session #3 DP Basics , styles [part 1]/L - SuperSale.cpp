// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e3 + 5 , oo = -1e18;

int n;
vector <pair<int , int>> arr;
ll dp[N][3005];

ll rec (int idx , ll cnt) {
    if (idx >= n) return 0;


    ll &ret = dp[idx][cnt];
    if (~ret) return ret;

    ll a = (cnt - arr[idx].second >= 0 ? rec(idx + 1, cnt - arr[idx].second) + arr[idx].first : oo) , b = rec(idx + 1 , cnt);


    return ret = max(a , b);
}

void solve() {
    memset(dp , -1 , sizeof(dp));

    cin >> n;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) cin >> arr[i].first >> arr[i].second;


    int k , cur; cin >> k;
    ll sum = 0;

    while(k--) {
        cin >> cur; sum += rec(0 , cur);
    }


    cout << sum << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    cin >> t;

    while (t--)
        solve();


    return 0;
}
