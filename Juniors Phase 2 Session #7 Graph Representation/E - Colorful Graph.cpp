// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5, W = 1e5 + 5 , oo = 1e9 + 5;

vector <set <int>> adj(N);

void solve() {
    int n , m , a , b; cin >> n >> m;
    vector <int> arr(n); set <int> st;

    for (auto &i : arr) {
        cin >> i; st.insert(i);
    }

    while (m--) {
        cin >> a >> b;

        if (arr[a - 1] != arr[b - 1]) {
            adj[arr[b - 1]].insert(arr[a - 1]);
            adj[arr[a - 1]].insert(arr[b - 1]);
        }
    }

    int mx = -oo , idx = -1;
    for (auto i : st) {
        int sz = adj[i].size();

        if (sz > mx) {
            mx = sz; idx = i;
        }
    }

    cout << idx << '\n';
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
