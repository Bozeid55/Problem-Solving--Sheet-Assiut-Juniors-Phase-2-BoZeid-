// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e2 + 5;

ll add(ll a,ll b,ll m) {
    return ((a%m)+(b%m))%m;
}

ll sub(ll a,ll b,ll m) {
    return ((a%m)-(b%m)+m)%m;
}


int n , m;
vector <vector <int>> arr;

ll dp[N][N];

bool can (int i , int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}


ll rec (int i , int j) {
    if (!can(i , j)) return 0;
    if (i == n - 1 && j == m - 1) return arr[i][j];


    ll &ret = dp[i][j];
    if (~ret) return ret;


    return ret = max({rec(i + 1 , j) + arr[i][j] , rec(i + 1 , j - 1) + arr[i][j] , rec(i + 1 , j + 1) + arr[i][j]});
}

void solve() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    ll mx = 0;
    for (int i = 0 ; i < m ; i++) {
        mx = max(mx , rec(0 , i));
    }

    cout << mx << '\n';

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
