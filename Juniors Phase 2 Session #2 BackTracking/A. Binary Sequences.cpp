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
vector <string> ans;
string tmp ="";

void rec () {
    if (tmp.length() >= n) {
        ans.push_back(tmp);
        return;
    }
    
    tmp += '0';
    rec();
    tmp.pop_back();
    
    tmp += '1';
    rec();
    tmp.pop_back();
    
}


void solve() {
    cin >> n;

    rec();
    
    for (auto i : ans) {
        cout << i << '\n';
    }
    
    ans.clear(); tmp = "";
}

int main() {
    ABo_ZeiD;

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
