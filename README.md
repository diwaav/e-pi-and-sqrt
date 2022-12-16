# "A Little Slice of π" CSE 13S
This program is a combination of multiple functions that come together in a test file. The functions 
use variuous methods to calculate approximations for the value of e, pi, and the square root of a 
given number in an attempt to replicate the math library. 

## Building
Build the program with:
```
$ make
```
You can check the format using:
```
$ make format
```
Remember to clean up afterwards:
```
$ make clean
```

## Running
Run the program using:
```
$ ./mathlib-test
```
followed by a command where:
```
-a is for all tests
-e is for the approximate value of e
-b is for the value of pi approximated by the Bailey-Borwein-Plouffe formula
-m is for the value of pi approximated by the Madhava Series
-r is for the value of pi approximated by the Euler Sequence
-v is for the value of pi approximated by the Viete formula
-n is for the Newton square root approximation for values from 0 to 10 incremented by 0.1
-s is for statistics for the number of iterations the function required in order to calculate the value
-h is for help
```
## Possible Errors
Although the functions do a good job at approximating the values of pi, e, and the square root, they are still just approximations.  
 
