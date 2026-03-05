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
bool flag = false , good = true;
int cnt = 0;

set <int> bad;

void dfs (int node , int par) {
    vis[node] = 1;
    if (bad.count(node)) good = false;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(i , node);
        }

        else if (par != i) {
           flag = true;
        }
    }

}

void solve () {
    int n , m , a , b; cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1 ; i <= n ; i++) {
        if (adj[i].size() > 2) {
            bad.insert(i);
        }
    }

    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            flag = false; good = true;
            dfs(i , -1);

            if (flag && good) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
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
