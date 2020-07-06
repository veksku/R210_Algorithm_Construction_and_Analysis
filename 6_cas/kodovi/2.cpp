#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node{
    Node (){
        left = right = nullptr;
    }
    int key;
    Node *left;
    Node *right;
};

void add_node(Node **root, int key){
    if(**root == nullptr){
        *root = new Node();
        (*root)->key = key;
        return ;
    }

    if((*root)->key > key)
        add_node(&(*root)->left, key);
    else
        add_node(&(*root)->right, key);
}

void free_tree(Node *root){
    if(root == nullptr)
        return;
    free_tree(root->left);
    free_tree(root->right);

    delete root;
}

void BFS(Node *root, vector<int> &levels){
    queue<Node *> nodes;
    nodes.push(root);

    levels[root->key] = 0;

    int current_level = 0;

    Node *pom;

    while(nodes.size()){
        pom = nodes.front();
        nodes.pop();

        if(pom->left){
            levels[pom->left->key] = levels[pom->key] + 1;
            nodes.push(pom->left);
        }
        if(pom->right){
            levels[pom->right->key] = levels[pom->key] + 1;
            nodes.push(pom->right);
        }
        if(levels[pom->key] != current_level){
            cout << "\n";
            current_level++;
        }
        cout << pom->key << " ";
    }
}

int main (){
    Node *root = nullptr;

    vector<int> keys = {4, 3, 5, 7, 1, 9, 8, 6};

    for (int x : keys)
        add_node(&root, x);

    int n = *max_element(keys.begin(), keys.end());

    vector<int> levels(n);

    BFS(root, levels);

    cout << "\n";
    
    free_tree(root);

    return 0;
}