#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Segment{
    int begin, end;
};

// Funkcija compare omogucava da se intervali sortiraju rastuce po pocecima a opadajuce po krajevima
// Zasto opadajuce? Razmotriti slucaj a = [5, 8], b = [5,12]. Ako ide rastuce, a ce biti pre b i algoritam nece
// naci da se a nalazi unutar b
bool compare(const Segment &s1, const Segment &s2){
	if (s1.begin == s2.begin)
		return s1.end > s2.end;

	return s1.begin < s2.begin;
}

void sort_segments(vector<Segment> &segments){
	sort(segments.begin(), segments.end(), compare);
}

void find_all_segments(vector<Segment> &segments){
	int max = segments[0].end;

	int n = segments.size();

	for (int i = 1; i < n; i++)
		if (segments[i].end <= max)
			cout << "[" << segments[i].begin << ", " << segments[i].end << "]\n";
		else
			max = segments[i].end;
}

int main(){
	// {1, 2}, {1, 5}, {6, 8}, {6, 9}
	vector<Segment> segments = {{1, 2}, {1, 5}, {2, 7}, {3, 9}, {2, 4}, {6, 8}, {5, 8}};

	sort_segments(segments);

	find_all_segments(segments);

	return 0;
}