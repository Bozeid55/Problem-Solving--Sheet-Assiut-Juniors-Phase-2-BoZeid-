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
const ll N = 1e5 + 5 , w = 1e6 + 5 , oo = 1e18 , o_o = -1e9;

int dx[] = {0 , 0  , 1 , -1} ,
    dy[] = {1 , -1 , 0 , 0};

struct DSU {
    vector <ll> parent , group; ll sz , mx;

    DSU (int n) {
        parent = vector <ll> (n + 5); sz = n + 5; mx = 1;
        group = vector <ll> (n + 5 , 1);
        iota(all(parent) , 0);
    }

    ll getLeader (int x) {
        if (parent[x] == x) return x;
        return parent[x] = getLeader(parent[x]);
    }

    bool Merge (int x, int y) {
        int Leader1 = getLeader(x), Leader2 = getLeader(y);
        if (Leader1 == Leader2) return 0;

        if (group[Leader1] > group[Leader2]) swap(Leader1, Leader2);

        parent[Leader1] = Leader2;
        group[Leader2] += group[Leader1];
        mx = max(mx , group[Leader2]);

        return 1;
    }

    bool sameGroup (int x, int y) {
        return getLeader(x) == getLeader(y);
    }

    int getSize (int x) {
        return group[getLeader(x)];
    }

};


ll mul(ll a,ll b,ll m) {
    return ((a%m)*(b%m))%m;
}

void solve () {
    int n , cnt = 1;

    while (cin >> n) {
        if (!n) return;

        DSU dsu(n + 1);
        vector <pair <int , int>> arr; arr.push_back({-1 , -1});
        int a , b;

        for (int i = 0 ; i < n ; i++) {
            cin >> a >> b; arr.push_back({a , b});
        }

        vector <pair <double , pair <int , int>>> mst;

        for (int i = 1 ; i <= n ; i++) {
            for (int j = i + 1 ; j <= n ; j++) {
                auto [x , y] = arr[i]; auto [x1 , y1] = arr[j];

                double cur = sqrt(((x1 - x) * (x1 - x))  +  ((y1 - y) * (y1 - y)));
                mst.push_back({cur , {i , j}});
            }
        }

        sort(all(mst));
        double ans = 0;

        for (auto i : mst) {
            auto [k , l] = i; auto [x , y] = l;

            dsu.Merge(x , y);
            if (dsu.getLeader(1) == dsu.getLeader(2)) {
                ans = k; break;
            }
        }

        cout << "Scenario #" << cnt++ << '\n'
             << "Frog Distance = " << fixed << setprecision(3) << ans << '\n';
        cout << '\n';
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
