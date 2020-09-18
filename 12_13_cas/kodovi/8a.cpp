#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Point{
    int x;
    int y;
};

Point p_0;

void swap(Point &p1, Point &p2){
	Point tmp = p1;
	p1 = p2;
	p2 = tmp;
}

// AB = B.x-A.x; B.y-A.y


int orientation(Point& p_0, Point& p1, Point& p2){
	int orient = (p1.x - p_0.x)*(p2.y - p_0.y) - (p1.y - p_0.y)*(p2.x - p_0.x);

	if(!orient)
		return 0;

	return (orient>0) ?  1 : 2; // 1-pozitivna orijentacija 2-negativna orijentacija
}								// smer suprotan kazaljci   smer obrnut kazaljci

bool compare(Point& p1, Point& p2){
	int orient = orientation(p_0, p1, p2);

	if(!orient){
		cout << "YES!\n";
		exit(EXIT_SUCCESS);
	}

	return orient == 1;
}

void three_colinear(vector<Point>& points){
    int n = points.size();

    for(int i=0; i<n; i++){
        swap(points[0], points[i]);
	p_0 = points[0];
	sort(points.begin() + 1, points.end(), compare);
    }
}

int main (){
	vector<Point> points = {{0, 0}, {1, 0}, {2, 4}, {5, 9}, {4, 7}, {7, 2}, {1, 4}, {2, 2}};

	three_colinear(points);

	cout << "NO! :(\n";
	int n = points.size();
	for(int i = 0; i<n; i++){
		cout << points[i].x << " " << points[i].y << endl;
	}
	return 0;
}
