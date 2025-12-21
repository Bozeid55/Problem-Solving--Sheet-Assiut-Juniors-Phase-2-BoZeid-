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
vector <string> arr , tmp;
set <set <string>> ans;

void rec (int idx) {
    if (idx >= n || tmp.size() >= r) {
        if (tmp.size() >= r) {
            set <string> cur(all(tmp));

            ans.insert(cur);
        }
        return;
    }


    for (int i = idx ; i < n ; i++) {
        tmp.push_back(arr[i]);
        rec(i + 1);
        tmp.pop_back();
    }

}

void solve() {
    cin >> n >> r;
    arr.resize(n); input(arr);


    rec(0);

    //sort(all(ans));
    for (auto i : ans) {
        for (auto x : i) {
            cout << x << " ";
        }
        cout << '\n';
    }


    ans.clear();
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
