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

const int mx = 1e5 + 1, MOD = 1e9 + 7; 

ll dp[mx][3];
vi adj[mx];

void dfs(int v, int p = 0) {
	for(const int &e : adj[v]) {
		if(e != p) {
			dfs(e, v);
			dp[v][0] *= dp[e][1] + dp[e][2];
			dp[v][1] *= dp[e][0] + dp[e][2];
			dp[v][2] *= dp[e][0] + dp[e][1];
			dp[v][0] %= MOD;
			dp[v][1] %= MOD;
			dp[v][2] %= MOD;
		}
	}
}

int main() {
	setIO("barnpainting");
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b); adj[b].pb(a);
	}

	for(int i = 1; i <= n; i++)
		dp[i][0] = 1, dp[i][1] = 1, dp[i][2] = 1;

	while(m--) {
		int b, c; cin >> b >> c;
		dp[b][0] = 0;
		dp[b][1] = 0;
		dp[b][2] = 0;
		dp[b][c - 1] = 1;
	}

	dfs(1);

	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD << endl;
}