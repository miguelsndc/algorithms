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
    int x; 
    while((cin >> x) && x != 42) {
        cout << x << '\n';
    }
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