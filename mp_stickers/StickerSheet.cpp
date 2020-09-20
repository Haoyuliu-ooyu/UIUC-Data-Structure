#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"

StickerSheet::StickerSheet(const Image &picture, unsigned max) {
        maxNum = max;
        original_picture = new Image(picture);
        Scene = new Image*[max];
        xCoord = new unsigned[max];
        yCoord = new unsigned[max];
        for (unsigned i = 0; i < max; i++) {
                Scene[i] = NULL;
        }
}

StickerSheet::~StickerSheet() {
        destroy();
}

StickerSheet::StickerSheet(const StickerSheet &other) {
        copy(other);
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {
        if (this != &other) {
                destroy();
                copy(other);  
        }
        return *this;
}

void StickerSheet::copy(const StickerSheet &other) {
        maxNum = other.maxNum;
        this->original_picture = new Image(*other.original_picture);
        Image** Scene_ = new Image*[maxNum];
        unsigned* yCoord_ = new unsigned[maxNum];
        unsigned* xCoord_ = new unsigned[maxNum];
        for (unsigned i = 0; i < maxNum; i++) {
                if (other.Scene[i] != NULL) {
                        Scene_[i] = new Image(*other.Scene[i]);
                        xCoord_[i] = other.xCoord[i];
                        yCoord_[i] = other.yCoord[i];
                } else {
                        Scene_[i] = NULL;
                }
        }
        this->Scene = Scene_;
        this->xCoord = xCoord_;
        this->yCoord = yCoord_;
}
void StickerSheet::destroy() {
        if (original_picture != NULL) {
                delete original_picture;
        }
        if (Scene != NULL) {
                for (unsigned i = 0; i < maxNum; i++) {
                        if (Scene[i] != NULL) {
                                delete Scene[i];
                        }
                }
                delete[] Scene;
        }
        if (xCoord != NULL) {
                delete[] xCoord;
        }
        if (yCoord != NULL) {
                delete[] yCoord;
        }
}
void StickerSheet::changeMaxStickers(unsigned max) {
        StickerSheet corpy = StickerSheet(*this);
        destroy();
        original_picture = new Image(*corpy.original_picture);
        maxNum =  max;
        Scene = new Image*[max];
        for (unsigned i = 0; i < max; i++) {
                Scene[i] = NULL;
        }
        xCoord = new unsigned[max];
        yCoord = new unsigned[max];
        for (unsigned i = 0; i < std::min(max, corpy.maxNum); i++) {
                if (corpy.Scene[i] != NULL) {
                        Scene[i] = new Image(*(corpy.Scene[i]));
                        xCoord[i] = corpy.xCoord[i];
                        yCoord[i] = corpy.yCoord[i];
                }
        }
}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y) {
        for (unsigned i = 0; i < maxNum; i++) {
                if (Scene[i] == NULL) {
                        Scene[i] = new Image(sticker);
                        xCoord[i] = x;
                        yCoord[i] = y;
                        return i;
                }
        }
        return -1;
}

bool StickerSheet::translate (unsigned index, unsigned x, unsigned y) {
        if (index < 0 || index >= maxNum || Scene[index] == NULL) {
                return false;
        }
        xCoord[index] = x;
        yCoord[index] = y;
        return true;
}
        
void StickerSheet::removeSticker (unsigned index) {
        if (index >= 0 && index < maxNum && Scene[index] != NULL) {
                delete Scene[index];
                Scene[index] = NULL;
        }
}

Image* StickerSheet::getSticker(unsigned index) {
        if (index < 0 || index >= maxNum || Scene[index] == NULL) {
                return NULL;
        }
        return Scene[index];
}

Image StickerSheet::render () const {
        Image image = Image(*original_picture);
        unsigned max_width = image.width();
        unsigned max_height = image.height();
        for (unsigned i = 0; i < maxNum; i++) {
                if (Scene[i] == NULL) {
                        continue;
                }
                unsigned current_width = Scene[i]->width();
                unsigned current_height = Scene[i]->height();
                if (current_width + xCoord[i] >= max_width) {
                        max_width = current_width + xCoord[i];
                } else if (current_width + yCoord[i] >= max_height) {
                        max_height = current_height + yCoord[i];
                }
        }
        image.resize(max_width, max_height);
        for (unsigned i = 0; i < maxNum; i++) {
                if (Scene[i] == NULL) {
                        continue;
                }
                Image* sticker = Scene[i];
                unsigned xc = xCoord[i];
                unsigned yc = yCoord[i];
                for (unsigned x = xc; x < xc + sticker->width(); x++) {
                        for (unsigned y = yc; y < yc + sticker->height(); y++) {
                                cs225::HSLAPixel & p1 = sticker->getPixel(x - xc, y - yc);
                                cs225::HSLAPixel & p2 = image.getPixel(x, y);
                                if (p1.a != 0) {
                                        p2 = p1;
                                }
                        }
                }
        }
        return image;
}