#include <iostream>
#include "splash.hpp"
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <Point2D> points;
	Point2D temp;
	for (int i = 0; i < n; ++i)
	{ 
		cin >> temp;
		points.push_back(temp);
	}
	//Convex2D convex(points);
	//convex.MakeConvexHullJarvis(points);
	
	return 0;
}