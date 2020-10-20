
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  PNG image = PNG();
  image.readFromFile("tests/pacman.png");
  unsigned x = image.width() / 5;
  unsigned y = image.height() / 5;
  DFS dfs1 = DFS(image, Point(x, y), x/2);
  DFS dfs2 = DFS(image, Point(2*x, y), x/2);
  BFS bfs1 = BFS(image, Point(x, 2*y), y/2);
  BFS bfs2 = BFS(image, Point(2*x, 2*y), y/2);
  
  RainbowColorPicker m = RainbowColorPicker(37);
  MyColorPicker n = MyColorPicker(0, 8);
  FloodFilledImage f = FloodFilledImage(image);
  f.addFloodFill(dfs1, m);
  f.addFloodFill(dfs2, m);
  f.addFloodFill(bfs1, n);
  f.addFloodFill(bfs2, n);

  Animation animation = f.animate(1000);
  
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  return 0;
}
