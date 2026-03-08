// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 10005 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};


vector <int> adj[N] , primes; int dis[N]; bool vis[N];

void seive () {
    vector <int> ck(N + 5 , 1);

    for (ll i = 2 ; i * i <= N ; i++) {
        if (ck[i]) {
            for (ll j = i * i ; j <= N ; j += i) {
                ck[j] = 0;
            }
        }
    }

    for (int i = 2 ; i <= N ; i++) {
        if (ck[i]) primes.push_back(i);
    }
}

bool can (int a , int b) {
    int cur = 0;

    while (a > 0 && b > 0) {
        if ((a % 10) != (b % 10)) cur++;
        a /= 10 , b /= 10;
    }

    return (cur == 1);
}

void makee () {
    for (int i = 0 ; i < primes.size() ; i++) {
        for (int j = i + 1 ; j < primes.size() ; j++) {
            if (primes[i] >= 1000 && primes[i] <= 9999 && primes[j] >= 1000 && primes[j] <= 9999) {
                if (can(primes[i] , primes[j])) {
                    adj[primes[i]].push_back(primes[j]);
                    adj[primes[j]].push_back(primes[i]);
                }
            }
        }
    }
}

void bfs (int node) {
    queue <int> q; q.push(node);
    vis[node] = 1; dis[node] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (auto i : adj[cur]) {
            if (!vis[i]) {
                vis[i] = 1; dis[i] = dis[cur] + 1; q.push(i);
            }
        }
    }
}


void solve () {
    memset(dis , -1 , sizeof(dis));
    memset(vis , 0 , sizeof(vis));

    int a , b; cin >> a >> b;
    bfs(a);

    if (dis[b] >= 0) cout << dis[b] << '\n';
    else cout << "Impossible" << '\n';
}

int main() {
    ABo_ZeiD; // i'm backkkkkk;
    seive();
    makee();

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
