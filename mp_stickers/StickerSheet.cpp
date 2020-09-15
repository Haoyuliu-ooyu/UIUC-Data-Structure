#include "StickerSheet.h"

StickerSheet::StickerSheet(const Image &picture, unsigned max) {}
    
StickerSheet::~StickerSheet() {}

StickerSheet::StickerSheet(const StickerSheet &other) {}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other) {return other;}
    
void StickerSheet::changeMaxStickers(unsigned max) {}

int StickerSheet::addSticker (Image &sticker, unsigned x, unsigned y) {return 1;}
        
bool StickerSheet::translate (unsigned index, unsigned x, unsigned y) {return true;}
        
void StickerSheet::removeSticker (unsigned index) {}

Image* StickerSheet::getSticker(unsigned index) {return nullptr;}
        
Image StickerSheet::render () const {
        Image i;
        return i;
}