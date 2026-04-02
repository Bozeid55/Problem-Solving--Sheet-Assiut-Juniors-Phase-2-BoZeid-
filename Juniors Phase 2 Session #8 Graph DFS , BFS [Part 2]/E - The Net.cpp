// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 305 , w = 1e6 + 5 , oo = 1e4;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};

vector <int> adj[N];

void bfs (int a , int b) {
    bool vis[N]; vector <int> rod(N , -1);
    memset(vis , 0 , sizeof(vis));

    queue <int> q; q.push(a); vis[a] = 1;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        if (cur == b) {
            vector <int> ans;

            ans.push_back(b); int x = rod[b];
            while (x != -1) {
                ans.push_back(x); x = rod[x];
            }

            for (int i = ans.size() - 1 ; i >= 0 ; i--) {
                cout << ans[i];
                if (i) cout << " ";
            }
            cout << '\n';
            return;
        }

        for (auto i : adj[cur]) {
            if (!vis[i]) {
                vis[i] = 1; q.push(i); rod[i] = cur;
            }
        }
    }

    cout << "connection impossible" << '\n';
}

void solve () {
    int n;
    while (cin >> n) {
        int m , a , b;
        string s;

        for (int i = 0 ; i < n ; i++) {
            cin >> s;
            for (auto &j : s) if (j == ',' || j == '-') j = ' ';

            stringstream cn(s); cn >> a;
            while (cn >> b) adj[a].push_back(b);

            sort(all(adj[a]));
        }

        cin >> m;

        vector <pair <int , int>> tmp;
        for (int i = 0 ; i < m ; i++) {
            cin >> a >> b; tmp.push_back({a , b});
        }

        cout << "-----" << '\n';
        for (auto [x , y] : tmp) bfs(x , y);

        for (int i = 1 ; i <= n ; i++) {
            adj[i].clear();
        }
    }
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;
//    seive();
//    makee();

//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);

    int t = 1;
//    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        solve();
        //cout << '\n';
//        if (i == t) cout << '\n';
    }


    return 0;
}
