#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> line;

struct LiChaoTree {
	const ll INF = 2e18;
	inline ll f(line l, ll x) {
		return l.first * x + l.second;
	}
	struct Node {
		int lnode, rnode;
		ll xl, xr;
		line l;
	};
	vector<Node> nodes;
	LiChaoTree(ll xmin, ll xmax) {
		nodes.push_back({-1, -1, xmin, xmax, {0, INF}});
	}
	void insert(int n, line newline) {
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;

		line llow = nodes[n].l, lhigh = newline;
		if (f(llow, xl) > f(lhigh, xl)) swap(llow, lhigh);

		if (f(llow, xr) <= f(lhigh, xr)) {
			nodes[n].l = llow;
			return;
		}
		else if (f(llow, xm) <= f(lhigh, xm)) {
			nodes[n].l = llow;
			if (nodes[n].rnode == -1) {
				nodes[n].rnode = nodes.size();
				nodes.push_back({-1, -1, xm + 1, xr, {0, INF}});
			}
			insert(nodes[n].rnode, lhigh);
		}
		else {
			nodes[n].l = lhigh;
			if (nodes[n].lnode == -1) {
				nodes[n].lnode = nodes.size();
				nodes.push_back({-1, -1, xl, xm, {0, INF}});
			}
			insert(nodes[n].lnode, llow);
		}
	}

	ll get(int n, ll xq) {
		if (n == -1) return INF;
		ll xl = nodes[n].xl, xr = nodes[n].xr;
		ll xm = (xl + xr) / 2;
		if (xq <= xm) return min(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
		else return min(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	LiChaoTree li(-1e12 - 100, 1e12 + 100);

	while (q--) {
		int op;
		ll a, b;
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			li.insert(0, {-a, -b});
		}
		else {
			cin >> a;
			cout << -li.get(0, a) << '\n';
		}
	}
}