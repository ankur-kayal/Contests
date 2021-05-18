#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

/*

x = a / b
y = c / d

y / (x + 1) = c / d * (b / a + b) = c * b / (d * (a + b))
(y + 1) / x = (c + d) / d * (b / a) = (c + d) * b / (d * a)

*/

array<int64_t, 2> normalize_slope(array<int64_t, 2> slope) {
    int64_t hcf = gcd(slope[0], slope[1]);
    return {slope[0] / hcf, slope[1] / hcf};
}

void run_cases() {
    int N;
    cin >> N;
    vector<array<array<int64_t,2>,2>> slopes(N);
    vector<array<int64_t,2>> unique_slopes;
    for(int i=0;i<N;i++) {
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;
        slopes[i][0] = normalize_slope({ c * b, d * (a + b) });
        slopes[i][1] = normalize_slope({ (c + d) * b, d * a });
        unique_slopes.push_back(slopes[i][0]);
        unique_slopes.push_back(slopes[i][1]);
    }

    sort(unique_slopes.begin(), unique_slopes.end());
    unique_slopes.resize(unique(unique_slopes.begin(), unique_slopes.end()) - unique_slopes.begin());

    int vertices = N + unique_slopes.size();
    vector<vector<int>> adj(vertices);

    auto add_edge = [&](int u, int v) -> void {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    auto get_index = [&](array<int64_t, 2> slope) -> int {
        return int(lower_bound(unique_slopes.begin(), unique_slopes.end(), slope) - unique_slopes.begin());
    };

    // Form the graph
    for(int i=0;i<N;i++) {
        add_edge(i, N + get_index(slopes[i][0]));
        add_edge(i, N + get_index(slopes[i][1]));
    }
    vector<bool> vis(vertices, false);
    vector<array<int64_t, 2>> matches;



    auto dfs = y_combinator([&](auto self, int node) -> int {
        if(vis[node]) {
            return -1;
        }
        vis[node] = true;

        vector<int> items;

        for(int neighbour: adj[node]) {
            int child = self(neighbour);

            if(child >= 0) {
                items.push_back(child);
            }
        }

        while(items.size() >= 2) {
            matches.push_back({items[items.size() - 2], items[items.size() - 1]});
            items.pop_back();
            items.pop_back();
        }

        int item_node = node < N ? node : -1;
        if(!items.empty() && item_node != -1) {
            matches.push_back({item_node, items.back()});
            items.pop_back();
            item_node = -1;
        }
        if(item_node == -1 && !items.empty()) {
            item_node = items[0];
        }
        return item_node;
    });

    for(int i=N;i<vertices;i++) {
        dfs(i);
    }


    cout << matches.size() << '\n';

    for(int i=0;i<matches.size();i++) {
        cout << matches[i][0] + 1 << " " << matches[i][1] + 1 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}