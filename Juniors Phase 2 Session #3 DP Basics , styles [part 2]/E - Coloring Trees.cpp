// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 105 , W = 1e5 + 5 , oo = 1e18;

int n , m , k;
vector <int> arr;
vector <vector <ll>> col;

ll dp[N][N][N];

ll rec (int idx , int lst , int cnt) {
    if (cnt > k) return oo;
    if (idx >= n) return (cnt != k ? oo : 0);


    ll &ret = dp[idx][lst][cnt];
    if (~ret) return ret;

    ret = oo;

    if (arr[idx] > 0) {
        ret = min(ret , rec(idx + 1 , arr[idx] , cnt + (idx == 0 ? 1 : (lst != arr[idx]))));
    }

    else {
        for (int cur = 1 ; cur <= m ; cur++) {
            ret = min(ret , rec(idx + 1 , cur , cnt + (idx == 0 ? 1 : (lst != cur))) + col[idx][cur]);
        }
    }

    return ret;
}


void solve() {
    cin >> n >> m >> k;
    arr.resize(n); input(arr);

    col.resize(n);
    for (int i = 0 ; i < n ; i++) {
        col[i].resize(m + 1);

        for (int j = 1 ; j <= m ; j++) {
            cin >> col[i][j];
        }
    }

    ll ans = rec(0 , 0 , 0);
    cout << (ans >= oo ? -1 : ans) << '\n';
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
