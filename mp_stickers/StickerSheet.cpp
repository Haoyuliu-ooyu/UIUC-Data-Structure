#include <StickerSheet.h>
#include <Image.h>

StickerSheet::StickerSheet(const Image &picture, unsigned max) {}
    
StickerSheet::~StickerSheet() {}

StickerSheet::StickerSheet(const StickerSheet &other) {}

StickerSheet::const StickerSheet & operator=(const StickerSheet &other) {}
    
StickerSheet::void changeMaxStickers(unsigned max) {}
        
StickerSheet::int addSticker (Image &sticker, unsigned x, unsigned y) {return 1;}
        
StickerSheet::bool translate (unsigned index, unsigned x, unsigned y) {return true;}
        
StickerSheet::void removeSticker (unsigned index) {}

StickerSheet::Image* getSticker(unsigned index) {
        Image* toReturn = NULL;
        return toReturn;
}
        
StickerSheet::Image render () const {
        Image toReturn = NULL;
        return toReturn;
}