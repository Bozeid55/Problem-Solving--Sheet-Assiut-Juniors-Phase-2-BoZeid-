// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1005 , oo = 1e9;

int n , m , x , y;
vector <vector <char>> arr;
ll a[N] = {0} , b[N] = {0};

int dp[N][N][2];

int rec(int idx , int sum , int cur) {
    if (idx >= m) return (sum >= x && sum <= y ? 0 : oo);


    int &ret = dp[idx][sum][cur];
    if (~ret) return ret;

    ret = oo;

    if (sum < x) ret = rec(idx + 1 , sum + 1 , cur) + (cur ? b[idx] : a[idx]);
    else if (sum >= x && sum < y) {
        ret = min(rec(idx + 1 , sum + 1 , cur) + (cur ? b[idx] : a[idx]) , rec(idx + 1 , 1 , (cur ? 0 : 1)) + (cur ? a[idx] : b[idx]));
    }
    else ret = rec(idx + 1 , 1  , (cur ? 0 : 1)) + (cur ? a[idx] : b[idx]);


    return ret;
}

void solve() {
    cin >> n >> m >> x >> y;
    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '#') a[j]++;
            else b[j]++;
        }
    }


    cout <<  min(rec(0 , 0 , 0) , rec(0 , 0 , 1))  << '\n';
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
