// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 5005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N]; bool vis[N] , tmp[N];
bool flag = false;
int cnt = 0;

void dfs (int node) {
    if (flag) {
        tmp[node] = 1;
        cnt++;
    }
    else vis[node] = 1;

    for (auto i : adj[node]) {
        if (flag) {
            if (!vis[i] && !tmp[i]) {
                dfs(i);
            }
        }
        else {
            if (!vis[i]) {
                dfs(i);
            }
        }
    }
}

void solve () {
    int n , m , s , a , b; cin >> n >> m >> s;

    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(s);

    flag = true;

    vector <pair <int , int>> vv;
    for (int i = 1 ; i <= n ; i++) {
        if (!vis[i]) {
            cnt = 0;
            memset(tmp , 0 , sizeof(tmp));

            dfs(i); vv.push_back({cnt , i});
        }
    }

    sort(all(vv)); reverse(all(vv));
    memset(vis , 0 , sizeof(vis));

//    cout << '\n';
//    cout << '\n';
//    for (auto [a , b] : vv) {
//        cout << a << " " << b << '\n';
//    }
    flag = false;

    int ans = 0;
    for (auto [a , b] : vv) {
        if (!vis[b]) {
            dfs(b); ans++;
        }
    }

    cout << ans << '\n';
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
