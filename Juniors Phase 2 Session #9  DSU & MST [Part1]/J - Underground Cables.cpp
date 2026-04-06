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
    int n;
    while (cin >> n) {
        if (!n) return;

        vector <pair <int , int>> arr;
        vector <pair <double , pair<int , int>>> mst;

        int a , b;
        for (int i = 0 ; i < n ; i++) {
            cin >> a >> b; arr.push_back({a , b});
        }

        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i == j) continue;
                double cur = sqrt((arr[j].first - arr[i].first) * (arr[j].first - arr[i].first) +
                               (arr[j].second - arr[i].second) * (arr[j].second - arr[i].second));

                mst.push_back({cur , {i + 1 , j + 1}});
            }
        }

        sort(all(mst));
        DSU dsu(n);

        double cnt = 0;
        for (auto i : mst) {
            auto [k , l] = i; auto [x , y] = l;

            if (dsu.Merge(x , y)) {
                cnt += k;
            }
        }

        cout << fixed << setprecision(2) << cnt << '\n';
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
