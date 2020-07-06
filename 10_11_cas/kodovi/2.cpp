#include <iostream>
#include <vector>

using namespace std;
    
vector<int> izracunajZNiz(const string &s, int n){
    vector<int> z(n);

    int l = 0, d = 0;

    for(int i=1; i<n; i++){
        if(i <= d)
            z[i] = min(d-i+1, z[i-l]);
        
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;

        if (i+z[i]-1 > d) {
            l = i;
            d = i+z[i]-1;
        }
    }
    return z;
}

int main(){
    string niz;
    cout << "Unesi nisku 'iglu', specijalan karakter i nisku 'plast sena'\n";
    cin >> niz;

    char special;
    cout << "Unesi specijalan karakter\n";
    cin >> special;

    int j=0;

    while(niz[j] != special)
        j++;

    //string niz="CDA#ACBACDACBACBACDA";
    int n=niz.size();
    vector<int> zNiz = izracunajZNiz(niz, n);
    
    for (int i=0; i<n; i++) {
        if (zNiz[i] == j)
          cout << i - j - 1 << endl;
    }
    
    return 0;
}