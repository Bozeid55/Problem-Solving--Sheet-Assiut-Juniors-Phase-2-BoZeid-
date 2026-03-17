// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 55 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};

vector <int> adj[N];
map <string , int> dis , vis; set <string> can;
int n , m , x , y , q; string s , tmp = "";

void bfs () {
    queue <pair <string , int>> q; q.push({tmp , 0});

    while (!q.empty()) {
        auto [a , b] = q.front(); q.pop();

        if (vis[a]) continue;

        vis[a] = 1 , dis[a] = b;
        can.insert(a);

        for (int i = 0 ; i < m ; i++) {
            string cur = a;

            for (auto k : adj[i]) cur[n - 1 - k] ^= 1;

            if (!vis[cur]) {
                q.push({cur , b + 1});
            }
        }
    }
}

void solve () {
    cin >> n >> m;

    for (int i = 0 ; i < m ; i++) {
        cin >> x;

        while (x--) {
            cin >> y;
            adj[i].push_back(y);
        }
    }

    for (int i = 0 ; i < n ; i++) tmp += '0';
    bfs();

    cin >> q;
    while (q--) {
        cin >> s; cout << (can.count(s) ? dis[s] : -1) << '\n';
    }

    for (int i = 0 ; i <= m ; i++) adj[i].clear();
    dis.clear(); vis.clear(); can.clear(); tmp = "";
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;
//    seive();
//    makee();

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);

    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        cout << "Case " << i << ":" << '\n';
        solve();
        cout << '\n';
    }

    return 0;
}
