#include <vector>
#include <iostream>
#include <algorithm>

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

int find_extreme_index(vector<Point>& points){
    int index = 0, max_x = points[0].x, min_y = points[0].y;

    int n = points.size();

    for(int i=1; i<n; i++){
        if(max_x < points[i].x){
            max_x = points[i].x;
            min_y = points[i].y;
            index = i;
        }
        else if(max_x = points[i].x)
            if(min_y > points[i].y){
                min_y = points[i].y;
                index = i;
            }
    }

    return index;
}

int orientation(Point p_0, Point p1, Point p2){
    int orient = (p1.x - p_0.x)*(p2.y - p_0.y) - (p1.y - p_0.y)*(p2.x - p_0.x);

    if(!orient)
        return 0;

    return (orient>0) ? 1 : 2; //pozitivna, negativna orijentacija
}

int distance(Point p, Point q){
    return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

bool compare(const Point &p1, const Point &p2){
    int orient = orientation(p_0, p1, p2);

    if(orient == 1)
        return true;
    else if(orient == 2)
        return false;
    else
        return distance(p_0, p1) < distance(p_0, p2);
}

void simple_polygon(vector<Point>& points){
    int index = find_extreme_index(points);

    swap(points[0], points[index]);
    p_0 = points[0];

    sort(points.begin() + 1, points.end(), compare);

    vector<Point> result;

    result.push_back(points[0]);
    result.push_back(points[1]);

    int n = points.size();
    int m = 1; //indeks poslednjeg elementa u vektoru result

    for (int k = 2; k < n; k++) {
        while(m > 1 && orientation(points[k], result[m], result[m-1]) != 2){
            m--;
            result.pop_back();
        }

        m++;
        result.push_back(points[k]);
    }

    for(auto p : result)
        cout << p.x << " " << p.y << endl;
}

int main(){
    vector<Point> points = { {0, 0}, {12, 2}, {9, 3}, {8, 7}, {5, 3}, {3, 6}, {1, 4}, {14, 0} };

    simple_polygon(points);

    return 0;
}