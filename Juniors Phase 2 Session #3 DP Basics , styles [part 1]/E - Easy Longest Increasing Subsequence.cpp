// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e3 + 1 , W = 1e5 + 5 , oo = LLONG_MIN;

int n;
vector <int> arr;
int dp[N][N];

ll rec(int idx , int cur) {
    if (idx == n) return 0;

    int &ret = dp[idx][cur + 1];
    if (~ret) return ret;

    return ret = max(((cur == -1 || arr[idx] > arr[cur]) ? rec(idx + 1 , idx) + 1 : -1) , rec(idx + 1 , cur));
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (auto &i : arr) cin >> i;


    cout << rec(0 , -1);
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
