// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , oo = LLONG_MAX;

int n;
vector <ll> a , b;

ll dp[N][2];
ll rec (int idx , int flag) {
    if (idx == n - 1) return 1;
    if (idx >= n) return 0;


    ll &ret = dp[idx][flag];
    if (~ret) return ret;


    ll lv = rec(idx + 1 , 0) , tk = 0;

    if (idx == 0) tk = max(tk , rec(idx + 1 , 0) + 1);

    if ((!flag && (a[idx] - b[idx] > a[idx - 1])) || ((a[idx] - b[idx]) > (a[idx - 1] + b[idx - 1]))) {
        tk = max(tk , rec(idx + 1 , 0) + 1);
    }

    if (a[idx] + b[idx] < a[idx + 1]) {
        tk = max(tk , rec(idx + 1 , 1) + 1);
    }

    return ret = max(tk , lv);
}

void solve() {
    cin >> n;
    a.resize(n); b.resize(n);

    for (int i = 0 ; i < n ; i++) cin >> a[i] >> b[i];


    cout << rec(0 , 0) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
