// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 50, W = 1e5 + 5 , oo = 1e9 + 5;

int n;
vector <vector <char>> adj(N , vector <char> (N)); bool vis[N][N]= {};

bool can (int i , int j) {
    return i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && adj[i][j] == '1';
}

void dfs (int x , int y) {
    vis[x][y] = 1;

    if (can(x + 1 , y)) dfs(x + 1 , y);
    if (can(x - 1 , y)) dfs(x - 1 , y);

    if (can(x , y + 1)) dfs(x , y + 1);
    if (can(x , y - 1)) dfs(x , y - 1);

    if (can(x + 1 , y + 1)) dfs(x + 1 , y + 1);
    if (can(x + 1 , y - 1)) dfs(x + 1 , y - 1);

    if (can(x - 1 , y + 1)) dfs(x - 1 , y + 1);
    if (can(x - 1 , y - 1)) dfs(x - 1 , y - 1);
}


void solve() {
    int cur = 1;
    
    while (cin >> n) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
               cin >> adj[i][j];
            }
        }

        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (adj[i][j] == '1' && !vis[i][j]) {
                    cnt++; dfs(i , j);
                }
            }
        }

        cout << "Image number " << cur++ << " contains " << cnt << " war eagles." << '\n';


        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                vis[i][j] = 0;
            }
        }

        for (int i = 0 ; i < N ; i++) {
            for (int j = 0 ; j < N ; j++) {
                adj[i][j] = '0';
            }
        }
    }

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
