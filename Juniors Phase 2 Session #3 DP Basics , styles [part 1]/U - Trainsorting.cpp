// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 2005 , W = 1e5 + 5 , oo = LLONG_MIN;

int n , dp1[N][N] , dp2[N][N];
vector <int> arr;

int rec (int idx , int cur , bool type) {
    if (idx >= n) return 0;

    int &ret = (type? dp1[idx][cur + 1] : dp2[idx][cur + 1]) ;
    if (~ret) return ret;


    ret = rec(idx + 1 , cur , type);

    if (cur == -1 || (type ? arr[idx] > arr[cur] : arr[idx] < arr[cur])) {
        ret = max(ret , rec(idx + 1 , idx , type) + 1);
    }

    return ret;
}


void solve() {
    cin >> n; arr.resize(n); input(arr);

    memset(dp1 , -1 , sizeof(dp1));
    memset(dp2 , -1 , sizeof(dp2));


    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, (rec(i + 1, i, 1) + 1) + rec(i + 1, i, 0));
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
