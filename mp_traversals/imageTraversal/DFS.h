/**
 * @file DFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
using namespace std;

/**
 * A depth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class DFS : public ImageTraversal {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;

  bool get_visited(unsigned i, unsigned j);
  void set_true(unsigned i, unsigned j);
  PNG* get_image();
  double get_tolerance();

private:
	/** @todo [Part 1] */
	/** add private members here*/
  double tolerance_;

  vector<vector<bool>> visited_;

  PNG image_;

  Point start_;

  stack<Point> traversal_;

};