//isti zadatak
//slozenost nlog(n) + Mlog(M) + qlog(M)log(n)


#include <iostream>
#include <vector>
#include <set>

#define M 100000

using namespace std;

int nzd(int x, int y) {
	while(y > 0) {
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int main() {
	int n, q, x;
	cin >> n >> q;

	set<int> s;
	for(int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}

	vector< vector<int> > D(M + 1);
	for(int k = 1; k <= M; k++)
		for(int i = k; i <= M; i += k)
			D[i].push_back(k);

	while(q--) {
		int x, y;
		cin >> x >> y;

		int d = nzd(x, y);
		// D[d] je vektor svih delioca broja d

		int m = -1;
		for(int i = D[d].size() - 1; i >= 0; i--) {
			int delilac = D[d][i];
			if(s.find(delilac) != s.end()) {
				m = delilac;
				break;
			}
		}
		cout << m << endl;
	}

	return 0;
}