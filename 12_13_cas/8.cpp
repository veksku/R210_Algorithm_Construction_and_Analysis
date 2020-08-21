#include <iostream>
#include <algorithm>
#include <vector>

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

int orientation(Point p, Point q, Point r){
	int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	if (val == 0)
		return 0;
    else
	    return (val > 0) ? 1: 2; // clockwise or counterclockwise
}

bool compare(const Point &p1, const Point &p2){
	int orient = orientation(p_0, p1, p2);

	if (!orient) {
		cout << "YES! :)\n";
		exit(EXIT_SUCCESS);
	}

	return orient == 2;
}

void three_colinear(vector<Point> &points){
	int n = points.size();

	for (int i = 0; i < n; i++) {
		swap(points[0], points[i]);
		p_0 = points[0];
		sort(points.begin() + 1, points.end(), compare);
	}
}

int main (){
	vector<Point> points = {{0, 0}, {1, 0}, {2, 4}, {4, 7}, {5, 9}, {7, 2}, {1, 4}, {2, 2}};

	three_colinear(points);

	cout << "NO! :(\n";
	int n = points.size();
	for(int i = 0; i<n; i++){
		cout << points[i].x << " " << points[i].y << endl;
	}
	return 0;
}
