#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct Node{
  bool is_leaf;
  unordered_map<char, Node*> nodes;
};

Node* create_node(){
    Node* new_node = new Node();
    
    new_node->is_leaf = false;

    return new_node;
}

void add_word(Node* root, string/*&*/ word, int i){
    if(i == (int)word.size()){
        root->is_leaf = true;
        return;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();

    add_word(root->nodes[word[i]], word, i+1);
}

void longest_common_preffix(Node* root, string& lcp){
    while(root && !root->is_leaf && root->nodes.size() == 1){
        auto element = root->nodes.begin();
        lcp += element->first;
        root = element->second;
    }
}

void free_tree(Node* root){
    if(!root)
        return;

    for(auto &p : root->nodes)
        free_tree(p.second);

    delete root;
}

int main ()
{
//   vector<string> words = {"code", "coder", "coding", "codable", "codec", "codecs", "coded",
// 		"codeless", "codec", "codecs", "codependence", "codex", "codify",
// 		"codependents", "codes", "code", "coder", "codesign", "codec",
// 		"codeveloper", "codrive", "codec", "codecs", "codiscovered"};

  // Probati ovaj skup reci i izbaciti uslov u petlji !root->is_leaf
  vector<string> words = {"ana", "anastasija", "anastasijin"};

  Node *root = create_node();

  for (string &s : words)
    add_word(root, s, 0);

  string lcp = "";

  longest_common_preffix(root, lcp);

  cout << lcp << endl;

  free_tree(root);

  return 0;
}
