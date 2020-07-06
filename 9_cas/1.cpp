//dat je skup S prirodnih brojeva od n elemenata
//dato je q upita, svaki upit je oblika (x,y)
//za svaki upit odrediti nzd koji se sadrzi u skupu S
//slozenost log(M) + q*sqrt(M)*log(n)

#include <iostream>
#include <set>

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

	while(q--) {
		int x, y;
		cin >> x >> y;

		int d = nzd(x, y);

		int m = -1;
		for(int k = 1; k * k <= d; k++)
			if(d % k == 0) {
				if(s.find(k) != s.end())
					m = max(m, k);
				if(s.find(d / k) != s.end())
					m = max(m, d / k);
			}
		cout << m << endl;
	}

	return 0;
}
