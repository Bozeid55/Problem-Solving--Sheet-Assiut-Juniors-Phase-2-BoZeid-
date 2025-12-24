// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e4 + 1;

int n , m;
vector <vector <int>> arr;
vector <vector <bool>> vis;
int ans = 0;

bool can (int i , int j) {
    return (i >=0 && i < n && j >=0 && j < m && !vis[i][j] && arr[i][j] == 1);
}


void rec (int i , int j) {
    if (i == n - 1 && j == m - 1) {
        ans++;
        return;
    }

    vis[i][j] = 1;

    if (can(i - 1 , j)) rec(i - 1 , j);
    if (can(i + 1 , j)) rec(i + 1 , j);
    if (can(i , j + 1)) rec(i , j + 1);
    if (can(i , j - 1)) rec(i , j - 1);

    vis[i][j] = 0;
}

void solve() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0 ; i < n ;i++) {
        arr[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    vis.resize(n);
    for (int i = 0 ; i < n ;i++) {
        vis[i].resize(m);
    }

    rec(0 , 0);

    cout << ans << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
