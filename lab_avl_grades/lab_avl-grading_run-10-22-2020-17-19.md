


## Score: 50/50 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c coloredout.cpp -o .objs/coloredout.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/coloredout.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - test_find

- **Points**: 10 / 10

```
==56== Memcheck, a memory error detector
==56== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==56== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==56== Command: ./test -r xml "test_find"
==56== 
==56== 
==56== HEAP SUMMARY:
==56==     in use at exit: 0 bytes in 0 blocks
==56==   total heap usage: 1,667 allocs, 1,667 frees, 216,640 bytes allocated
==56== 
==56== All heap blocks were freed -- no leaks are possible
==56== 
==56== For counts of detected and suppressed errors, rerun with: -v
==56== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_insert_small

- **Points**: 5 / 5





### ✓ - [10/10] - test_insert_find

- **Points**: 10 / 10





### ✓ - [10/10] - test_insert_big

- **Points**: 10 / 10

```
==60== Memcheck, a memory error detector
==60== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==60== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==60== Command: ./test -r xml "test_insert_big"
==60== 
==60== 
==60== HEAP SUMMARY:
==60==     in use at exit: 0 bytes in 0 blocks
==60==   total heap usage: 1,693 allocs, 1,693 frees, 218,128 bytes allocated
==60== 
==60== All heap blocks were freed -- no leaks are possible
==60== 
==60== For counts of detected and suppressed errors, rerun with: -v
==60== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [5/5] - test_remove_small

- **Points**: 5 / 5





### ✓ - [10/10] - test_remove_big

- **Points**: 10 / 10

```
==63== Memcheck, a memory error detector
==63== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==63== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==63== Command: ./test -r xml "test_remove_big"
==63== 
==63== 
==63== HEAP SUMMARY:
==63==     in use at exit: 0 bytes in 0 blocks
==63==   total heap usage: 1,706 allocs, 1,706 frees, 219,624 bytes allocated
==63== 
==63== All heap blocks were freed -- no leaks are possible
==63== 
==63== For counts of detected and suppressed errors, rerun with: -v
==63== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---

This report was generated for **haoyul4** using **43b33c153c21569c52e279865923941220447706** (latest commit as of **October 19th 2020, 7:00 am**)
