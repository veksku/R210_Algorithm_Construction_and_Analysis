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

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
		return 0;

	return (val > 0) ? 1: 2; // clock or counterclock wise
}

bool compare(const Point &p1, const Point &p2){

	int orient = orientation(p_0, p1, p2);
    
	if (!orient) {
		cout << "YES! :)\n";
		exit(EXIT_SUCCESS);
	}

	// Ako je orijentacija tacaka suprotna od smera kretanja kazaljke na satu onda vracamo true jer je tacka p1 pre tacke p2 u sortiranom poretku,
	// inace vracamo false
	return orient == 2;
}

void three_colinear(vector<Point> &points){

	int n = points.size();

	for (int i = 0; i < n; i++) {
		swap(points[0], points[i]);
		p_0.x = points[0].x;
        p_0.y = points[0].y;
		sort(points.begin() + 1, points.end(), compare);
	}
}

int main (){

	vector<Point> points = {{0, 0}, {1, 3}, {2, 5}, {4, 7}, {5, 9}, {7, 2}, {1, 5}, {2, 2}};

	three_colinear(points);

	cout << "NO! :(\n";

	return 0;
}