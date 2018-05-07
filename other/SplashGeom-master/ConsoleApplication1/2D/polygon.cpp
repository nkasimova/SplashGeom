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
#include "polygon.hpp"

Polygon::Polygon()
	: vertices_(0) {}

Polygon::Polygon(int n)
	: vertices_(n) {}

Polygon::Polygon(const Polygon& second_polygon)
{
	vertices_.resize(second_polygon.Size());
	std::copy(second_polygon.vertices_.begin(), second_polygon.vertices_.end(), vertices_.begin());
}

void Polygon::operator =(const Polygon& second_polygon)
{
	vertices_ = second_polygon.vertices_;
}

Polygon::Polygon(const vector<Point2D>& points)
{
	vertices_.resize(points.size());
	std::copy(points.begin(), points.end(), vertices_.begin());
}

void Polygon::operator =(const vector<Point2D>& points)
{
	std::copy(points.begin(), points.end(), vertices_.begin());
}

Polygon::Polygon(Polygon&& second_polygon)
{
	vertices_ = std::move(second_polygon.vertices_);
}

void Polygon::operator =(Polygon&& second_polygon)
{
	vertices_ = std::move(second_polygon.vertices_);
}

int Polygon::Size() const
{
	return vertices_.size();
}

double Polygon::Area() const 
{
	double area = 0;
	int num_of_vertices = vertices_.size();
	for (int i = 0; i < num_of_vertices; ++i) {
		int j = (i + 1) % num_of_vertices;
		area += Vector2D(vertices_[i]).OrientedCCW(Vector2D(vertices_[j] - vertices_[i]));
	}
	return fabs(area / 2.0);
}

bool Polygon::Contains(const Point2D& point) const
{
	int num_of_cross_sides = 0;
	size_t sz = vertices_.size();
	Ray2D checking_ray(point, Vector2D(1, 0));
	bool is_on_border = false;
	for (size_t i = 0; i < sz && !is_on_border; ++i) {
		int j = (i + 1) % sz;
		Segment2D cur_side(vertices_[i], vertices_[j]);
		if (cur_side.Contains(point)) {
			is_on_border = true;
			num_of_cross_sides = 1;
		} else if (checking_ray.HasIntersection(cur_side)) {
			num_of_cross_sides++;
		}
	}
	return num_of_cross_sides % 2 == 0;
}

bool Polygon::Boundary(const Point2D & point) const
{
	size_t sz = vertices_.size();
	bool is_on_border = false;
	for (size_t i = 0; i < sz && !is_on_border; ++i) {
		int j = (i + 1) % sz;
		Segment2D cur_side(vertices_[i], vertices_[j]);
		if (cur_side.Contains(point)) {
			is_on_border = true;
		}
	}
	return is_on_border;
}

vector<Point2D> Polygon::GetIntersection(const Line2D&) const
{
	return vector<Point2D>();
}

vector<Point2D> Polygon::GetIntersection(const Ray2D&) const
{
	return vector<Point2D>();
}

vector<Point2D> Polygon::GetIntersection(const Segment2D&) const
{
	return vector<Point2D>();
}