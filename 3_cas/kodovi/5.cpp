#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void build_segment_tree(vector<int> &array, vector<int> &segment_tree, int k, int x, int y){
    if(x == y){
        segment_tree[k] = array[x]*array[x];
        return;
    }

    int middle = (x + y) / 2;

    build_segment_tree(array, segment_tree, 2*k + 1, x, middle);
    build_segment_tree(array, segment_tree, 2*k + 2, middle + 1 , y);

    segment_tree[k] = segment_tree[2*k + 1] + segment_tree[2*k + 2]; //za k=0 je ovo dodela vrednosti korenu
}

int sum_of_squares(vector<int> &segment_tree, int a, int b, int x, int y, int k){
    if(x>b || y<a)
        return 0;
    if(x>=a && y<=b)
        return segment_tree[k];
    
    int middle = (x + y) / 2;
    return sum_of_squares(segment_tree, a, b, x, middle, 2*k + 1) + sum_of_squares(segment_tree, a, b, middle + 1, 2*k + 2);
}

int main(){
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int n = array.size();
    int height = ceil(log2(n));

    int size = 2 * pow(2, height) - 1;
    vector<int> segment_tree(size);

    build_segment_tree(array, segment_tree, 0, 0, n-1);

    cin >> a >> b;

    cout << sum_of_squares(segment_tree, a, b, 0, n-1, 0) << endl;

    return 0;
}