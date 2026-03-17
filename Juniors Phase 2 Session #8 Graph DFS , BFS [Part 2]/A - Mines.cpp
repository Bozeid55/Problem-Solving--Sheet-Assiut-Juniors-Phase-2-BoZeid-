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

int x , y , z;

vector <int> adj[N] , fnl; bool vis[N];

void dfs (int node) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

void dfs1 (int node) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    fnl.push_back(node);
}


void solve () {
    memset(vis , 0 , sizeof(vis));

    int n; cin >> n;
    vector <array <int , 3>> arr;

    for (int i = 0 ; i < n ; i++) {
        cin >> x >> y >> z; arr.push_back({x , y , z});
    }

    sort(all(arr));

    int x1 , y1, z1;

    vector <pair <int , int>> aaaa;
    //vector <int> dep(n + 1 , 0);

    for (int i = 0 ; i < n ; i++) {
        x = arr[i][0] , y = arr[i][1] , z = arr[i][2];

        pair <int , int> aa = {x - (z / 2.0) , y - (z / 2.0)} ,
                         bb = {x + (z / 2.0) , y + (z / 2.0)} ;

        for (int j = 0 ; j < n ; j++) {
            if (i == j) continue;

            x1 = arr[j][0] , y1 = arr[j][1] , z1 = arr[j][2];

            if (x1 >= aa.first && x1 <= bb.first && y1 >= aa.second && y1 <= bb.second) {
                adj[i].push_back(j); aaaa.push_back({i , j});
                //dep[j]++;
            }
        }
    }

//    for (auto [a , b] : aaaa) {
//        cout << a << " " << b << '\n';
//    }

    for (int i = 0 ; i < n ; i++) {
        if (!vis[i]) dfs1(i);
    }

    //for (auto i : fnl) {
        //cout << i << " ";
    //}

    memset (vis , 0 , sizeof(vis));

    reverse(all(fnl));

    int cnt = 0;
    for (auto i : fnl) {
        if (!vis[i]) {
            cnt++; dfs(i);
        }
    }


    cout << cnt << '\n'; for (int i = 0 ; i < n ; i++) adj[i].clear();
    fnl.clear();
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
//        cout << "Case " << i << ": ";
        solve();
//        if (i != t) {
//            cout << '\n';
//        }
    }


    return 0;
}
