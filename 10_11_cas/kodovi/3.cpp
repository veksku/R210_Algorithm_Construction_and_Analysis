#include <iostream>
#include <vector>

using namespace std;

void compute_preffix_table(string &pattern, vector<int> &preffix_table, int n){
    
    int i = 1, j = 0;

    while(i < n){
        if(pattern[j] == pattern[i]){
            preffix_table[i] = ++j;
            i++;
        }
        else{
            if(j != 0){
                j = preffix_table[j-1]; //najbitnija dodela u kodu, ostatak je logican
            }
            else{
                preffix_table[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string &text, string &pattern){

    int m = text.size();
    int n = pattern.size();

    vector<int> preffix_table(n);

    compute_preffix_table(pattern, preffix_table, n);

    int i = 0, j = 0;

    while(i < m){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j == n){
            cout << "Pattern found\n";
            return;
        }

        if(i < m && text[i] != pattern[j]){
            if(j != 0)
                j = preffix_table[j-1]; //najbitnija dodela u kodu, ostatak je logican
            else
                i++;
        }

    }
}

int main (){

  string text = "abcabcabcabcabcabcabcd";

  string pattern = "abcabcabcd";

  KMP(text, pattern);

  return 0;
}
