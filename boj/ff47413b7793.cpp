#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[9] = {-1};

void rec(int d) {
	if (d == m) {
		for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (ans[d] <= arr[i]) {
			ans[d + 1] = arr[i];
			rec(d + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	rec(0);
}