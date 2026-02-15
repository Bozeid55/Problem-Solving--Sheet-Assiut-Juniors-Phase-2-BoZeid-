// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 15 , w = 1e6 + 5 , oo = 1e9 + 7;

vector <int> adj[N]; bool vis[N][N];
int stx , sty , edx , edy;

bool can (int x , int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8 && !vis[x][y];
}

int bfs (int l , int r) {
    queue <pair <int , int>> q;
    queue <int> ans;


    q.push({l , r}); ans.push(0); vis[l][r] = 1;

    while (!q.empty()) {
        auto [x , y] = q.front(); q.pop();
        int cur = ans.front(); ans.pop();

        if (x == edx && y == edy) return cur;


        /*----------------------------------------*/
        if (can(x - 2 , y - 1)) {
            q.push({x - 2 , y - 1}); vis[x - 2][y - 1] = 1; ans.push(cur + 1);
        }

        if (can(x - 2 , y + 1)) {
            q.push({x - 2 , y + 1}); vis[x - 2][y + 1] = 1; ans.push(cur + 1);
        }

        if (can(x + 1 , y - 2)) {
            q.push({x + 1 , y - 2}); vis[x + 1][y - 2] = 1; ans.push(cur + 1);
        }

        if (can(x - 1 , y - 2)) {
            q.push({x - 1 , y - 2}); vis[x - 1][y - 2] = 1; ans.push(cur + 1);
        }
        /*----------------------------------------*/
        if (can(x + 1, y + 2)) {
            q.push({x + 1 , y + 2}); vis[x + 1][y + 2] = 1; ans.push(cur + 1);
        }

        if (can(x - 1, y + 2)) {
            q.push({x - 1 , y + 2}); vis[x - 1][y + 2] = 1; ans.push(cur + 1);
        }

        if (can(x + 2 , y + 1)) {
            q.push({x + 2 , y + 1}); vis[x + 2][y + 1] = 1; ans.push(cur + 1);
        }

        if (can(x + 2 , y - 1)) {
            q.push({x + 2 , y - 1}); vis[x + 2][y - 1] = 1; ans.push(cur + 1);
        }
        /*----------------------------------------*/
    }

}


void solve() {
    string a;

    while(getline(cin , a)) {
        if (a == "") break;

        stx = (a[0] - 'a' + 1) , sty = (a[1] - '0') ,
        edx = (a[3] - 'a' + 1) , edy = (a[4] - '0');


        cout << "To get from " << a[0] << a[1] << " to " << a[3] << a[4] << " takes " << (bfs(stx , sty)) << " knight moves." << '\n';

        memset(vis , 0 , sizeof(vis));
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
