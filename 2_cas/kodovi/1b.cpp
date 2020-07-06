#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#define CHAR_SIZE 128

using namespace std;

struct Node{
  bool is_leaf;
  unordered_map<char, Node *> nodes;
};

Node *create_node(){
	Node *new_node = new Node();

  // Inicijalno nijedan cvor nije list
	new_node->is_leaf = false;

	return new_node;
}

void add_word(Node *root, string &word, int i){
  // Ukoliko smo dosli do kraja reci, to znaci da je cvor u kome se trenutno nalazimo i list, tj predstavlja kraj reci, oznacavamo to i zavrsavamo rekurziju,
  // jer je cela rec dodata u stablo
  if (i == (int)word.size()) {
    root->is_leaf = true;
    return ;
  }

  // Trazimo cvor (granu) niz koju vodi odgovarajuce slovo reci, recimo da nam je rec KUCA i da imamo granu iz korena niz koju ide slovo K, a zatim
  //iz odgovarajuceg cvora granu niz koju ide slovo U trazimo u odgovarajucem cvoru granu niz koju vodi C, dakle u mapi trazimo par ciji je kljuc bas slovo C (i-to slovo reci word)
  auto iterator = root->nodes.find(word[i]);

  // // Ukoliko element ne postoji, zelimo da ga dodamo u stablo. Ako imamo K->U zelimo da nakon U dodamo i C. Zato pravimo novi cvor sa odgovarajucom oznakom
  if (iterator == root->nodes.end())
    root->nodes[word[i]] = create_node();

  add_word(root->nodes[word[i]], word, i + 1);
}

bool find_word(Node *root, string &word, int i){
  // Ukoliko smo dosli do cvora koji cuva kraj reci vracamo true, jer se rec nalazi u stablu
  if (i == (int)word.size()) {
    // Primetimo da ovde NE SMEMO da vracamo true, jer mozda se rec iz stabla ne zavrsava ovde.
    // Neka u stablu imamo reci cod, i coder, cvorovi koji su listovi su cvor u koji ulazi D i cvor u koji ulazi R.
    // Sada zamislimo da trazimo rec code, ukoliko u ovom if-u vracamo true a ne root->is_leaf, reci cemo da rec code postoji u stablu, sto nije tacno
    return root->is_leaf;
  }

  // Trazimo odgovarajuci cvor
  auto iterator = root->nodes.find(word[i]);

  // Ukoliko ga nema, znaci da rec ne postoji u stablu
  if (iterator == root->nodes.end())
    return false;

  // Ukoliko se i-to slovo nalazi u reci, vracamo ono sto nam vraca rekurzivni poziv za i + 1, ako je negde nadjena rec imacemo true, inace, u nekom od kasnijih rekurzivnih poziva smo
  // vratili false, pa cemo i sad to uraditi
  return find_word(root->nodes[word[i]], word, i + 1);
}

void free_tree(Node *root)
{
  if (root == nullptr)
    return ;

  // Prvo oslobadjamo sva podstabla datog korena
  for (auto &p : root->nodes)
    free_tree(p.second);

  // A nakon toga i sam koren. Alokacija je vrsena pomocu new pa oslobadjanje mora pomocu delete
  delete root;
}

int main (){
  vector<string> words = {"cod", "coder", "coding", "codecs"};

  Node *root = create_node();

  for (string &s : words)
    add_word(root, s, 0);

  string s = "code";

  // boolalpha nam omogucava da pisemo true i false a ne 0 ili 1
  cout << boolalpha << find_word(root, s, 0) << endl;

  free_tree(root);

  return 0;
}