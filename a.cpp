#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
// using sint = __int128;
#define pb push_back
#define psf push_front
#define popb pop_back
#define popf pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef pair <int, int> pi;
typedef pair <ll, ll> pl;
typedef pair <double, double> pd;
typedef vector <string> vs;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <double> vd;
typedef vector <vd> vvd;
typedef vector <bool> vb;
typedef vector <vi> vvi;
typedef vector <vl> vvl;
typedef vector <vb> vvb;
typedef vector <vvi> vvvi;
typedef vector <vvl> vvvl;
typedef multiset <int> msi;
typedef multiset <ll> msl;
typedef set <int> sti;
typedef set <ll> stl;
typedef deque <int> di;
typedef deque <ll> dl;
typedef priority_queue <int> pqi;
typedef priority_queue <ll> pql;
typedef priority_queue <pi> pqpi;
typedef priority_queue <pl> pqpl;

ll gcd(ll a, ll b){
    if (!b) return a;
    return gcd(b, a % b);
}

ll inv(ll a, ll m){
    ll r = 1, b = m - 2, z = 1, k = a;
    while (z <= b){
        if (b & z) r = (r * k) % m;
        z *= 2;
        k = (k * k) % m;
    }
    return r;
}

int find(int a, vi & p){
    if (a == p[a]) return a;
    p[a] = find(p[a], p);
    return p[a];
}

void uni(int a, int b, vi & r, vi & p){
    a = find(a, p), b = find(b, p);
    if (a == b) return ;
    if (r[b] > r[a]) swap(a, b);
    r[a] = max(r[a], r[b] + 1);
    p[b] = a;
}

int mxsgt(int i, int l, int r, int a, int b, vi & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return -1e9;
    return max(mxsgt(i * 2, l, r, a, (a + b)/2, sgt), mxsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt));
}

int mnsgt(int i, int l, int r, int a, int b, vl & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return 1e9;
    return min(mnsgt(i * 2, l, r, a, (a + b)/2, sgt), mnsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt));
}

ll smsgt(int i, int l, int r, int a, int b, vl & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return 0;
    return smsgt(i * 2, l, r, a, (a + b)/2, sgt) + smsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt);
}

// ll mx = 1e6, m = 998244353;
// vl f(mx + 1, 1), invf(mx + 1, 1);

void solve(){
    //
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // for (int i = 2; i <= mx; i++) f[i] = (f[i - 1] * i)%m;
    // invf[mx] = inv(f[mx], m);
    // for (int i = mx - 1; i; i--) invf[i] = ((i + 1) * invf[i + 1])%m;
    cin >> t;
    while (t--) solve();
}
