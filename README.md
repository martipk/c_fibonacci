# c_fibonacci



----------------------------------------------------

## Large Fibonacci Number Generator

Fibonacci sequence number generator that can find more than the 1'000'000th Fibonacci number, bypassing the C data types overflow limits.

## Introduction

Inherently, finding Fibonacci numbers is rather easy, as it is just addition. However a problem arises when the numbers become too big and can no longer be stored in the regular C data types.

## The Problem

In C, the biggest integer type is `long long int`, and it ranges from `-2^63` to `2^63`. However, since Fibonacci numbers are strictly positive we can use the `unsigned long long int` type which ranges from `0` to `2^64 = 18,446,744,073,709,551,615 `. Which prevents us from getting the Fibonacci numbers past the 93rd `= 12'200'160'415'121'876'738`. If you take look at `weak_fibonacci.c` you will see that after the 93rd number `F(93)`, the integer values overflow and can no longer be stored.

##### Usage: 
	$ gcc weak_fibonacci.c -o wfib
	$ ./wfib upto 93
First parameter can be either "upto" to list all paramaters up to the specified Fibonacci number or "only" to print a that specific Fibonnaci number.
The Second parameter is the Fibonacci number you would like to see.

## The Solution

My first idea was to attach `unsigned long long ints` together recursively so their combined bits would be enough to store the numbers but it proved to be very difficult to convert the bits back to the integer as there was no way to store such a huge number. 

So I decided to take a different approach, and deal with the sum by factors of 10 and storing the resulting sum in a character array, because in C, `char *` could be initialized on the heap with any length therefore allowing me find any Fibonacci number,  the only limit being the heap size. The code is all in `fibonacci.c`.

### IMPORTANT:


in the header of the file there are 3 constants defined:

	#define LENGTH 20900
	#define FIB_NUMBS 100000
	#define PRINT_INTERVAL 10000

`LENGTH` is how many characters should be used for the calculation. If known, the amount of digits in the given Fibonacci number + 1 should run most efficiently, any less would overflow the buffer. If unknown, then roughly 25% of `FIB_NUMBS` will be more than enough.

`FIB_NUMBS` is the final Fibonacci number you want to obtain.

`PRINT_INTERVAL` is the interval in between prints. Write 1 if you want every single one to be printed. Keep in mind that with higher fibonacci numbers if all of them are printed your terminal will clog your memory since terminal output is saved to ram.

##### Usage: 
	$ gcc fibonacci.c -o fib
	$ ./fib
Run the program without any parameters. If you change the constants make sure to recompile.

## Runtime Tests
Runtime for some Fibonacci numbers.

-  `F(100)`: Running program with `LENGTH = 22` and  `FIB_NUMBS = 100` took 0.005 seconds.

-  `F(1'000)`: Running program with `LENGTH = 220` and  `FIB_NUMBS = 1'000` took 0.008 seconds.

-  `F(10'000)`: Running program with `LENGTH = 2200` and  `FIB_NUMBS = 10'000` took 0.173 seconds.

- `F(50'000)`: Running the program with  `LENGTH = 10451` and  `FIB_NUMBS = 50'000` took 3.77 seconds to execute. (Check http://mathforsmartypants.com/resources/ficalc.php for validity).

-  `F(100'000)`: Running program with `LENGTH = 20900` and  `FIB_NUMBS = 100'000` took 15.071 seconds. (Check https://www.wolframalpha.com/input/?i=100,000th+fibonacci+number for validity).

- `F(1'000'000)`: Running the program with `LENGTH = 208990` and `FIB_NUMBS = 1'000'000` and  took 26 minutes and 50 seconds to execute. The output of the 1 millionth Fibonacci number has been recorded in `1millionth.txt` and is proven to be correct from https://www.itarray.net/fibonacci-sequence-number-of-1-000-000/ .

(Note: `PRINT_INTERVAL` not mentioned since it does not affect runtime).

## Future Improvements

Right now the program is very slow with higher numbers since it does pointless operations while building up to the bigger numbers because it needs to loop over the whole strings and sum them up even if they're 0. Possible future improvements would be to find a way to only sum the digits needed.