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

vector <vector <int>> cur;
vector <bool> visC , visDr , visDl;
ll sum = 0 , mx = 0;

void rec (int idx) {
    if (idx >= 8) {
        mx = max(mx ,sum);
        return;
    }

    for (int i = 0 ; i < 8 ; i++) {

        if (!visC[i] && !visDr[i + idx] && !visDl[8 + i - idx]) {
            sum += cur[i][idx];

            visC[i] = visDr[i + idx] = visDl[8 + i - idx] = 1;
            rec(idx + 1);
            visC[i] = visDr[i + idx] = visDl[8 + i - idx] = 0;

            sum -= cur[i][idx];
        }
    }

}

void solve() {
    visC.resize(8); visDr.resize(2 * 8 + 1); visDl.resize(2 * 8 + 1);

    cur.resize(8);
    for (int i = 0 ; i < 8 ; i++) {
        cur[i].resize(8);

        for (int j = 0 ; j < 8 ; j++) {
            cin >> cur[i][j];
        }
    }

    rec(0);

    cout << mx << '\n';
    sum = 0 , mx = 0;

    visC.clear(); visDr.clear(); visDl.clear();
}

int main() {
    ABo_ZeiD; // i'm backkkkkkk

    //freopen("smallest.in" , "r", stdin);


    int t = 1;

    cin >> t;
    while (t--)
        solve();


    return 0;
}
