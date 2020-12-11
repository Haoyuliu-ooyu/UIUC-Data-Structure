---

This report was generated for **haoyul4** using **05272e75f3aa5e0110b2a0c1427bf1cc3c02ff70** (latest commit as of **December 10th 2020, 6:00 am**)

---




## Score: 75/215 (34.88%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c dsets.cpp -o .objs/dsets.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c maze.cpp -o .objs/maze.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part1.cpp -o .objs/tests/test_part1.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/test_part2.cpp -o .objs/tests/test_part2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/mazereader.cpp -o .objs/tests/mazereader.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/dsets.o .objs/maze.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/test_part1.o .objs/tests/test_part2.o .objs/tests/mazereader.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - addElements1

- **Points**: 10 / 10





### ✓ - [10/10] - addElements2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion1

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion2

- **Points**: 10 / 10





### ✓ - [10/10] - testFindAndSetUnion3

- **Points**: 10 / 10





### ✓ - [5/5] - size1

- **Points**: 5 / 5





### ✓ - [10/10] - size2

- **Points**: 10 / 10





### ✗ - [0/10] - testMakeSmallMaze

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✓ - [10/10] - testMakeMazeConnected

- **Points**: 10 / 10





### ✗ - [0/10] - testMakeMazeAcyclic

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✗ - [0/10] - testMakeMazeTree1000

- **Points**: 0 / 10


```
FAIL: Maze has a cycle
```


### ✗ - [0/10] - testMakeMazeRandom

- **Points**: 0 / 10


```
FAIL: Generated the same 50x50 maze twice
```


### ✗ - [0/10] - testSolveMazeValidPath

- **Points**: 0 / 10


```
FAIL: No solution was generated
```


### ✗ - [0/10] - testSolutionBottomRow

- **Points**: 0 / 10


```
FAIL: Didn't end up at the bottom row
```


### ✗ - [0/10] - testSolutionCorrectSquare

- **Points**: 0 / 10


```
FAIL: Didn't end up at the bottom row
```


### ✗ - [0/10] - testSolveMazeSmall

- **Points**: 0 / 10


```
Original: soln.getSolutionSize() == solution.size()
Expanded: 5644 (0x160c) == 0
```


### ✗ - [0/10] - testSolveMazeLarge

- **Points**: 0 / 10


```
Original: soln.getSolutionSize() == solution.size()
Expanded: 3883 (0xf2b) == 0
```


### ✗ - [0/10] - testDrawMazeSmall

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=21, h=21, hash=3ff0000000000000)
```


### ✗ - [0/10] - testDrawMazeMed

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=501, h=501, hash=3ff0000000000000)
```


### ✗ - [0/10] - testDrawMazeLarge

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=5001, h=5001, hash=3ff0000000000000)
```


### ✗ - [0/10] - testDrawSolutionMed

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=501, h=501, hash=3fe0000000000000)
```


### ✗ - [0/10] - testDrawSolutionLarge

- **Points**: 0 / 10


```
Original: *actualOutput == solnImage
Expanded: PNG(w=0, h=0, hash=0)
==
PNG(w=5001, h=5001, hash=3fe0000000000000)
```


---