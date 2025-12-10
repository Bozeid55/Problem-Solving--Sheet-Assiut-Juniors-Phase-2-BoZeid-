// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000000007;
int dx[]= {-1 , 1 , 0 , 0 , 1 , -1 , 1, -1} ,
    dy[]= {0 , 0 , 1 , -1 , 1 , -1 , -1 ,1};

int n , m , x , y , cnt = 0;
vector <vector <char>> arr;
vector <vector <bool>> vis;


bool can (int i , int j) {
    return i >= 0 && i < n && j >=0 && j < m && arr[i][j] != '*' && !vis[i][j];
}


void rec (int a , int b) {
    if (a < 0 || a >= n || b >= m || b < 0) return;
    
    vis[a][b] = 1;
    cnt++;

    if (can(a , b + 1)) rec(a , b + 1);
    if (can(a , b - 1)) rec(a , b - 1);
    if (can(a + 1, b)) rec(a + 1, b);
    if (can(a - 1, b)) rec(a - 1 , b);

}

void solve() {
    cin >> n >> m;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    vis.resize(n);
    for (int i = 0 ; i < n ; i++) {
        vis[i].resize(m);
        for (int j = 0 ; j < m ; j++) {
            vis[i][j] = 0;
        }
    }

    cin >> x >> y;

    if (arr[x - 1][y - 1] == '*') {
        cout << 0 << '\n';
        return;
    }


    rec(x - 1 , y - 1);

    cout << cnt << '\n';

    cnt = 0;
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
