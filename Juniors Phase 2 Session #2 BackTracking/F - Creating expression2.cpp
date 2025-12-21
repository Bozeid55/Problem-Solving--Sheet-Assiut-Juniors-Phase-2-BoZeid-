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


int n; ll trg , cnt = 0;
vector <ll> arr;

void rec (int idx , ll cur) {
    if (idx >= n) {
        if (cur == trg) {
            cnt++;
        }
        return;
    }


    rec(idx + 1 , cur + arr[idx]);
    rec(idx + 1 , cur - arr[idx]);
}

void solve() {
    cin >> n >> trg;
    arr.resize(n); input(arr);

    rec(1 , arr[0]);


    cout << cnt << '\n';
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
