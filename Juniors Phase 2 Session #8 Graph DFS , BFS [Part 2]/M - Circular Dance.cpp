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


vector <int> adj[N]; bool vis[N];
vector <int> ans;

void dfs (int cur) {
    vis[cur] = 1;

    if (!vis[adj[cur][0]] && (adj[adj[cur][0]][0] == adj[cur][1] || adj[adj[cur][0]][1] == adj[cur][1])) {
        ans.push_back(adj[cur][0]);
        dfs(adj[cur][0]);
    }
    else if (!vis[adj[cur][1]]) {
        ans.push_back(adj[cur][1]);
        dfs(adj[cur][1]);
    }
}


void solve () {
    int n , x , y; cin >> n;

    for (int i = 1 ; i <= n ; i++) {
        cin >> x >> y;

        adj[i].push_back(x);
        adj[i].push_back(y);
    }

    ans.push_back(1);
    dfs(1);

    for (auto i : ans) cout << i << " ";
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);
//    pre();

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
