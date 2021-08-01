#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, q;
vector< array<int, 3> > es;

inline bool read() {
	if(!(cin >> n >> q))
		return false;
	es.resize(q);
	fore (i, 0, q) {
		cin >> es[i][0] >> es[i][1] >> es[i][2];
		es[i][0]--;
		es[i][1]--;
	}
	return true;
}

vector< vector<pt> > g;

const int LOG = 19;
vector<int> up[LOG];
vector<int> tin, tout;
vector<int> xr;
int T = 0;

void dfs(int v, int p, int curXor) {
	tin[v] = T++;
	xr[v] = curXor;
	up[0][v] = p;
	fore (pw, 1, LOG)
		up[pw][v] = up[pw - 1][up[pw - 1][v]];
	
	for (auto [to, w] : g[v]) {
		if (to == p)
			continue;
		dfs(to, v, curXor ^ w);
	}
	tout[v] = T;
}

void buildLCA() {
	fore (pw, 0, LOG)
		up[pw].resize(n);
	tin.assign(n, -1);
	tout.assign(n, -1);
	xr.assign(n, 0);
	
	T = 0;
	fore (v, 0, n) {
		if (tin[v] != -1)
			continue;
		dfs(v, v, 0);
	}
}

int isPar(int p, int v) {
	return tin[p] <= tin[v] && tout[v] <= tout[p];
}

int lca(int u, int v) {
	if (isPar(u, v)) return u;
	if (isPar(v, u)) return v;
	
	for (int pw = LOG - 1; pw >= 0; pw--) {
		if (!isPar(up[pw][v], u))
			v = up[pw][v];
	}
	return up[0][v];
}

vector<int> par, rk;

void init(int n) {
	par.assign(n, 0);
	iota(par.begin(), par.end(), 0);
	rk.assign(n, 1);
}

int top(int v) {
	if (par[v] != v)
		return par[v] = top(par[v]);
	return v;
}

bool unite(int u, int v) {
	u = top(u);
	v = top(v);
	if (u == v)
		return false;
	if (rk[u] < rk[v])
		swap(u, v);
	par[v] = u;
	rk[u] += rk[v];
	return true;
}

vector<int> F;
void inc(int pos, int val) {
	for(; pos < sz(F); pos |= pos + 1)
		F[pos] += val;
}
int sum(int pos) {
	int ans = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ans += F[pos];
	return ans;
}

void addOnPath(int v, int l) {
	while (v != l) {
		inc(tin[v], 1);
		inc(tout[v], -1);
		v = up[0][v];
	}
}

inline void solve() {
	init(n);
	g.resize(n);
	
	vector<int> ans(q, -1);
	fore (i, 0, q) {
		int u = es[i][0];
		int v = es[i][1];
		int x = es[i][2];
		
		if (unite(u, v)) {
			ans[i] = 1;
			g[u].emplace_back(v, x);
			g[v].emplace_back(u, x);
		}
	}
	
	buildLCA();
	F.assign(2 * n + 5, 0);
	
	fore (i, 0, q) {
		if (ans[i] != -1)
			continue;
		
		ans[i] = 0;
		int u = es[i][0];
		int v = es[i][1];
		int x = es[i][2];
		
		int xorPath = xr[u] ^ xr[v];
		if ((xorPath ^ x) != 1)
			continue;
		
		int l = lca(u, v);
		int usedOnPath = sum(tin[u]) + sum(tin[v]) - 2 * sum(tin[l]);
		if (usedOnPath > 0)
			continue;
		
		ans[i] = 1;
		addOnPath(u, l);
		addOnPath(v, l);
	}
	
	for (int res : ans)
		cout << (res ? "YES" : "NO") << '\n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}