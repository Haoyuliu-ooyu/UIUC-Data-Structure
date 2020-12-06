/**
 * @file NetworkFlow.cpp
 * CS 225: Data Structures
 */

#include <vector>
#include <algorithm>
#include <set>

#include "graph.h"
#include "edge.h"

#include "NetworkFlow.h"

int min(int a, int b) {
  if (a<b)
    return a;
  else return b;
}

NetworkFlow::NetworkFlow(Graph & startingGraph, Vertex source, Vertex sink) :
  g_(startingGraph), residual_(Graph(true,true)), flow_(Graph(true,true)), source_(source), sink_(sink) {

  // YOUR CODE HERE
  auto vertices = g_.getVertices();
  auto edges = g_.getEdges();
  for (auto v : vertices) {
    residual_.insertVertex(v);
    flow_.insertVertex(v);
  }
  for (auto e : edges) {
    residual_.insertEdge(e.source, e.dest);
    residual_.setEdgeWeight(e.source, e.dest, e.getWeight());
    residual_.insertEdge(e.dest, e.source);
    residual_.setEdgeWeight(e.dest, e.source, 0);
    flow_.insertEdge(e.source, e.dest);
    flow_.setEdgeWeight(e.source, e.dest, 0);
  }

}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the helper function.
   *
   * @param source  The starting (current) vertex
   * @param sink    The destination vertex
   * @param path    The vertices in the path
   * @param visited A set of vertices we have visited
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, 
  std::vector<Vertex> &path, std::set<Vertex> &visited) {

  if (visited.count(source) != 0)
    return false;
  visited.insert(source);

  if (source == sink) {
    return true;
  }

  vector<Vertex> adjs = residual_.getAdjacent(source);
  for(auto it = adjs.begin(); it != adjs.end(); it++) {
    if (visited.count(*it) == 0 && residual_.getEdgeWeight(source,*it) > 0) {
      path.push_back(*it);
      if (findAugmentingPath(*it,sink,path,visited))
        return true;
      else {
        path.pop_back();
      }
    }
  }

  return false;
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the main function.  It initializes a set to keep track of visited vertices.
   *
   * @param source The starting (current) vertex
   * @param sink   The destination vertex
   * @param path   The vertices in the path
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, std::vector<Vertex> &path) {
   std::set<Vertex> visited;
   path.clear();
   path.push_back(source);
   return findAugmentingPath(source,sink,path,visited);
}

  /**
   * pathCapacity - Determine the capacity of a path in the residual graph.
   *
   * @param path   The vertices in the path
   */

int NetworkFlow::pathCapacity(const std::vector<Vertex> & path) const {
  // YOUR CODE HERE
  int min = 999999999;
  vector<int> temp;
  for (unsigned i = 0; i < path.size() - 1; i++) {
    temp.push_back(residual_.getEdgeWeight(path[i], path[i+1]));
  }
  for (auto t : temp) {
    if (t <= min) {
      min = t;
    }
  }
  return min;
}

  /**
   * calculuateFlow - Determine the capacity of a path in the residual graph.
   * Sets the member function `maxFlow_` to be the flow, and updates the
   * residual graph and flow graph according to the algorithm.
   *
   * @return The network flow graph.
   */

const Graph & NetworkFlow::calculateFlow() {
  // YOUR CODE HERE
  vector<Vertex> vertices;
  int max_flow = 0;
  while (findAugmentingPath(source_, sink_, vertices)) {
    auto edges = residual_.getEdges();
    int temp_weight = pathCapacity(vertices);
    max_flow += temp_weight;
    for (unsigned i = 0; i < vertices.size() - 1; i++) {
      residual_.setEdgeWeight(vertices[i], vertices[i+1], residual_.getEdgeWeight(vertices[i], vertices[i+1]) - temp_weight);
      residual_.setEdgeWeight(vertices[i+1], vertices[i], residual_.getEdgeWeight(vertices[i+1], vertices[i]) + temp_weight);
      if (flow_.edgeExists(vertices[i], vertices[i+1])) {
        flow_.setEdgeWeight(vertices[i], vertices[i+1], flow_.getEdgeWeight(vertices[i], vertices[i+1]) + temp_weight);
      } else {
        flow_.setEdgeWeight(vertices[i+1], vertices[i], flow_.getEdgeWeight(vertices[i+1], vertices[i]) - temp_weight);
      }
    }
  }
  maxFlow_ = max_flow;
  return flow_;
}

int NetworkFlow::getMaxFlow() const {
  return maxFlow_;
}

const Graph & NetworkFlow::getGraph() const {
  return g_;
}

const Graph & NetworkFlow::getFlowGraph() const {
  return flow_;
}

const Graph & NetworkFlow::getResidualGraph() const {
  return residual_;
}

