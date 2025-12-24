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

int n , w;
vector <pair <int , int>> arr;

ll cnt = 0 , sum = 0 , mx = -1;

void rec(int idx) {
    if (idx >= n || cnt >= w) {
        if (cnt <= w) mx = max(mx , sum);

        return;
    }

    if (cnt <= w) mx = max(mx , sum);


    cnt += arr[idx].first;
    sum += arr[idx].second;

    rec(idx + 1);

    cnt -= arr[idx].first;
    sum -= arr[idx].second;

    rec(idx + 1);
}

void solve() {
    cin >> n >> w; arr.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    rec(0);

    cout << mx << '\n';
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
