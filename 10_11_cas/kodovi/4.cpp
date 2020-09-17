#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void manacher(string &string){

  string pom = "$";

  int n = string.size();

  for (int i = 0; i < n; i++) {
    pom += "#";
    pom += string[i];
  }

  pom += "#@";

  int C = 1, R = 1;

  vector<int> pom_vector(pom.size());

  int mirror;

  n = pom.size();

  for (int i = 1; i < n - 1; i++) {
    mirror = 2 * C - i;

    if (i < R)
      pom_vector[i] = min(R - i, pom_vector[mirror]);

    while (pom[i + (pom_vector[i] + 1)] == pom[i - (pom_vector[i] + 1)])
      pom_vector[i]++;

    if (i + pom_vector[i] > R) {
      C = i;
      R = i + pom_vector[i];
    }
  }
  int max_position = max_element(pom_vector.begin(), pom_vector.end()) - pom_vector.begin();
  int max = pom_vector[max_position];

  int start = max_position - max + 1;

  string result = "";

  int end = start + 2 * max;

  for (int i = start; i < end; i += 2)
    result += pom[i];

  cout << result << endl;
}

int main (){
  string s = "aaaaaaaaaacabaabad";

  manacher(s);

  return 0;
}
