void init(ll *a, ll *tree, ll s, ll e, ll n) {
    if (s == e) {
        tree[n] = a[s];
        return;
    }
    ll l = n * 2, r = n * 2 + 1, mid = (s + e) / 2;
    init(a, tree, s, mid, l);
    init(a, tree, mid + 1, e, r);
    tree[n] = max(tree[l], tree[r]);
    return;
}

void propagate(ll *tree, ll *lazy, ll s, ll e, ll n) {
    if (lazy[n] != 0) {
        tree[n] += lazy[n];
        if (s != e) {
            lazy[2 * n] += lazy[n];
            lazy[2 * n + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

ll lazyQuery(ll *tree, ll *lazy, ll s, ll e, ll i, ll n) {
    propagate(tree, lazy, s, e, n);
    if (s == e) return tree[n];
    ll mid = (s + e) / 2;
    if (i <= mid) return lazyQuery(tree, lazy, s, mid, i, 2 * n);
    else return lazyQuery(tree, lazy, mid + 1, e, i, 2 * n + 1);
}

void lazyUpdate(ll *tree, ll *lazy, ll s, ll e, ll i, ll j, ll val, ll n) {
    propagate(tree, lazy, s, e, n);
    if (j < s || i > e) return;
    if (i <= s && j >= e) {
        tree[n] += val;
        if (s != e) {
            lazy[2 * n] += val;
            lazy[2 * n + 1] += val;
        }
        return;
    }
    ll mid = (s + e) / 2;
    lazyUpdate(tree, lazy, s, mid, i, j, val, 2 * n);
    lazyUpdate(tree, lazy, mid + 1, e, i, j, val, 2 * n + 1);
    tree[n] = max(tree[2 * n], tree[2 * n + 1]);
}
