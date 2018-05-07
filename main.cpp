#include <iostream>

#include "splash.hpp"
using namespace std;

int main()
{
	//TestConvex2D();
	int n;
	cin >> n;
	vector <Point2D> points;
	Point2D temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		points.push_back(temp);
	}
	Convex2D convex;
	points = convex.MakeConvexHullGrehem(points);
	for (int i = 0; i < points.size(); ++i)
		cout << points[i] << endl;
	return 0;
}