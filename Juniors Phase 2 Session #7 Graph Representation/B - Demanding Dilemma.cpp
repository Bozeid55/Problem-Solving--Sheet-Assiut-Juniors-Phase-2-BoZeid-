// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1005, W = 1e5 + 5 , oo = 1e9 + 5;

int p; vector <int> adj[N]; bool vis[N];

void solve() {
    int n , m , x; cin >> n >> m;

    for (int i = 0 ; i < n ; i++) {
        for (int j =  0 ; j < m ; j++) {
            cin >> x; adj[i].push_back(x);
        }
    }


    if (m == 0) {
        cout << "Yes";
        for (int i = 0 ; i < n ; i++) {
            adj[i].clear();
        }
        return;
    }

    set <vector <int>> st;

    bool flag = true;
    for (int i = 0 ; i < m ; i++) {
        int cnt = 0;

        vector <int> idx;
        for (int j = 0 ; j < n ; j++) {
            cnt += adj[j][i];
            if (adj[j][i]) idx.push_back(j);
        }

        if (st.count(idx)) {
            flag = false; break;
        }

        if (cnt != 2) {
            flag = false; break;
        }

        st.insert(idx);
    }


    cout << (flag ? "Yes" : "No");

    for (int i = 0 ; i < n ; i++) {
        adj[i].clear();
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkk;


//    memset(dp , -1 , sizeof(dp));
    //freopen("smallest.in" , "r", stdin);


    int t = 1;
    cin >> t;
    for (int i = 1 ; i <= t ; i++) {
//        cout << "Case " << i << ": ";
        solve();

            cout << '\n';

    }


    return 0;
}
