// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 105 , W = 1e5 + 5 , oo = 1e9 - 1;

int n , m , a , b , cur = 0;
vector <int> adj[N]; bool vis[N];

void dfs (int node , int lst , bool &flag) {
    if(vis[node]) {
        flag = true; return;
    }

    vis[node] = 1; cur++;

    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it , node , flag);

        else {
            if (it == lst) continue;
            flag = true;
        }
    }
}


void solve() {
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cnt = 0;

    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            bool can = 0; cur = 0;
            dfs(i , -1 , can);

            if (can && (cur&1)) cnt++;
        }
    }

    cout << cnt + ((n - cnt)&1)  << '\n';
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
