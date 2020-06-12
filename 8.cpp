#include <iostream>
#include <algorithm>
#include <vector>

struct Point{
	int x;
	int y;
};

// Tacka u odnosu na koju se racunaju uglovi pri sortiranju tacaka
Point p_0;

void swap(Point &p1, Point &p2)
{
	Point tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	if (val == 0)
		return 0;

	return (val > 0) ? 1: 2; // clock or counterclock wise
}

bool compare(const Point &p1, const Point &p2)
{
	int orient = orientation(p_0, p1, p2);

	// Ako su kolinearne dovoljno je ispisati poruku o tome i zavrsiti rad programa
	if (!orient) {
		std::cout << "YES! :)\n";
		exit(EXIT_SUCCESS);
	}

	// Ako je orijentacija tacaka suprotna od smera kretanja kazaljke na satu onda vracamo true jer je tacka p1 pre tacke p2 u sortiranom poretku,
	// inace vracamo false
	return orient == 2;
}

void three_colinear(std::vector<Point> &points)
{
	int n = points.size();

	for (int i = 0; i < n; i++) {
		swap(points[0], points[i]);
		p_0 = points[0];
		std::sort(points.begin() + 1, points.end(), compare);
	}
}

int main ()
{
	std::vector<Point> points = {{0, 0}, {1, 3}, {2, 5}, {4, 7}, {5, 9}, {7, 2}, {1, 1}, {2, 2}};

	three_colinear(points);

	// Ako smo dosli do ovde to znaci da nije bilo kolinearnih tacaka, jer bi u suprotnom izvrsavanje bilo zavrseno jos u funkciji compare
	std::cout << "NO! :(\n";

	return 0;
}
