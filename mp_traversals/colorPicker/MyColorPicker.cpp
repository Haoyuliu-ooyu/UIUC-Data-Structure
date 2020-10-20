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
  s = 0;
  increment = incre;
}
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  HSLAPixel pixel(h, s, 0.5);
  h += increment;
  s += 0.2;
  if (h >= 360) { h -= 360; }
  if (s >= 1) { s -= 1; }
  return pixel;
}
