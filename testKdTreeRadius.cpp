//#include "KdTree.h"
//#include <iostream>
//using namespace std;
//
//bool vectorEquals(const vector<Point*>& a, const vector<Point*>& b){
//	if (a.size() != b.size())
//		return false;
//
//	if (a.size() == 0)
//		return true;
//
//	for(unsigned int i = 0; i < a.size(); i++){
//
//		bool existe = false;
//		for(unsigned int j = 0; j < b.size(); j++){
//			if (existe = (*a[i] == *b[j]))
//				break;
//		}
//
//		if (!existe)
//			return false;
//	}
//
//	return true;
//}
//
//void printVector(const vector<Point*>& a){
//	for(unsigned int i = 0; i < a.size(); i++){
//		cout << *a[i] << endl;
//	}
//}
//
//int main(){
//
//	vector<Point*> points;
//	points.push_back(new Point(0,1,2));
//	points.push_back(new Point(3,2,2));
//	points.push_back(new Point(13,6,4));
//	points.push_back(new Point(7,7,9));
//	points.push_back(new Point(7.1,7,9));
//	points.push_back(new Point(13,50,3));
//	points.push_back(new Point(136,5.50,3));
//	points.push_back(new Point(-3,6,7));
//	points.push_back(new Point(-90,8,15));
//	points.push_back(new Point(14,8,30));
//	points.push_back(new Point(136,5.50,3));
//
//	KdTree tree(points);
//
//	vector<Point*> neighbours, neighboursTest;
//
//	bool success = true;
//
//	for(double maxRadius = 0; maxRadius < 100; maxRadius += 0.2){
//		cout << "Test for maxRadius = " << maxRadius << endl;
//
//		for(unsigned int p = 0; p < points.size(); p++){
//			Point* testPoint = points[p];
//
//			neighbours.clear();
//			neighboursTest.clear();
//
//			tree.searchNeighboursRadius(testPoint,&neighbours,maxRadius);
//			tree.searchNeighboursRadiusTest(testPoint,&neighboursTest,maxRadius);
//
//			success = success && vectorEquals(neighbours,neighboursTest);
//
//			if (!success){
//				cout << "ERROR! point = " << p << endl;
//				cout << "normal:" << endl;
//				printVector(neighbours);
//				cout << "......." << endl;
//				printVector(neighboursTest);
//				break;
//			}
//		}
//	}
//
//	if (success)
//		cout << "TODO BIEN!" << endl;
//	else
//		cout << "TODO MAL!" << endl;
//
//
//
//	return 0;
//
//}
