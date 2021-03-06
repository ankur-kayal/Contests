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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int PX, PY;
    cin >> PX >> PY;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int left = 0, right = 0, up = 0, down = 0;
    for(auto u: s) {
        if(u == 'R') {
            right++;
            x++;
        }
        if(u == 'L') {
            left++;
            x--;
        }
        if(u == 'U') {
            up++;
            y++;
        }
        if(u == 'D') {
            down++;
            y--;
        }
    }

    int diffx = x - PX;
    int diffy = y - PY;
    debug() << imie(x) imie(y) imie(PX) imie(PY);
    debug() << imie(diffx) imie(diffy) imie(left) imie(right) imie(up) imie(down);
    bool ok = true;
    if(diffx > 0 and right < diffx) {
        ok = false;
    }
    debug() << imie(ok);
    if(diffx < 0 and left < -diffx) {
        ok = false;
    }
    debug() << imie(ok);
    if(diffy > 0 and up < diffy) {
        ok = false;
    }
    debug() << imie(ok);
    if(diffy < 0 and down < -diffy) {
        ok = false;
    }
    debug() << imie(ok);

    cout << (ok ? "YES" : "NO") << nl;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}