// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000005, W = 1e5 + 5 , oo = 1e9 + 5;


int n , m , x , a , b; vector <int> adj[N];
void solve() {

    while (cin >> n) {
        cin >> m;

        set <int> st;
        for (int i = 0 ; i < n ; i++) {
            cin >> x; st.insert(x);
            adj[x].push_back(i + 1);
        }

        while (m--) {
            cin >> a >> b;

            if (adj[b].size() < a) cout << 0 << '\n';
            else cout << adj[b][a - 1] << '\n';
        }

        for (auto i : st) {
            adj[i].clear();
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
