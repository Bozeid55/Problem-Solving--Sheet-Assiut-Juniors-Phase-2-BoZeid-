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


int n , m , x , y;
vector <vector <ll>> arr , brr , ans;

void rec (int a , int b , int cur) {
    if (a >= n) return;

    if (b < y) {
        if (cur < m) {
            ans[a][b] += (arr[a][cur] * brr[cur][b]);
            rec(a , b , cur + 1);

            return;
        }

        rec(a , b + 1 , 0);
        return;
    }

    rec(a + 1 , 0 , 0);
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

    cin >> x >> y;
    brr.resize(x);
    for (int i = 0 ; i < x ; i++) {
        brr[i].resize(y);
        for (int j = 0 ; j < y ; j++) {
            cin >> brr[i][j];
        }
    }

    ans.resize(n);
    for (int i = 0 ; i < n ; i++) {
        ans[i].resize(y);
        for (int j = 0 ; j < y ; j++) {
            ans[i][j] = 0;
        }
    }

    rec(0 , 0 , 0);

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < y ; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
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
