#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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


void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> ranges(N);
    for(int i = 0; i < N; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l *= 2;
        r *= 2;
        switch(t) {
            case 2:
                r--;
                break;
            case 3:
                l++;
                break;
            case 4:
                l++, r--;
                break;
        }
        ranges[i] = {l, r};
    }

    int ans = 0;

    auto intersect = [&](vector<int> &a, vector<int> &b) -> bool {
        vector<int> common = {max(a[0], b[0]), min(a[1], b[1])};
        return common[0] <= common[1];
    };

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            ans += intersect(ranges[i], ranges[j]);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}