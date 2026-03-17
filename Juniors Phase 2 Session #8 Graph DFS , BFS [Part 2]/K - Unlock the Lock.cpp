// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e4 + 5 , w = 1e6 + 5 , oo = 1e4;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};

vector <ll> adj[N];
bool vis[N];
int l , u , r , x;

void solve () {
    int cnt = 1;

    while (cin >> l >> u >> r) {
        if (!l && !u && !r) return;
        vector <int> arr(r) , dis(N + 5 , -1);

        for (int i = 0 ; i < r ; i++) cin >> arr[i];

        auto bfs = [&] () -> void {
            queue <int> q; q.push(l);
            vis[l] = 1 , dis[l] = 0;

            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                if (cur == u) return;

                for (auto i : arr) {
                    if (dis[((i + cur) % oo)] == -1) {
                        q.push(((i + cur) % oo)); dis[((i + cur) % oo)] = dis[cur] + 1;
                    }
                }
            }
        };

        bfs();

        cout << "Case " << cnt++ << ": ";
        if (dis[u] == -1) {
            cout << "Permanently Locked" << '\n'; continue;
        }

        cout << dis[u] << '\n';
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
//        if (i == t) cout << '\n';
    }

    return 0;
}
