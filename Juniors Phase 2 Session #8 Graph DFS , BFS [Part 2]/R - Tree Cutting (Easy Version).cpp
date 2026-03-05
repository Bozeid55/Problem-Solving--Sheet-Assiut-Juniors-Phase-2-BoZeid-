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

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N]; bool vis[N] , tmp[N];
vector <int> arr(N) , red(N , 0) , blue(N , 0);

int rd = 0 , bl = 0 , mx = 0;

void dfs (int node , int par) {

    for (auto i : adj[node]) {
        if (i == par) continue;

        dfs(i , node);

        red[node] += red[i];
        blue[node] += blue[i];

        mx += ((blue[i] == bl && !red[i]) || (red[i] == rd && !blue[i]));
    }

}

void solve () {
    int n , a , b; cin >> n;

    for (int i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        
        rd += (arr[i] == 1); red[i] += (arr[i] == 1);
        bl += (arr[i] == 2); blue[i] += (arr[i] == 2);
    }

    for (int i = 0 ; i < n - 1 ; i++) {
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1 , -1);

    cout << mx << '\n';
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
