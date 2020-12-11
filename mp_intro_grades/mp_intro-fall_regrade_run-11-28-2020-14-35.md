---

This report was generated for **haoyul4** using **28199d84b5649943a49b033f0960e52e1f52378f** (latest commit as of **November 21st 2020, 6:00 am**)

---




## Score: 13/13 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/PNG.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/HSLAPixel.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic cs225/lodepng/lodepng.cpp
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic main.cpp intro.cpp
clang++ PNG.o HSLAPixel.o lodepng.o intro.o main.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o intro
clang++  -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic tests/tests.cpp
clang++ tests.o PNG.o HSLAPixel.o lodepng.o intro.o -std=c++1y -stdlib=libc++ -lc++abi -lm -o test

```


### ✓ - [1/1] - HSLAPixel's default constructor creates a white pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's default constructor creates an opaque pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSL constructor creates a pixel with provided HSL values

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSL constructor creates an opaque pixel

- **Points**: 1 / 1





### ✓ - [1/1] - HSLAPixel's HSLA constructor creates a pixel with provided HSLA values

- **Points**: 1 / 1





### ✓ - [1/1] - Rotate in_01.png

- **Points**: 1 / 1





### ✓ - [1/1] - Rotate in_02.png

- **Points**: 1 / 1





### ✓ - [1/1] - Rotate in_03.png

- **Points**: 1 / 1





### ✓ - [3/3] - Creative artwork contains at least three unique colors

- **Points**: 3 / 3





### ✓ - [2/2] - Generate creative artwork

- **Points**: 2 / 2





---