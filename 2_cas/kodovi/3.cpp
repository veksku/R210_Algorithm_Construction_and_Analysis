#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    string word;
    map<char, Node*> nodes;
};

Node* create_node(){
    Node* new_node = new Node();
    new_node->word = "";
    return new_node;
}

void add_word(Node* root, string& word, int i){
    if(i == (int)word.size()){
        root->word = word;
        return;
    }

    auto iterator = root->nodes.find(word[i]);

    if(iterator == root->nodes.end())
        root->nodes[word[i]] = create_node();

    add_word(root->nodes[word[i]], word, i+1);
}

void lexicographic(Node* root, stack<string>& result){
    if (root->word != "")
        result.push(root->word);

    auto begin = root->nodes.begin();
    auto end = root->nodes.end();

    while(begin != end){
        lexicographic(begin->second, result);
        begin++;
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
  vector<string> words =
	{
		"lexicographic", "sorting", "of", "a", "set", "of", "keys", "can",
		"be", "accomplished", "with", "a", "simple", "trie", "based",
		"algorithm", "we", "insert", "all", "keys", "in", "a", "trie",
		"output", "all", "keys", "in", "the", "trie", "by", "means", "of",
		"preorder", "traversal", "which", "results", "in", "output", "that",
		"is", "in", "lexicographically", "increasing", "order", "preorder",
		"traversal", "is", "a", "kind", "of", "depth", "first", "traversal"
	};
  // vector<string> words = {"ana", "anastasija", "anastasijin", "anamarija", "anamarijin"};

  Node *root = create_node();

  for (string &s : words)
    add_word(root, s, 0);
  
  stack<string> result;

  lexicographic(root, result);
  
  while(!result.empty()){
      cout << result.top() << endl;
      result.pop();
  }

  free_tree(root);

  return 0;
}