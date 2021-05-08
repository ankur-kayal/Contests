#include <bits/stdc++.h>
using namespace std;


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    set<pair<int,int>> edges;
    vector<int> parent(n, -1);
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
        adj[u].push_back(v);
        edges.insert({u, v});
    }
    vector<pair<int,int>> broken, construct;

    // Break the tree into multiple forests of bamboo
    function<void(int,int)> break_dfs = [&](int node, int par) -> void {
        parent[node] = par;
        vector<int> children;
        for(int child: adj[node]) {
            if(child != par) {
                break_dfs(child, node);
            }
        }
        for(auto u: adj[node]) {
            if(u != par && parent[u] != -1) {
                children.push_back(u);
            }
        }
        if(children.size() >= 2 && parent[node] != -1) {
            if(edges.count({node, par})) edges.erase(edges.find({node, par}));
            if(edges.count({par, node})) edges.erase(edges.find({par, node}));
            if(node > par) {
                broken.push_back({par, node});
            } else {
                broken.push_back({node, par});
            }
            parent[node] = -1;
        }
        if(adj[node].size() > 2) {
            for(int i=2;i<children.size();i++) {
                if(edges.count({node, children[i]})) edges.erase(edges.find({node, children[i]}));
                if(edges.count({children[i], node})) edges.erase(edges.find({children[i], node}));
                if(node > children[i]) {
                    broken.push_back({children[i], node});
                } else {
                    broken.push_back({node, children[i]});
                }
                parent[children[i]] = -1;
            }
        }
    };

    break_dfs(0, -1);


    // Now find the leafs of all bamboo forests
    vector<vector<int>> bamboo_leafs;
    adj = vector<vector<int>>(n);
    for(auto [u, v]: edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> leafs;
    vector<int> vis(n, 0);
    function<void(int,int)> find_bamboo_leafs = [&](int node, int par) -> void {
        vis[node] = 1;
        if(adj[node].size() <= 1) {
            leafs.push_back(node);
        }
        for(auto u: adj[node]) {
            if(u != par) {
                find_bamboo_leafs(u, node);
            }
        }
    };

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            leafs.clear();
            find_bamboo_leafs(i, -1);
            if(leafs.size() == 1) {
                leafs.push_back(leafs.back());
            }
            bamboo_leafs.push_back(leafs);
        }
    }

    // connect all bamboo trees in the forest
    for(int i=0;i<int(bamboo_leafs.size())-1;i++) {
        construct.push_back({bamboo_leafs[i][1], bamboo_leafs[i+1][0]});
    }

    cout << broken.size() << nl;
    if(!broken.empty()) {
        for(int i=0;i<broken.size();i++) {
            cout << broken[i].first + 1 << " " << broken[i].second + 1 << " ";
            // cout << nl;
            cout << construct[i].first + 1 << " " << construct[i].second + 1 << nl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}