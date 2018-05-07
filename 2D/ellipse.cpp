// Splash (c) - open-source C++ library for geometry and linear algebra.
// Copyright (c) 2016, Ilya Zakharkin, Elena Kirilenko and Nadezhda Kasimova.
// All rights reserved.
/*
	This file is part of Splash.

	Splash is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Splash is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Splash. If not, see <http://www.gnu.org/licenses/>.
*/
#include "ellipse.hpp"

Ellipse::Ellipse()
	: center_(), little_haxis_(0.0), big_haxis_(0.0) {}

Ellipse::Ellipse(const Point2D& center, double a, double b)
	: center_(center), little_haxis_(a), big_haxis_(b) {}

string Ellipse::GetEquation() const
{
	string equation;



	return equation;
}

double Ellipse::Area() const
{
	return M_PI * little_haxis_ * big_haxis_;
}

bool Ellipse::Contains(const Point2D&) const
{
	return 0;
}

bool Ellipse::Boundary(const Point2D&) const
{
	return 0;
}

vector<Point2D> Ellipse::GetIntersection(const Line2D&) const
{
	return vector<Point2D>();
}

vector<Point2D> Ellipse::GetIntersection(const Ray2D&) const
{
	return vector<Point2D>();
}

vector<Point2D> Ellipse::GetIntersection(const Segment2D&) const
{
	return vector<Point2D>();
}