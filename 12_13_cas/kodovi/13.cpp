#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point{
	int x;
	int y;
};

bool compare(const Point &p_1, const Point &p_2){
  if (p_1.x == p_2.x) {
    return p_1.y < p_2.y;
  }

  return p_1.x < p_2.x;
}

ostream &operator<<(ostream &out, Point &p){
  out << p.x << " " << p.y << " ";
  return out;
}

// Funkcija koja odredjuje koordinate potencijalnih temena kvadrata ako imamo temena A i B
// Za vise informacija o formuli posetite
// https://math.stackexchange.com/questions/964625/find-3rd-and-4th-co-ordinates-for-a-square-given-co-ordinates-of-two-points
void find_coordinates (const Point &a, const Point &b, Point &c, Point &c_1, Point &d, Point &d_1){
    int delta_x = b.x - a.x;
    int delta_y = b.y - a.y;

    c.x = (b.x + delta_y);
    c_1.x = (b.x - delta_y);

    c.y = (b.y - delta_x);
    c_1.y = (b.y + delta_x);

    d.x = (a.x + delta_y);
    d_1.x = (a.x - delta_y);

    d.y = (a.y - delta_x);
    d_1.y = (a.y + delta_x);
}

bool check_for_vertices (vector<Point> &points, const Point &c, const Point &c_1, const Point &d, const Point &d_1){
    return (binary_search(points.begin(), points.end(), c, compare) && binary_search(points.begin(), points.end(), d, compare)) ||
         (binary_search(points.begin(), points.end(), c_1, compare) && binary_search(points.begin(), points.end(), d_1, compare));
}

bool is_there_square(vector<Point> &points){
    // Sortiramo tacke rastuce po x (pa ako ima vise sa istom x koordinatom onda po y koordinati)
    sort(points.begin(), points.end(), compare);

    int n = points.size();

    // Preostala temena potencijalnog kvadrata, mozemo imati 2 kvadrata cija su 2 temena A i B
    Point c, d, c_1, d_1;

    // Idemo kroz sve parove tacaka (ne racunamo tacku i nju samo kao par)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;

        // Odredjujemo koordinate potencijalnih preostalih temena
        find_coordinates(points[i], points[j], c, c_1, d, d_1);

        // Ako postoje tacke sa odgovarajucim temenima u skupu tacaka samo vracamo true kao indikator da postoje 4 tacke koje formiraju kvadrat
        if (check_for_vertices(points, c, c_1, d, d_1))
            return true;
        }
    }

    // Ako smo prosli kroz sve parove i nismo nasli 4 tacke koje formiraju kvadrat, vracamo false
    return false;
}

int main ()
{
    // {2, 0}, {1, 1}, {8, 19}, {2, 14}

    vector<Point> points = { {0, 3}, {2, 2}, {6, 4}, {1, 1}, {2, 1}, {2, 5}, {3, 0}, {0, 0}, {3, 3} };

    // boolalpha omogucava da ispisujemo true/false umesto 0/1 kada je u pitanju boolean vrednost
    cout << boolalpha << is_there_square(points) << "\n";

    return 0;
}
