// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 5005 , oo = LLONG_MIN;

string s; int n;
ll dp[N][N];

ll rec(int l , int r) {
    if (l > r) return 0;

    ll &ret = dp[l][r];
    if (~ret) return ret;


    return ret = min({(s[l] == s[r] ? rec(l + 1 , r - 1) : rec(l + 1 , r - 1) + 1) , rec(l + 1 , r) + 1 , rec(l , r - 1) + 1});
}

void solve() {
    memset(dp , -1 , sizeof(dp));
    cin >> s; n = s.length();

    cout << rec(0 , n - 1) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    //freopen("smallest.in" , "r", stdin);


    int t; cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
