#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node{
    long largest;
    long second_largest;
};

void build_segment_tree(vector<int>& array, vector<Node>& segment_tree, int k, int x, int y){
    if(x == y){
        segment_tree[k].largest = array[x];
        segment_tree[k].second_largest = INT32_MIN;
        return;
    }

    int middle = (x+y)/2;

    build_segment_tree(array, segment_tree, 2*k+1, 0, middle);
    build_segment_tree(array, segment_tree, 2*k+2, middle+1, y);

    segment_tree[k].largest = max(segment_tree[2*k+1].largest, segment_tree[2*k+2].largest);
    segment_tree[k].second_largest = min(max(segment_tree[2*k+1].largest, segment_tree[2*k+2].second_largest),
                                         max(segment_tree[2*k+2].largest, segment_tree[2*k+1].second_largest));
}

Node find_max_product_in_segment(vector<Node>& segment_tree, int k, int x, int y, int a, int b){
    
    Node result;
    result.largest = INT32_MIN;
    result.second_largest = INT32_MIN;
    
    if(a > y || b < x)
        return result;

    if(x >= a && y <= b)
        return segment_tree[k];

    int middle = (x+y)/2;

    Node left = find_max_product_in_segment(segment_tree, 2*k+1, 0, middle, a, b);
    Node right = find_max_product_in_segment(segment_tree, 2*k+2, middle+1, y, a, b);

    result.largest = max(left.largest, right.largest);
    result.second_largest = min(max(left.largest, right.second_largest),
                                max(right.largest, left.second_largest));

    return result;
}

int main(){
    vector<int> array = {1, 3, 4, 2, 5};

    int n = array.size();
    int height = ceil(log2(n));
    int size = 2 * pow(2,height) - 1;

    vector<Node> segment_tree(size);

    build_segment_tree(array, segment_tree, 0, 0, n-1);

    Node result = find_max_product_in_segment(segment_tree, 0, 0, n-1, 0, 2);

    cout << result.largest * result.second_largest << endl;

    return 0;
}