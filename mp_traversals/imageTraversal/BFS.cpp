#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;
using namespace std;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  tolerance_ = tolerance;
  start_ = start;
  image_ = png;
  traversal_.push(start);
  visited_.resize(image_.width());
  for (unsigned i = 0; i < visited_.size(); i++) {
    visited_[i].resize(image_.height());
    for (unsigned j = 0; j < visited_[i].size(); j++) {
      visited_[i][j] = false;
    }
  } 
  visited_[start_.x][start_.y] = true;
}


/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  BFS * new_ = new BFS(image_, start_, tolerance_);
  return ImageTraversal::Iterator(*new_, start_);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
  traversal_.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  Point front = traversal_.front();
  traversal_.pop();
  return front;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  return traversal_.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return traversal_.empty();
}

bool BFS::get_visited(unsigned i, unsigned j) {
  return visited_[i][j];
}

void BFS::set_true(unsigned i, unsigned j) {
  visited_[i][j] = true;
}

PNG* BFS::get_image() {
  return &image_;
}

double BFS::get_tolerance() {
  return tolerance_;
}
