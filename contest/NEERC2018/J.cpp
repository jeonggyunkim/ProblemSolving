#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, x, y;
	cin >> a >> b >> x >> y;

	long long d = __gcd(x, y);
	x /= d; y /= d;

	cout << min(a / x, b / y);
}