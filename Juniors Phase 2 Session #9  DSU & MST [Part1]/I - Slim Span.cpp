// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define msb(x) 64 - ll(__builtin_clzll(x))
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1e5 + 5 , w = 1e6 + 5 , oo = 2e18 , o_o = -2e18;

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

ll add(ll a,ll b,ll m) {
    return ((a%m)+(b%m))%m;
}


ll mul(ll a,ll b,ll m) {
    return ((a%m)*(b%m))%m;
}


ll sub(ll a,ll b,ll m) {
    return ((a%m)-(b%m)+m)%m;
}


void solve () {
    int n , m , a , b , c;
    while (cin >> n >> m) {
        if (!n && !m) return;

        vector <pair <int , pair<int , int>>> mst;
        for (int i = 0 ; i < m ; i++) {
            cin >> a >> b >> c;
            mst.push_back({c , {a , b}});
        }

        sort(all(mst));

        int ans = INT_MAX;
        for (int i = 0 ; i < m ; i++) {
            DSU dsu(n);
            vector <int> val;

            int cnt = 0;
            for (int j = i ; j < m ; j++) {
                auto [k , l] = mst[j]; auto [x , y] = l;
                if (dsu.Merge(x , y)) {
                    cnt++; val.push_back(k);
                }
            }

            if (cnt == n - 1) {
                int mn = *min_element(all(val)) , mx = *max_element(all(val));
                ans = min(ans , (mx - mn));
            }
        }

        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }

}

int main() {
    ABo_ZeiD; // i'm backkkkkk;

#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
#endif

    int t = 1;
    //cin >> t;
    for (int i = 1 ; i <= t ; i++) {
        solve();
    }
    //cin >> t;

    return 0;
}
