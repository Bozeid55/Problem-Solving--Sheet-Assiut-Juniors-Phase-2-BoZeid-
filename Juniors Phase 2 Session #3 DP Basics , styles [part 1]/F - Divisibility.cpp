// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e4 + 5;

ll add(ll a,ll b,ll m) {
    return ((a%m)+(b%m))%m;
}

ll sub(ll a,ll b,ll m) {
    return ((a%m)-(b%m)+m)%m;
}


int n; ll trg;
vector <ll> arr;

ll dp[N][105];

bool rec (int idx , ll cur) {
    if (idx >= n) return cur == 0;


    ll &ret = dp[idx][cur];
    if (~ret) return ret;



    return ret = (rec(idx + 1 , add(cur , arr[idx] , trg) ) || rec(idx + 1 , sub(cur , arr[idx] , trg)));
}

void solve() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> trg;
    arr.resize(n); input(arr);

    cout << (rec(1 , arr[0] % trg)? "Divisible" : "Not divisible") << '\n';


    arr.clear();
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
