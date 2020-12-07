---

This report was generated for **haoyul4** using **e90a20560eac3d941b894418cd355d99bbcbf18d** (latest commit as of **December 7th 2020, 6:00 am**)

---




## Score: 10/10 (100.00%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c graph.cpp -o .objs/graph.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c NetworkFlow.cpp -o .objs/NetworkFlow.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c tests/unit_tests.cpp -o .objs/tests/unit_tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/graph.o .objs/NetworkFlow.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/unit_tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [1/1] - Graph a - 4 -> b  has flow of 4.

- **Points**: 1 / 1

```
==62== Memcheck, a memory error detector
==62== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==62== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==62== Command: ./test -r xml "Graph\ a\ -\ 4\ -\>\ b\ \ has\ flow\ of\ 4."
==62== 
==62== 
==62== HEAP SUMMARY:
==62==     in use at exit: 0 bytes in 0 blocks
==62==   total heap usage: 1,982 allocs, 1,982 frees, 235,436 bytes allocated
==62== 
==62== All heap blocks were freed -- no leaks are possible
==62== 
==62== For counts of detected and suppressed errors, rerun with: -v
==62== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing flow through two pipes - secret test

- **Points**: 1 / 1

```
==64== Memcheck, a memory error detector
==64== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==64== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==64== Command: ./test -r xml "Testing\ flow\ through\ two\ pipes\ -\ secret\ test"
==64== 
==64== 
==64== HEAP SUMMARY:
==64==     in use at exit: 0 bytes in 0 blocks
==64==   total heap usage: 2,042 allocs, 2,042 frees, 241,632 bytes allocated
==64== 
==64== All heap blocks were freed -- no leaks are possible
==64== 
==64== For counts of detected and suppressed errors, rerun with: -v
==64== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Graph a - 10 -> b  has flow of 10.

- **Points**: 1 / 1

```
==66== Memcheck, a memory error detector
==66== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==66== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==66== Command: ./test -r xml "Graph\ a\ -\ 10\ -\>\ b\ \ has\ flow\ of\ 10."
==66== 
==66== 
==66== HEAP SUMMARY:
==66==     in use at exit: 0 bytes in 0 blocks
==66==   total heap usage: 1,982 allocs, 1,982 frees, 235,436 bytes allocated
==66== 
==66== All heap blocks were freed -- no leaks are possible
==66== 
==66== For counts of detected and suppressed errors, rerun with: -v
==66== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing flow through two pipes

- **Points**: 1 / 1

```
==68== Memcheck, a memory error detector
==68== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==68== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==68== Command: ./test -r xml "Testing\ flow\ through\ two\ pipes"
==68== 
==68== 
==68== HEAP SUMMARY:
==68==     in use at exit: 0 bytes in 0 blocks
==68==   total heap usage: 2,042 allocs, 2,042 frees, 241,440 bytes allocated
==68== 
==68== All heap blocks were freed -- no leaks are possible
==68== 
==68== For counts of detected and suppressed errors, rerun with: -v
==68== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing simple backflow - secret

- **Points**: 1 / 1

```
==70== Memcheck, a memory error detector
==70== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==70== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==70== Command: ./test -r xml "Testing\ simple\ backflow\ -\ secret"
==70== 
==70== 
==70== HEAP SUMMARY:
==70==     in use at exit: 0 bytes in 0 blocks
==70==   total heap usage: 2,181 allocs, 2,181 frees, 260,956 bytes allocated
==70== 
==70== All heap blocks were freed -- no leaks are possible
==70== 
==70== For counts of detected and suppressed errors, rerun with: -v
==70== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing simple backflow

- **Points**: 1 / 1

```
==72== Memcheck, a memory error detector
==72== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==72== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==72== Command: ./test -r xml "Testing\ simple\ backflow"
==72== 
==72== 
==72== HEAP SUMMARY:
==72==     in use at exit: 0 bytes in 0 blocks
==72==   total heap usage: 2,135 allocs, 2,135 frees, 252,864 bytes allocated
==72== 
==72== All heap blocks were freed -- no leaks are possible
==72== 
==72== For counts of detected and suppressed errors, rerun with: -v
==72== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing full pipe usage - secret

- **Points**: 1 / 1

```
==74== Memcheck, a memory error detector
==74== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==74== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==74== Command: ./test -r xml "Testing\ full\ pipe\ usage\ -\ secret"
==74== 
==74== 
==74== HEAP SUMMARY:
==74==     in use at exit: 0 bytes in 0 blocks
==74==   total heap usage: 2,165 allocs, 2,165 frees, 255,668 bytes allocated
==74== 
==74== All heap blocks were freed -- no leaks are possible
==74== 
==74== For counts of detected and suppressed errors, rerun with: -v
==74== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing full pipe usage

- **Points**: 1 / 1

```
==76== Memcheck, a memory error detector
==76== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==76== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==76== Command: ./test -r xml "Testing\ full\ pipe\ usage"
==76== 
==76== 
==76== HEAP SUMMARY:
==76==     in use at exit: 0 bytes in 0 blocks
==76==   total heap usage: 2,179 allocs, 2,179 frees, 253,988 bytes allocated
==76== 
==76== All heap blocks were freed -- no leaks are possible
==76== 
==76== For counts of detected and suppressed errors, rerun with: -v
==76== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing 3 x 3 plumbing - secret

- **Points**: 1 / 1

```
==78== Memcheck, a memory error detector
==78== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==78== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==78== Command: ./test -r xml "Testing\ 3\ x\ 3\ plumbing\ -\ secret"
==78== 
==78== 
==78== HEAP SUMMARY:
==78==     in use at exit: 0 bytes in 0 blocks
==78==   total heap usage: 2,280 allocs, 2,280 frees, 273,204 bytes allocated
==78== 
==78== All heap blocks were freed -- no leaks are possible
==78== 
==78== For counts of detected and suppressed errors, rerun with: -v
==78== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [1/1] - Testing 3 x 3 plumbing

- **Points**: 1 / 1

```
==80== Memcheck, a memory error detector
==80== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==80== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==80== Command: ./test -r xml "Testing\ 3\ x\ 3\ plumbing"
==80== 
==80== 
==80== HEAP SUMMARY:
==80==     in use at exit: 0 bytes in 0 blocks
==80==   total heap usage: 2,316 allocs, 2,316 frees, 278,376 bytes allocated
==80== 
==80== All heap blocks were freed -- no leaks are possible
==80== 
==80== For counts of detected and suppressed errors, rerun with: -v
==80== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



---