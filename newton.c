#include "mathlib.h"

// The square_count keeps track of the number of iterations taken
// by the function sqrt_newton().
static int square_count = 0;

// The function sqrt_newton() finds the square root of a double-type number.
// Inputs: A number that is of type double.
// Outputs: The square root of the input.

double sqrt_newton(double x) {
    // Make sure we are starting from a count of 0.
    (square_count = 0) ? square_count : (square_count = 0);

    // The variables z and y define the min and max for our
    // search for the square root of a number.
    double z = 0.0;
    double y = 1.0;

    while (absolute(y - z) > EPSILON) {
        // While the difference betwee y and z are larger than EPSILON,
        // set z to the same value of y but then change y to be closer to the middle
        z = y;
        y = (double) 0.5 * (z + (x / z));

        // Increment the iteration count
        square_count += 1;
    }

    // After finding the value that results in x after multiplied
    // to itself, return it as a double.
    return y;
}

// The function sqrt_newton_iters() calculates the number of iterations that the
// function sqrt_newton() took in order to produce the value.
// Inputs: None.
// Outputs: The number of iterations taken by sqrt_newton() to calculate the last given input.

int sqrt_newton_iters(void) {
    return square_count;
}
