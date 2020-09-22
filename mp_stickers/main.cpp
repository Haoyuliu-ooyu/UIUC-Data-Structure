#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image base;
  base.readFromFile("alma.png");
  StickerSheet sheet = StickerSheet(base, 15);
  Image sticker;
  sticker.readFromFile("i.png");
  Image frog;
  frog.readFromFile("frog.png");
  Image cover;
  cover.readFromFile("lighten.png");
  cover.resize(150, 200);
  for (unsigned i = 0; i < 5; i++) {
    sheet.addSticker(sticker, 50 * i, 30 * i);
    sheet.addSticker(frog, 300 - 8*i, 200 + 40*i);
    sheet.addSticker(cover, 20 + 10*i, 20 + 36*i);
  }
  sheet.render().writeToFile("myImage.png");


  return 0;
}
