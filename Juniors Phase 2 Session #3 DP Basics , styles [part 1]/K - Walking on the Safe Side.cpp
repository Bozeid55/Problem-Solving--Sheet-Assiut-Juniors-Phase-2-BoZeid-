// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e3 + 5;

ll n , m;
vector <vector <bool>> arr;

ll dp[N][N];

ll rec (int i , int j) {
    if (i > n || j > m || !arr[i][j]) return 0;
    if ((i == n) && (j == m)) return 1;

    ll &ret = dp[i][j];
    if (~ret) return ret;


    return ret = rec(i + 1 , j) + rec(i , j + 1);
}

void solve() {
    memset(dp , -1 , sizeof(dp));

    string s; getline(cin , s);

    cin >> n >> m; cin.ignore();
    arr.resize(n + 1);
    for (int i= 0 ; i <= n  ; i++) {
        arr[i].resize(m + 1);
        for (int j = 0 ; j <= m ; j++) arr[i][j] = 1;
    }

    for (int i = 0 ; i < n ; i++) {
        string x; getline(cin , x);

        if (!x.empty()) {
            stringstream gt(x);
            int a , b; gt >> a;

            while (gt >> b) {
                arr[a][b] = 0;
            }
        }

        //cout << '\n';
    }



    cout << rec(1 , 1) << '\n';

}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1; cin >> t;
    
    for (int i = 1; i <= t ; i++) {
        solve();

        if(i != t) cout << '\n';
    }



    return 0;
}
