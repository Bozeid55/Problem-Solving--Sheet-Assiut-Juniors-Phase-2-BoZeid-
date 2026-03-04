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

int dX[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N]; bool vis[N];
vector <int> col;

bool flag = true;

void dfs (int node) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            col[i] = 1 - col[node];
            dfs(i);
        }

        else if (col[i] == col[node]) {
            flag = false; return;
        }
    }
}

void solve () {
    int n , m , a , b , tm; cin >> n >> m; tm = m;

    vector <int> fnl;

    while (m--) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

        fnl.push_back(a);
    }

    col.resize(n + 1);

    dfs(1);

    if (!flag) {
        cout << "NO" << '\n'; return;
    }

    cout << "YES" << '\n';

    for (int i = 0 ; i < tm ; i++) {
        cout << (col[fnl[i]] ? '0' : '1');
    }

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
