// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 100005 , oo = INT_MIN;

int n , k;
vector <int> a , b;

ll dp[105][N];

ll rec(int idx , ll cur) {
    if (idx >= n) return (cur == 0 ? 0 : oo);


    ll &ret = dp[idx][cur];
    if (~ret) return ret;

    ret = oo;

    return ret = max({ret , rec(idx + 1 , cur + (a[idx] - (k * b[idx]))) + a[idx] , rec(idx + 1 , cur)});
}

void solve() {

    cin >> n >> k;
    a.resize(n); input(a);
    b.resize(n); input(b);

    int ans = rec(0 , 0);
    cout << (ans == 0 ? -1 : ans)  << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("smallest.in" , "r", stdin);

    int t = 1;
//    cin >> t
    for (int i = 1 ; i <= t ; i++) {
        solve();
    }
  
    return 0;
}
