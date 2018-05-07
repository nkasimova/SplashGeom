// Splash (c) - open-source C++ library for geometry and linear algebra
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
	along with Splash.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "graph.hpp"

vector<unique_ptr<Vertex>>::iterator Graph::add_vertex(const Point2D& point2D) {
    vertices.emplace_back(new Vertex(point2D));
    vertices.back()->index = vertices.size() - 1;
    return vertices.end() - 1;
}

vector<std::unique_ptr<Vertex>>::iterator Graph::add_vertex(Point2D&& point2D) {
    vertices.emplace_back(new Vertex(std::move(point2D)));
    vertices.back()->index = vertices.size() - 1;
    return vertices.end() - 1;
}

Edge* Graph::add_edge(vector<unique_ptr<Vertex>>::iterator vertex1,
               std::vector<std::unique_ptr<Vertex>>::iterator vertex2) {
    size_t index1 = vertex1 - vertices.begin();
    size_t index2 = vertex2 - vertices.begin();
    for (Edge* edge : (*vertex1)->edges) {
        if (edge->other_vertex(vertex1->get()) == vertex2->get()) {
            return nullptr;
        }
    }
    edges.emplace_back(new Edge());
    edges.back()->vertices[0] = vertices[index1].get();
    edges.back()->vertices[1] = vertices[index2].get();
    edges.back()->indexes[0] = vertices[index1]->edges.size();
    edges.back()->indexes[1] = vertices[index2]->edges.size();
    vertices[index1]->edges.push_back(edges.back().get());
    vertices[index2]->edges.push_back(edges.back().get());
    return edges.back().get();
}

void Graph::print_all_neighbours(Vertex* x) {
    for (const Edge* edge : x->edges) {
        std::cout << edge->other_vertex(x)->index << " ";
    }
    std::cout << "\n";
}

vector<Vertex*> Graph::get_similar_vertices(Vertex* x, Vertex* y) {
    Vertex* x_neighbour;
    Vertex* y_neighbour;
    std::vector<Vertex*> result;
    for (const Edge* edge_x : x->edges) {
        x_neighbour = edge_x->other_vertex(x);
        for (const Edge* edge_y : y->edges) {
            y_neighbour = edge_y->other_vertex(y);
            if (x_neighbour == y_neighbour) {
                result.push_back(x_neighbour);
            }
        }
    }
    return result;
}
