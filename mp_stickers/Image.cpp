#include "Image.h"
#include "cs225/PNG.h"
#include <cmath>

void Image::lighten() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.l + 0.1 <= 1)  {
                p.l = p.l + 0.1;
            } else {
                p.l = 1;
            }
        }
    }
}

void Image::lighten(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.l + amount <= 1)  {
                p.l = p.l + amount;
            } else {
                p.l = 1;
            }
        }
    }
}
        
void Image::darken() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.l - 0.1 >= 0)  {
                p.l = p.l - 0.1;
            } else {
                p.l = 0;
            }
        }
    }
}
        
void Image::darken(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.l - amount >= 0)  {
                p.l = p.l - amount;
            } else {
                p.l = 0;
            }
        }
    }
}
        
void Image::saturate() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.s + 0.1 <= 1)  {
                p.s= p.s + 0.1;
            } else {
                p.s = 1;
            }
        }
    }
}
        
void Image::saturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.s + amount <= 1)  {
                p.s = p.s + amount;
            } else {
                p.s = 1;
            }
        }
    }
}
        
void Image::desaturate() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.s - 0.1 >= 0)  {
                p.s = p.s - 0.1;
            } else {
                p.s = 0;
            }
        }
    }
}
        
void Image::desaturate(double amount) {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            if (p.s - amount >= 0)  {
                p.s = p.s - amount;
            } else {
                p.s = 0;
            }
        }
    }
}
        
void Image::grayscale() {
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p = this->getPixel(x, y);
            p.s = 0;
        }
    }
}
        
void Image::rotateColor(double degrees) {
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & p = this->getPixel(x, y);
      if (p.h + degrees >= 360) {
        p.h = p.h + degrees - 360;
      } else if (p.h + degrees <= 0) { 
        p.h = p.h + degrees + 360;
      } else {
          p.h = p.h + degrees;
      }
    }
  }
}
        
void Image::illinify() {
    for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & p = this->getPixel(x, y);
      if (p.h >= 102.5 && p.h <= 288.5) {
        p.h = 216;
      } else {
        p.h = 11;
      }
    }
  }
}
        
void Image::scale(double factor) {
    PNG* scaled = new PNG(this->width()*factor, this->height()*factor);
    for (unsigned x = 0; x < this->width()*factor; x++) {
        for (unsigned y = 0; y < this->height()*factor; y++) {
            cs225::HSLAPixel & p_scaled = scaled->getPixel(x, y);
            cs225::HSLAPixel & p_original = this->getPixel(floor(x/factor), floor(y/factor));
            p_scaled = p_original;
        }
    }
    this->resize(this->width()*factor, this->height()*factor);
    for (unsigned x = 0; x < this->width(); x++) {
        for (unsigned y = 0; y < this->height(); y++) {
            cs225::HSLAPixel & p_scaled = scaled->getPixel(x, y);
            cs225::HSLAPixel & p_original = this->getPixel(x, y);
            p_original = p_scaled;
        }
    }
    delete scaled;
}

void Image::scale(unsigned w, unsigned h) {
    double factor = std::min((double)w/this->width(), (double)h/this->height());
    this->Image::scale(factor);
}