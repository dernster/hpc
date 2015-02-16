#include "KdTree.h"
#include <iostream>
using namespace std;

int main(){

	vector<Point*> points;
	points.push_back(new Point(0,1,2));
	points.push_back(new Point(3,2,2));
	points.push_back(new Point(13,6,4));
	points.push_back(new Point(7,7,9));
	points.push_back(new Point(13,50,3));
	points.push_back(new Point(-3,6,7));
	points.push_back(new Point(-90,8,15));
	points.push_back(new Point(14,8,30));


	KdTree tree(points);

	cout << tree << endl;


	return 0;

}
