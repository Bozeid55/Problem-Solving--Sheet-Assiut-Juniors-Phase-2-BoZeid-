/*  AtCoder dp_c : https://atcoder.jp/contests/dp/tasks/dp_c?lang=en */
// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e5+ 1;

int n;
vector <vector <int>> arr;
ll dp[N][3];

ll rec (int idx , int cur) {
    if (idx >= n) return 0;


    ll &ret = dp[idx][cur];
    if (~ret) return ret;



    for (int i = 0 ; i < 3 ; i++) {
        if (i != cur) {
            dp[idx][cur] = max(dp[idx][cur] , rec(idx + 1 , i) + arr[idx][cur]);
        }
    }


    return ret;
}


void solve() {
    cin >> n;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(3);

        for (int j = 0 ; j < 3 ; j++) {
            cin >> arr[i][j];
        }
    }


    cout << max({rec(0 , 0) , rec(0 , 1) , rec(0 , 2)}) << '\n';
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
