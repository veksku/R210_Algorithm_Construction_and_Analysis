//brzo stepenovanje, izracunati vrednost a^n
//slozenost log(n) gde je n velicina stepena

#include <iostream>

using namespace std;

int fastpow(int a, int n) {
	int res = 1;
	while(n > 0) {
		if(n & 1) //izdvajaju se samo stepeni dvojke, vidi primer
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
	int a, n;
	cin >> a >> n;

	cout << fastpow(a, n) << endl;
	return 0;
}

//algoritam pretvara 3^5 u 3^4 * 3

//primer: broj 5 bitovski je 101
//i0=0: 101 & 1 = 1, posto je = 1 onda imamo i-ti stepen dvojke, a 101 -> 10
//i1=1: 10 & 1 = 0, nije = 1 pa nemamo stepen dvojke, 10 -> 1
//i2=2: 1 & 1 = 1, jos jedan stepen i-ti stepen dvojke, 1 -> 0 i zavrsava se petlja
//sledi 5 = 2^i2 + 2^i0 = 4 + 1
//ovo su zapravo stepeni broja a