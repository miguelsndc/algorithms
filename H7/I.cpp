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
int power(int b, int p, int m) {
    long long x = 1;
    int power = b % m;
    int k = log2(p);
    for (int i = 0; i <= k; i++) {
       int a = (p >> i) & 1;
       if (a == 1)
           x = (x * power) % m;
       power = (power * power) % m;
   }
    return x;
}

const int maxd = 1e6 + 1;
vi divisors(maxd + 1);
void solve() {
    int n; cin >> n;
    vi v(n); for (int i = 0; i < n; i++) cin >> v[i];
    for (int c: v) {
        for (int i = 1; i * i <= c; i++) {
            if (c % i == 0) {
                divisors[i]++;
                if (i != (c / i)) divisors[c / i]++;
            }
        }
    }
    for (int i = maxd; i >= 1; i--) {
        if (divisors[i] >= 2) {
            cout << i << '\n';
            return;
        }
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