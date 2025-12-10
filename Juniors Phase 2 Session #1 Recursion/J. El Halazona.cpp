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


int n , cnt = 0;
vector <vector <ll>> arr;
vector <vector <bool>> vis;
vector <ll> ans;

vector <char> dic = {'R' , 'D' , 'L' , 'U'};

bool can (int i , int j) {
    return i >= 0 && i < n && j >=0 && j < n && !vis[i][j];
}


void rec (int a , int b) {
    if (a < 0 || a >= n || b >= n || b < 0 || vis[a][b]) return;
    vis[a][b] = 1; ans.push_back(arr[a][b]);

    if (dic[cnt % 4] == 'R') {
        if (can(a , b + 1)) rec(a , b + 1);
        else {
            cnt++; rec(a + 1 , b);
        }
    }

    if (dic[cnt % 4] == 'D') {
        if (can(a + 1 , b)) rec(a + 1 , b);
        else {
            cnt++; rec(a , b - 1);
        }
    }

    if (dic[cnt % 4] == 'L') {
        if (can(a , b - 1)) rec(a , b - 1);
        else {
            cnt++; rec(a - 1 , b);
        }
    }

    if (dic[cnt % 4] == 'U') {
        if (can(a - 1 , b)) rec(a - 1 , b);
        else {
            cnt++; rec(a , b + 1);
        }
    }
}

void solve() {
    cin >> n;

    arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        arr[i].resize(n);
        for (int j = 0 ; j < n ; j++) {
            cin >> arr[i][j];
        }
    }

    vis.resize(n);
    for (int i = 0 ; i < n ; i++) {
        vis[i].resize(n);
        for (int j = 0 ; j < n ; j++) {
            vis[i][j] = 0;
        }
    }

    rec(0 , 0);

    for (int i = 0 ; i < n * n ; i++) {
        if ((i) && (i % n == 0)) {
            cout << '\n';
        }

        cout << ans[i] << " ";
    }
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
