#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int64_t l, r, id;
    int64_t ord;

    Query() {}
 
    Query(int64_t _l, int64_t _r, int64_t _id) : l(_l), r(_r), id(_id) {calcOrder();}
 
    inline void calcOrder() {
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}

void run_cases() {
    int N, T;
    cin >> N >> T;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t maxA = *max_element(A.begin(), A.end());

    vector<int64_t> K(maxA + 1);

    int64_t ans = 0;
    vector<Query> queries;
    vector<int64_t> answers(T);

    for(int i = 0; i < T; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        queries.push_back(Query(l, r, i));
    }

    sort(queries.begin(), queries.end());

    int global_left = 0, global_right = 0;

    auto add_element = [&](int64_t element) {
        ans -= (K[element] * K[element] * element);
        K[element]++;
        ans += (K[element] * K[element] * element);
    };

    auto delete_element = [&](int64_t element) {
        ans -= (K[element] * K[element] * element);
        K[element]--;
        ans += (K[element] * K[element] * element);
    };

    for(Query q: queries) {

        while(global_left < q.l) {
            delete_element(A[global_left]);
            global_left++;
        }

        while(global_left > q.l) {
            global_left--;
            add_element(A[global_left]);
        }

        while(global_right < q.r) {
            add_element(A[global_right]);
            global_right++;
        }

        while(global_right > q.r) {
            global_right--;
            delete_element(A[global_right]);
        }

        answers[q.id] = ans;
    }


    for(auto u: answers) {
        cout << u << '\n';
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