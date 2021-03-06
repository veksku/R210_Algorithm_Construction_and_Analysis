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

int sum_of_segment(vector<int> &segment_tree, int x, int y, int a, int b, int k){
    if(x > b || y < a){
        return 0;
    }
    if(x >= a && y <= b)
        return segment_tree[k];

    int middle = (x + y) / 2;

    return sum_of_segment(segment_tree, x, middle, a, b, 2*k+1) + sum_of_segment(segment_tree, middle + 1, y, a, b, 2*k+2);
}

int main(){
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int n = array.size();
    int height = ceil(log2(n));

    int size = 2 * pow(2, height) - 1;
    vector<int> segment_tree(size);

    build_segment_tree(array, segment_tree, 0, 0, n-1);

    cout << sum_of_segment(segment_tree, 0, n - 1, 0, 2, 0) << "\n";

    return 0;
}