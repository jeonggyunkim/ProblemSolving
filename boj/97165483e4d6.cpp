#include <iostream>
using namespace std;

long long c(int n, int r) {
	static long long mem[30][30] = {};

	if (mem[n][r] > 0) {
		return mem[n][r];
	}
	if (r == 0 || n == r) {
		return mem[n][r] = 1;
	}
	return mem[n][r] = c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
	int N, K;
	cin >> N >> K;

	cout << c(N, K);
}