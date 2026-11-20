#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
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

ll lcm(ll a, ll b){
    return a * (b/gcd(a, b));
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

ll mxsgt(ll i, ll l, ll r, ll a, ll b, vl & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return -1e17;
    return max(mxsgt(i * 2, l, r, a, (a + b)/2, sgt), mxsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt));
}

ll mnsgt(ll i, ll l, ll r, ll a, ll b, vl & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return 1e17;
    return min(mnsgt(i * 2, l, r, a, (a + b)/2, sgt), mnsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt));
}

ll smsgt(int i, int l, int r, int a, int b, vl & sgt){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return 0;
    return smsgt(i * 2, l, r, a, (a + b)/2, sgt) + smsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt);
}

ll prodsgt(int i, int l, int r, int a, int b, vl & sgt, ll md){
    if (l <= a && b <= r) return sgt[i];
    if (b < l || r < a) return 1;
    return (prodsgt(i * 2, l, r, a, (a + b)/2, sgt, md) * prodsgt(i * 2 + 1, l, r, (a + b + 1)/2, b, sgt, md))%md;
}

vi z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void addtrie(int i, int j, int m, string & s, vvi & trie){
    if (i == m) {
        trie[j][26]++;
        return;
    }
    int k = int(s[i] - 'a');
    if (!trie[j][k]){
        trie[j][k] = int(trie.size());
        trie.pb(vi (27, 0));
    }
    addtrie(i + 1, trie[j][k], m, s, trie);
}

int cnttrie(int i, int j, int m, string & s, vvi & trie){
    if (i == m) return trie[j][26];
    int k = int(s[i] - 'a');
    if (!trie[j][k]) return 0;
    return cnttrie(i + 1, trie[j][k], m, s, trie);
}


void dfscyclebridge(int i, int p, int & ct, vi & c, vi & t, vi & l, vvi & gf){
    t[i] = l[i] = ct++;
    for (int j: gf[i]){
        if (j != p){
            if (!t[j]){
                dfscyclebridge(j, i, ct, c, t, l, gf);
                l[i] = min(l[i], l[j]);
                if (l[j] <= t[i]) c[i] = c[j] = 1;
                // else i j is a bridge
            }else l[i] = min(l[i], t[j]);
        }
    }
}

// ll mx = 1e5, md = 998244353;
// vl f(mx + 1, 1), invf(mx + 1, 1);

void buildfac(ll & mx, ll & md, vl & f, vl & invf){
    for (int i = 2; i <= mx; i++) f[i] = (f[i - 1] * i)%md;
    invf[mx] = inv(f[mx], md);
    for (int i = mx - 1; i; i--) invf[i] = ((i + 1) * invf[i + 1])%md;
}

// int mx = 1e7 + 1;
//vi pm, sv(mx, 1);

void buildprimes(int & mx, vi & sv, vi & pm){
    sv[0] = sv[1] = 0;
    for (int i = 2; i < mx; i++){
        if (sv[i]){
            pm.pb(i);
            for (int j = i * i; j < mx; j += i) sv[j] = 0;
        }
    }
}

void solve(){
    //
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //buildfac(mx, md, f, invf);
    //buildprimes(mx, sv, pm);
    cin >> t;
    while (t--) solve();
}

