#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal_ = NULL;
  finished = true;
}

ImageTraversal::Iterator::Iterator(ImageTraversal& traversal, Point start) {
  traversal_ = &traversal;
  start_ = start;
  finished = false;
  current_ = traversal_->peek();
}

/**
 * ImageTraversal::Iterator::~Iterator() {
  * if (traversal_ != NULL) {
    *delete traversal_;
    *traversal_ = NULL;
  *}
}*/
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  Point curr = traversal_->pop();
  traversal_->set_true(curr.x, curr.y);
  Point right(curr.x + 1, curr.y);
  Point below(curr.x, curr.y+1);
  Point left(curr.x - 1, curr.y);
  Point above(curr.x, curr.y -1);
  HSLAPixel& startPixel = traversal_->get_image()->getPixel(start_.x, start_.y);

  if (right.x < traversal_->get_image()->width()) {
    HSLAPixel & t = traversal_->get_image()->getPixel(right.x, right.y);
    if (calculateDelta(startPixel, t) < traversal_->get_tolerance()) {
      traversal_->add(right);
    }
  }
  if (below.y < traversal_->get_image()->height()) {
    HSLAPixel & t = traversal_->get_image()->getPixel(below.x, below.y);
    if (calculateDelta(startPixel, t) < traversal_->get_tolerance()) {
      traversal_->add(below);
    }
  }
  if (left.x < traversal_->get_image()->width()) {
    HSLAPixel & t = traversal_->get_image()->getPixel(left.x, left.y);
    if (calculateDelta(startPixel, t) < traversal_->get_tolerance()) {
      traversal_->add(left);
    }
  }
  if (above.y < traversal_->get_image()->height()) {
    HSLAPixel& t = traversal_->get_image()->getPixel(above.x, above.y);
    if (calculateDelta(startPixel, t) < traversal_->get_tolerance()) {
      traversal_->add(above);
    }
  }

  while (!(traversal_->empty()) && traversal_->get_visited(traversal_->peek().x, traversal_->peek().y)) {
    traversal_->pop();
  }
  if (traversal_->empty()) {
    finished = true;
  } else {
    current_ = traversal_->peek();
  }
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current_;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return !(finished && other.finished);
}
