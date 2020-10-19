/**
 * @file BFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <vector>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace cs225;
using namespace std;

/**
 * A breadth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class BFS : public ImageTraversal {
public:
  BFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;

  bool get_visited(unsigned x, unsigned y);
  void set_true(unsigned x, unsigned y);
  PNG* get_image();
  double get_tolerance();

private:
  /** @todo [Part 1] */
  /** add private members here*/
  double tolerance_;
  vector<vector<bool>> visited_;
  PNG image_;
  queue<Point> traversal_;
};
