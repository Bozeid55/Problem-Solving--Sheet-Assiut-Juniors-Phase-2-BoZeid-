// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e5 + 5;

int n;
vector <ll> arr;
map <ll , ll> mp;

ll dp[N];

ll rec (int idx) {
    if (idx >= N) return 0; // damn end if >= max value -> [1e5] not size of arr -> [n]

    ll &ret = dp[idx];
    if (~ret) return ret;


    return ret = max(rec(idx + 1) , rec(idx + 2) + mp[idx] * idx);
}

void solve() {
    cin >> n; arr.resize(n);

    for (auto &i : arr) {
        cin >> i; mp[i]++;
    }

    cout << rec(0) << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk
    memset(dp , -1 , sizeof(dp));

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    //cin >> t;
    while (t--)
        solve();


    return 0;
}
