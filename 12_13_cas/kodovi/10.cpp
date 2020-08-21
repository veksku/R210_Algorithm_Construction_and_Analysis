#include <iostream>
#include <vector>
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

int find_extreme_point(std::vector<Point> &points){
    int max_x = points[0].x, min_y = points[0].y, index = 0;

    int n = points.size();

    for (int i = 1; i < n; i++) {
        if (points[i].x > max_x) {
            max_x = points[i].x;
            min_y = points[i].y;
            index = i;
        }
        else if (points[i].x == max_x) {
            if (points[i].y < min_y) {
                min_y = points[i].y;
                index = i;
            }
        }
    }

    return index;
}

int distance(const Point &p_1, const Point &p_2){
    return (p_1.x - p_2.x)*(p_1.x - p_2.x) + (p_1.y - p_2.y)*(p_1.y - p_2.y);
}

int orientation(Point p, Point q, Point r){
	int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	if (val == 0)
		return 0;
    else
	    return (val > 0) ? 1: 2; // clock or counterclock wise
}

bool compare(const Point &p1, const Point &p2){
	int orient = orientation(p_0, p1, p2);

	if (orient == 2) 
        return true; //p1 ce biti pre p2 u poretku
    else if(orient == 1)
        return false; //p2 ce biti pre p1 u poretku

	// Ako je orijentacija tacaka suprotna od smera kretanja kazaljke na satu onda vracamo true jer je tacka p1 pre tacke p2 u sortiranom poretku,
	// inace vracamo false
	return distance(p_0, p1) < distance(p_0, p2);
}

void simple_polygon(vector<Point> &points){
    int extreme_index = find_extreme_point(points);

    swap(points[0], points[extreme_index]);

    p_0 = points[0];

    // Sortiramo po uglu ili po udaljenosti od tacke p_0 ako je ugao isti
    sort(points.begin() + 1, points.end(), compare); //ovo je rotiranje prave u krug

    vector<Point> result;

    result.push_back(points[0]);
    result.push_back(points[1]); //prva tacka na koju se naidje rotacijom prave uvek pripada konveksnom omotacu
  
    int n = points.size();
    int m = 1;

    for (int k = 2; k < n; k++) {
        // Ako naidjemo na neku tacku takvu r takvu da vazi da izmedju poslednje 2 dodate tacke p, q i tacke r vazi orijentacija u smeru kretanja kazaljke na satu,
        // to znaci da poslednje dodatu tacku treba izbaciti iz resenja (za bolje i detaljnije objasnjenje pogledati skriptu profesorke Vesne)
        while (result.size() > 2 && orientation(result[m - 1], result[m], points[k]) != 2) {
            // Izbacujemo poslednje dodatu tacku
            result.pop_back();
            m--;
        }

        // Dodajemo novu tacku u omotac pa uvecavamo brojac koji ih broji
        m++;
        // Dodajemo bas novu tacku do koje smo dosli
        result.push_back(points[k]);
    }

    for (Point &p : result)
        cout << p.x << " " << p.y << endl;
}

int main(){
    vector<Point> points = { {0, 0}, {12, 2}, {9, 3}, {8, 7}, {5, 3}, {3, 6}, {1, 4}, {14, 0} };

    simple_polygon(points);

    return 0;
}