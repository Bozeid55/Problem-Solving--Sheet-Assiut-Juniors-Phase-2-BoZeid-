// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N =  1e4 + 1;

int n , r;
vector <int> tmp; bool vis[10] = {0};
vector <vector<int>> ans;

void rec() {
    if (tmp.size() == r) {
        ans.push_back(tmp);
        return;
    }
    
    for (int idx = 1 ; idx <= n ; idx++) {
        if (!vis[idx]) {
            tmp.push_back(idx); vis[idx] = 1;
            rec();
            tmp.pop_back(); vis[idx] = 0;
        }
    }
    
}


void solve() {
    cin >> n >> r;
    rec();

    sort(all(ans));
    for (auto i : ans) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << '\n';
    }
    
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
