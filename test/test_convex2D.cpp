#include <algorithm>
#include <iostream>

#include "../splash.hpp"

using namespace std;

int TestConvex2D()
{
	Convex2D conv1, conv2;
	int n1;
///////
	cout << "Constructor test:\n";

	cout << "Enter the number of vertices:\n";
	cin >> n1;
	cout << "Enter the vertices:\n";
	vector<Point2D> points(n1);
	for (int i = 0; i < n1; ++i)
		cin >> points[i];
	cout << "Convex polygon vertices are:\n";
	for (auto i : conv1.GetVertices())
		cout << i << "\n";
/*
	cout << "Enter the number of vertices:\n";
	cin >> n2;
	cout << "Enter the vertices:\n";
	points.clear();
	points.resize(n2);
	for (int i = 0; i < n2; ++i)
		cin >> points[i];
	cout << "Convex polygon vertices are:\n";
	for (auto i : conv2.GetVertices())
		cout << i << "\n";
*/
///////
	cout << "ConvexHull test:\n";
	cout << "Enter the number of points:\n";
	cin >> n1;
	cout << "Enter the vertices:\n";
	points.clear();
	points.resize(n1);
	for (int i = 0; i < n1; ++i)
		cin >> points[i];
	conv1 = conv1.MakeConvexHullGrehem(points);
	cout << "ConvexHull vertices are:\n";
	for (auto i : conv1.GetVertices())
		cout << i << "\n";

	return 0;
}