#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;

using ll = long long;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin); // see /general/io
		freopen((name+".out").c_str(), "w", stdout);
	}
}

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
};

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	for(int i = 0; i < sz(v)-1; i++) a += v[i].cross(v[i+1]);
	return a;
}

typedef Point<long double> P;

void solve(int n) {
	vector<P> pts(n);
	for(int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		pts[i] = P(a, b);
	}

	// implementation has 2x polygon area
	long double area = polygonArea2(pts) / 2;
	(area < 0) ? cout << "CW " : cout << "CCW ";

	cout << fixed << setprecision(1) << abs(area) << "\n";
}

int main() {
	setIO();
	for(;;) {
		int n; cin >> n;
		if(!n) break;
		solve(n);
	} 
}