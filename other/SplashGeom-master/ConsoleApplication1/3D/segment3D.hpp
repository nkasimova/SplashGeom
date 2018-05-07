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
#ifndef SEGMENT_HPP_
#define SEGMENT_HPP_

#include "../splash_forward.hpp"
#include "../splash_utils.hpp"

#include "point3D.hpp"
#include "vector3D.hpp"
#include "line3D.hpp"

class Segment3D
{
public:
	Point3D a;
	Point3D b;

	Segment3D();
	Segment3D(const Point3D& point_a, const Point3D& point_b);

	void Reverse();

	double Length() const;
	Point3D Center() const;
	bool Point3DInBox(const Point3D& point) const;

	Vector3D Direction() const;
	Vector3D NormalVec() const;

	bool Contains(const Point3D& point) const;
	Point3D GetIntersection(const Segment3D& second_seg) const;
	Point3D GetIntersection(const Line3D& line) const;
	Point3D GetIntersection(const Ray3D& ray) const;

	bool HasIntersection(const Segment3D& second_seg) const;
	bool HasIntersection(const Line3D& line) const;
	bool HasIntersection(const Ray3D& ray) const;
};

#endif /*SEGMENT_HPP_*/