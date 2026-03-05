// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 2e5 + 5 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N]; bool vis[N] , tmp[N];

int cur = 0;

void dfs (int node , int par , int cnt) {
    if (cnt <= 2) vis[node] = 1;

    bool bad = false;

    for (auto i : adj[node]) {
        if (i == par) continue;

        dfs(i , node , cnt + 1);
        if (!vis[i]) bad = true;
    }

    if (bad) {
        for (auto i : adj[node]) vis[i] = 1;
        vis[node] = 1; cur++;
    }
}

void solve () {
    int n , a , b; cin >> n;

    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , -1 , 0);

    cout << cur << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);

    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
