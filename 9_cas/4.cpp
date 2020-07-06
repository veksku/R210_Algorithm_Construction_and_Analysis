//izracunaj n-ti clan fibonacijevog niza
//slozenost log(n)

#include <iostream>
#include <vector>

#define MOD 10000 //poslednjih 10000 cifara n-tog broja, jer brojevi u ovom nizu jako brzo rastu

using namespace std;

// 0 1
// 2 3

vector<int> mat_mul(vector<int> m1, vector<int> m2) {
	vector<int> m(4);
	m[0] = (m1[0] * m2[0]) % MOD + (m1[1] * m2[2]) % MOD;
	m[1] = (m1[0] * m2[1]) % MOD + (m1[1] * m2[3]) % MOD;
	m[2] = (m1[2] * m2[0]) % MOD + (m1[3] * m2[2]) % MOD;
	m[3] = (m1[2] * m2[1]) % MOD + (m1[3] * m2[3]) % MOD;
	return m;
}

vector<int> fastpow(vector<int> a, int n) {
	vector<int> res = {1, 0, 0, 1}; //jedinicna matrica
	while(n > 0) {
		if(n & 1)
			res = mat_mul(res, a);
		a = mat_mul(a, a);
		n >>= 1;
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	vector<int> mat = {1, 1, 1, 0};
	vector<int> mat_n = fastpow(mat, n);
	cout << mat_n[2] << endl;
	return 0;
}