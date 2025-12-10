// وَكَانَ فَضْلُ اللَّهِ عَلَيْكَ عَظِيمًا♡
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define input(vec) for (auto& i : vec) cin >> i
#define inputone(vec , x) for (int i = 1 ; i <= x ; i++) cin >> vec[i]
#define ABo_ZeiD ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const ll N = 1000000007;


void rec (int h , int n) {
    if (h == 0) return;
    rec(h - 1 , n);

    for (int i = 0 ; i < n - h ; i++) cout << " ";
    for (int i = 1 ; i <= 2 * h - 1 ; i++) cout << "*";
    cout << '\n';
}

void solve() {
    int n; cin >> n;

    rec(n , n);
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

//    cin >> t;
    while (t--)
        solve();


    return 0;
}
