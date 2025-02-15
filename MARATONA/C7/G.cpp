#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define fi first
#define se second
#define sz(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define INF 1000000009
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

void solve() {
    string s; cin >> s;
    ll ps = 0, mx = -1, mxi = 0;
    for (int i = 0; i < sz(s); i++) {
        int up = (s[i] == '+'? 1 : -1);
        ps += up;
        if (ps > mx) {
            mx = ps;
            mxi = i;
        }
    }
    cout << mxi + 1<< '\n';
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    for (int t = 1; t <= tt; t++) {
         solve();
    }
}