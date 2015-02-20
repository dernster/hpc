#include "KdTree.h"
#include <iostream>
using namespace std;

bool vectorEquals(const vector<Point*>& a, const vector<Point*>& b){
	if (a.size() != b.size())
		return false;

	for(unsigned int i = 0; i < a.size(); i++){
		if (*a[i] != *b[i])
			return false;
	}

	return true;
}

void printVector(const vector<Point*>& a){
	for(unsigned int i = 0; i < a.size(); i++){
		cout << *a[i] << endl;
	}
}

int main(){

	vector<Point*> points;
	points.push_back(new Point(0,1,2));
	points.push_back(new Point(3,2,2));
	points.push_back(new Point(13,6,4));
	points.push_back(new Point(7,7,9));
	points.push_back(new Point(7.1,7,9));
	points.push_back(new Point(13,50,3));
	points.push_back(new Point(136,5.50,3));
	points.push_back(new Point(-3,6,7));
	points.push_back(new Point(-90,8,15));
	points.push_back(new Point(14,8,30));
	points.push_back(new Point(136,5.50,3));

	KdTree tree(points);
	vector<Point*> neighbours, neighboursTest;
	bool success = true;
	for(int maxNeighbours = 1; maxNeighbours < 12; maxNeighbours++){
		for(double maxRadius = 0; maxRadius < 100; maxRadius += 2){
			cout << "Test for maxNeighbours = " << maxNeighbours << " and maxRadius = " << maxRadius << endl;

			for(unsigned int p = 0; p < points.size(); p++){
				Point* testPoint = points[p];

				neighbours.clear();
				neighboursTest.clear();

				tree.searchNeighbours(testPoint,&neighbours,maxNeighbours);
				tree.searchNeighboursTest(testPoint,&neighboursTest,maxNeighbours);

				success = success && vectorEquals(neighbours,neighboursTest);

				if (!success){
					cout << "ERROR! point = " << p << endl;
					cout << "normal:" << endl;
					printVector(neighbours);
					cout << "......." << endl;
					printVector(neighboursTest);
					break;
				}
			}
		}

		if (!success)
			break;

		cout << "SABELO!" << endl;
	}

	if (success)
		cout << "TODO BIEN!" << endl;
	else
		cout << "TODO MAL!" << endl;



	return 0;

}
