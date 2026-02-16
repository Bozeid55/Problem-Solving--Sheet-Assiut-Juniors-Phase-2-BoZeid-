// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 3e5 + 5 , w = 1e6 + 5 , oo = 1e9;
int dx[] = {1 , 1 , 1 , -1 , -1 , -1 , 0 , 0} ,
    dy[] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 1};


map <pair <int , int> , bool> adj , vis;

bool can (int x , int y) {
    return x >=0 && x <= oo && y >= 0 && y <= oo && adj[{x , y}] && !vis[{x , y}];
}

int x2 , y2 , anss = 0;

void bfs (int l , int r) {
    queue <pair <int , int>> q;
    queue <int> cnt;

    q.push({l , r}); cnt.push(0);  vis[{l , r}] = 1;

    while (!q.empty()) {
        auto [a , b] = q.front(); q.pop();
        int ans = cnt.front(); cnt.pop();


        if (a == x2 && b == y2) {
            vis[{a , b}] = 1; anss = ans; return;
        }


        for (int i = 0 ; i < 8 ; i++) {
            int x = a + dx[i] , y = b + dy[i];

            if (can(x , y)) {
                q.push({x , y}); cnt.push(ans + 1); vis[{x , y}] = 1;
            }
        }
    }
}



void solve () {
    int x1 , y1 , n , r , a , b;
    cin >> x1 >> y1 >> x2 >> y2;

    cin >> n;
    for (int i = 0; i < n ; i++) {
        cin >> r >> a >> b;

        for (int j = a ; j <= b ; j++) {
            adj[{r , j}] = 1; vis[{r , j}] = 0;
        }
    }

    bfs(x1 , y1);

    if (vis[{x2 , y2}]) {
        cout << anss << '\n'; return;
    }

    cout << -1 << '\n';
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
