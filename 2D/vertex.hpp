// Splash (c) - open-source C++ library for geometry and linear algebra
// Copyright (c) 2016, Ilya Zakharkin, Elena Kirilenko and Nadezhda Kasimova.
// All rights reserved.
/*
	This file is part of Splash.
	Splash is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	Foobar is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef vertex_hpp
#define vertex_hpp

#include "point2D.hpp"

class Edge;

class Vertex 
{
public:
    Point2D point2D;
    vector<Edge*> edges;
    size_t index;
    
    Vertex();
    Vertex(const Point2D& _point2D);
    Vertex(Point2D&& _point2D);
};

#endif /* vertex_hpp */
