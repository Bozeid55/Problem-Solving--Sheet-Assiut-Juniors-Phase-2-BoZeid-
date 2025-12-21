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

int n;
vector <int> arr , tmp;
multiset <vector <int>> ans;

// ana gbt a5ryyyyyyyyyyyyyyyyyyyy
void rec(int idx) {
    if (idx >= n) {
        if (!tmp.empty()) ans.insert(tmp);

        return;
    }

    if (tmp.empty() || arr[idx] > tmp.back()) {
        tmp.push_back(arr[idx]);
        rec(idx + 1);
        tmp.pop_back();
    }

    rec(idx + 1);
}


void solve() {
    cin >> n;
    arr.resize(n); input(arr);

    rec(0);

    for (auto i : ans) {
        for (int x : i) {
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
