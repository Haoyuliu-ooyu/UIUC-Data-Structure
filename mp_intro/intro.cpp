#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <iostream>
#include <cmath>


void rotate(std::string inputFile, std::string outputFile) {
  cs225::PNG input, output;
  input.readFromFile(inputFile);
  output.resize(input.width(), input.height());
  for (unsigned x = 0; x < input.width(); x++) {
    for (unsigned y = 0; y < input.height(); y++) {
      cs225::HSLAPixel & inp = input.getPixel(x, y);
      cs225::HSLAPixel & outp = output.getPixel(input.width() - x - 1, input.height() - y - 1);
      outp = inp;
    }
  }
  output.writeToFile(outputFile);
  // TODO: Part 2
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      i.h = 225;
      i.s = 79;
      i.l = 56;
    }
  }
  for (unsigned x = 0; x < width/4; x++) {
    for (unsigned y = 3 * (height/4); y < height; y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      if (std::sqrt(std::pow(((int)x - 0), 2) + std::pow(((int)y - 800), 2)) <= 200) {
        i.h = 58;
        i.s = 90;
        i.l = 98;
      }
    }
  }
  for (unsigned x = width/4; x < width/2; x++) {
    for (unsigned y = 0; y < height ; y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      i.h = 197;
      i.s = 46;
      i.l = 47;
    }
  }
  for (unsigned x = width/2; x < 3 * width/4; x++) {
    for (unsigned y = 0; y < height/2; y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      i.h = 194;
      i.s = 40;
      i.l = 41;
    }
  }
  for (unsigned x = 3 * width/4; x < width; x++) {
    for (unsigned y = 0; y < 7 * height / 8; y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      unsigned diff = std::sqrt(std::pow(((int)x - width/2), 2) + std::pow(((int)y - height/2), 2));
      i.l = i.l * diff * (1 - 0.03);
    }
  }
  for (unsigned x = 3 * width/4; x < width; x++) {
    for (unsigned y = 0; y < height / 2; y++) {
      cs225::HSLAPixel & i = png.getPixel(x, y);
      i.h = 190;
      i.s = 50;
      i.l = 51;
    }
  }
  return png;
}
