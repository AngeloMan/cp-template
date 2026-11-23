// \begin{lstlisting}
// int ns = 1;
// while (ns < n) ns <<= 1;
// // sgt.assign(2 * ns, neutro);
// // lazy.assign(2 * ns, 0);
// \end{lstlisting}

// \subsubsection*{1.2.4.1 Range add + range sum}
// \begin{lstlisting}
vl sgt, lazy;

void apply(int p, int l, int r, ll x){
    sgt[p] += x * (r - l + 1);
    lazy[p] += x;
}

void push(int p, int l, int r){
    if (lazy[p] == 0 || l == r) return;
    int md = (l + r) >> 1;
    apply(p << 1, l, md, lazy[p]);
    apply(p << 1 | 1, md + 1, r, lazy[p]);
    lazy[p] = 0;
}

void build(int p, int l, int r, vl &a, int n){
    if (l == r){
        sgt[p] = (l < n ? a[l] : 0);
        return;
    }
    int md = (l + r) >> 1;
    build(p << 1, l, md, a, n);
    build(p << 1 | 1, md + 1, r, a, n);
    sgt[p] = sgt[p << 1] + sgt[p << 1 | 1];
}

void upd(int p, int l, int r, int i, ll x){
    if (l == r){
        sgt[p] = x;
        lazy[p] = 0;
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    if (i <= md) upd(p << 1, l, md, i, x);
    else upd(p << 1 | 1, md + 1, r, i, x);
    sgt[p] = sgt[p << 1] + sgt[p << 1 | 1];
}

void add(int p, int l, int r, int ql, int qr, ll x){
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr){
        apply(p, l, r, x);
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    add(p << 1, l, md, ql, qr, x);
    add(p << 1 | 1, md + 1, r, ql, qr, x);
    sgt[p] = sgt[p << 1] + sgt[p << 1 | 1];
}

ll query(int p, int l, int r, int ql, int qr){
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return sgt[p];
    push(p, l, r);
    int md = (l + r) >> 1;
    return query(p << 1, l, md, ql, qr)
         + query(p << 1 | 1, md + 1, r, ql, qr);
}

// Inicializacao (n > 0):
// sgt.assign(2 * ns, 0); lazy.assign(2 * ns, 0);
// build(1, 0, ns - 1, a, n);
// upd(1, 0, ns - 1, i, x); // atribui a[i] = x
// add(1, 0, ns - 1, l, r, x);
// query(1, 0, ns - 1, l, r);
// \end{lstlisting}

// \subsubsection*{1.2.4.2 Range add + range max}
// \begin{lstlisting}
const ll NEG = -1e17;
vl sgt, lazy;

void apply(int p, ll x){
    sgt[p] += x;
    lazy[p] += x;
}

void push(int p, int l, int r){
    if (lazy[p] == 0 || l == r) return;
    apply(p << 1, lazy[p]);
    apply(p << 1 | 1, lazy[p]);
    lazy[p] = 0;
}

void build(int p, int l, int r, vl &a, int n){
    if (l == r){
        sgt[p] = (l < n ? a[l] : NEG);
        return;
    }
    int md = (l + r) >> 1;
    build(p << 1, l, md, a, n);
    build(p << 1 | 1, md + 1, r, a, n);
    sgt[p] = max(sgt[p << 1], sgt[p << 1 | 1]);
}

void upd(int p, int l, int r, int i, ll x){
    if (l == r){
        sgt[p] = x;
        lazy[p] = 0;
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    if (i <= md) upd(p << 1, l, md, i, x);
    else upd(p << 1 | 1, md + 1, r, i, x);
    sgt[p] = max(sgt[p << 1], sgt[p << 1 | 1]);
}

void add(int p, int l, int r, int ql, int qr, ll x){
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr){
        apply(p, x);
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    add(p << 1, l, md, ql, qr, x);
    add(p << 1 | 1, md + 1, r, ql, qr, x);
    sgt[p] = max(sgt[p << 1], sgt[p << 1 | 1]);
}

ll query(int p, int l, int r, int ql, int qr){
    if (r < ql || qr < l) return NEG;
    if (ql <= l && r <= qr) return sgt[p];
    push(p, l, r);
    int md = (l + r) >> 1;
    return max(query(p << 1, l, md, ql, qr),
               query(p << 1 | 1, md + 1, r, ql, qr));
}

// Inicializacao (n > 0):
// sgt.assign(2 * ns, NEG); lazy.assign(2 * ns, 0);
// build(1, 0, ns - 1, a, n);
// upd(1, 0, ns - 1, i, x); // atribui a[i] = x
// add(1, 0, ns - 1, l, r, x);
// query(1, 0, ns - 1, l, r);
// \end{lstlisting}

// \subsubsection*{1.2.4.3 Range add + range min}
// \begin{lstlisting}
const ll INF = 1e17;
vl sgt, lazy;

void apply(int p, ll x){
    sgt[p] += x;
    lazy[p] += x;
}

void push(int p, int l, int r){
    if (lazy[p] == 0 || l == r) return;
    apply(p << 1, lazy[p]);
    apply(p << 1 | 1, lazy[p]);
    lazy[p] = 0;
}

void build(int p, int l, int r, vl &a, int n){
    if (l == r){
        sgt[p] = (l < n ? a[l] : INF);
        return;
    }
    int md = (l + r) >> 1;
    build(p << 1, l, md, a, n);
    build(p << 1 | 1, md + 1, r, a, n);
    sgt[p] = min(sgt[p << 1], sgt[p << 1 | 1]);
}

void upd(int p, int l, int r, int i, ll x){
    if (l == r){
        sgt[p] = x;
        lazy[p] = 0;
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    if (i <= md) upd(p << 1, l, md, i, x);
    else upd(p << 1 | 1, md + 1, r, i, x);
    sgt[p] = min(sgt[p << 1], sgt[p << 1 | 1]);
}

void add(int p, int l, int r, int ql, int qr, ll x){
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr){
        apply(p, x);
        return;
    }
    push(p, l, r);
    int md = (l + r) >> 1;
    add(p << 1, l, md, ql, qr, x);
    add(p << 1 | 1, md + 1, r, ql, qr, x);
    sgt[p] = min(sgt[p << 1], sgt[p << 1 | 1]);
}

ll query(int p, int l, int r, int ql, int qr){
    if (r < ql || qr < l) return INF;
    if (ql <= l && r <= qr) return sgt[p];
    push(p, l, r);
    int md = (l + r) >> 1;
    return min(query(p << 1, l, md, ql, qr),
               query(p << 1 | 1, md + 1, r, ql, qr));
}

// Inicializacao (n > 0):
// sgt.assign(2 * ns, INF); lazy.assign(2 * ns, 0);
// build(1, 0, ns - 1, a, n);
// upd(1, 0, ns - 1, i, x); // atribui a[i] = x
// add(1, 0, ns - 1, l, r, x);
// query(1, 0, ns - 1, l, r);
