// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define msb(x) 64 - ll(__builtin_clzll(x))
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , w = 1e6 + 5 , oo = 1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};

struct DSU {
    vector <int> parent , group; int sz;

    DSU (int n) {
        parent = vector <int> (n + 1); sz = n;
        group = vector <int> (n + 1 , 1);
        iota(all(parent) , 0);
    }

    int getLeader (int x) {
        if (parent[x] == x) return x;
        return parent[x] = getLeader(parent[x]);
    }

    bool Merge (int x, int y) {
        int Leader1 = getLeader(x), Leader2 = getLeader(y);
        if (Leader1 == Leader2) return 0;

        if (group[Leader1] > group[Leader2]) swap(Leader1, Leader2);

        parent[Leader1] = Leader2;
        group[Leader2] += group[Leader1];

        return 1;
    }

    bool sameGroup (int x, int y) {
        return getLeader(x) == getLeader(y);
    }

    int getSize (int x) {
        return group[getLeader(x)];
    }
};

void solve () {
    char c; cin >> c; cin.ignore();
    string s;

    DSU dsu(c - 'A' + 1);

    int ans = (c - 'A' + 1);
    while (getline(cin , s)) {
        if (s.empty()) break;
        if (dsu.Merge(s[0] - 'A' + 1, s[1] - 'A' + 1)) ans--;
    }

    cout << ans << '\n';
}

int32_t main() {
    ABo_ZeiD; // i'm backkkkkk;

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif

    int t = 1;
    cin >> t; cin.ignore();
    for (int i = 1 ; i <= t ; i++) {
        // cout << "Case " << i << ":" << '\n';
        solve();
        if (i != t) cout << '\n';
    }


    return 0;
}
