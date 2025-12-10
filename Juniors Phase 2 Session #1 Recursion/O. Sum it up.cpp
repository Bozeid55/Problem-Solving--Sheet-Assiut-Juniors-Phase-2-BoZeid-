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
int dx[]= {-1 , 1 , 0 , 0 , 1 , -1 , 1, -1} ,
    dy[]= {0 , 0 , 1 , -1 , 1 , -1 , -1 ,1};


int n , k;
vector <ll> arr;
set <vector <int>> st;
vector <int> tmp;
ll sum = 0;

void rec (int a) {
    if (a >= n) {
        if (sum == k) {
            st.insert(tmp);
        }
        return;
    }

    sum += arr[a];
    tmp.push_back(arr[a]);
    rec (a + 1);

    tmp.pop_back();
    sum -= arr[a];
    rec (a + 1);
}

void solve() {
    cin >> n >> k;
    arr.resize(n); input(arr);

    rec(0);

    if (st.empty()) {
        cout << "NONE" << '\n';
        cout << '\n';
        return;
    }

    for (auto i : st) {
        for (auto a : i) {
            cout << a << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    arr.clear();
    tmp.clear();
    st.clear();
    sum = 0;
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
