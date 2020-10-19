#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(double hue, double incre) {
  h = hue;
  s = 1;
  increment = incre;
}
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(h, s, 0.5);
  h += increment;
  s += increment;
  if (h >= 360) { h -= 360; }
  if (s >= 100) { s -= 100; }
  return pixel;
}
