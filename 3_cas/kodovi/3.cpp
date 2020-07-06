#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void build_segment_tree(vector<int> &array, vector<int> &segment_tree, int k, int x, int y){
    if(x == y){
        segment_tree[k] = array[x];
        return;
    }

    int middle = (x + y) / 2;

    build_segment_tree(array, segment_tree, 2*k + 1, x, middle);
    build_segment_tree(array, segment_tree, 2*k + 2, middle + 1 , y);

    segment_tree[k] = segment_tree[2*k + 1] + segment_tree[2*k + 2]; //za k=0 je ovo dodela vrednosti korenu
}

void update_tree(vector<int> &segment_tree, int k, int x, int y, int index, int new_value){
    if(x == y){
        segment_tree[k] = new_value;
        return;
    }

    int middle = (x+y)/2;

    if(index <= middle)
        update_tree(segment_tree, 2*k+1, x, middle, index, new_value);
    else
        update_tree(segment_tree, 2*k+2, middle+1, y, index, new_value);
    
    segment_tree[k] = segment_tree[2*k+1] + segment_tree[2*k+2];
}

int main(){
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int n = array.size();
    int height = ceil(log2(n));

    int size = 2 * pow(2, height) - 1;
    vector<int> segment_tree(size);

    build_segment_tree(array, segment_tree, 0, 0, n-1);

    for(int x : segment_tree)
        cout << x << " ";
    cout << endl;

    update_tree(segment_tree, 0, 0, n - 1, 2, 8);

    for(int x : segment_tree)
        cout << x << " ";
    cout << endl;

    return 0;
}