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
		(void)!freopen((name+".in").c_str(), "r", stdin); // see /general/io
		(void)!freopen((name+".out").c_str(), "w", stdout);
	}
}

/**
 * Description: sorts vertices such that if there exists an edge x->y, then x goes before y
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/quantumsuperposition
 */

struct TopoSort {
	int N; vi in, res;
	vector<vi> adj;
	void init(int _N) { N = _N; in.resize(N); adj.resize(N); }
	void ae(int x, int y) { adj[x].pb(y), in[y] ++; }
	bool sort() {
		queue<int> todo; 
		for(int i = 0; i < N; i++) if (!in[i]) todo.push(i);
		while (sz(todo)) {
			int x = todo.front(); todo.pop(); res.pb(x);
			for(const int &i : adj[x]) if (!(--in[i])) todo.push(i);
		}
		return sz(res) == N;
	}
};

ll N, M;
const int mx = 3e5+1;

bool vis[mx];
int dp[mx][26];

string A;

int main() {
	setIO();
	cin >> N >> M >> A;

	TopoSort ts;

	ts.init(N);

	while(M--) {
		int a, b; cin >> a >> b;
		a--; b--;
		ts.ae(a, b);
	}

	if(!ts.sort()) {
		cout << -1 << endl;
	} else {
		for(const int &x : ts.res) {
			dp[x][A[x] - 'a']++;
			for(const int &e : ts.adj[x]) {
				for(int i = 0; i < 26; i++) {
					dp[e][i] = max(dp[e][i], dp[x][i]);
				}
			}
		}

		int ret = 0;

		for(int i = 0; i < N; i++) {
			for(int _ = 0; _ < 26; _++) {
				ret = max(ret, dp[i][_]);
			}
		}

		cout << ret << endl;
	}
}