#include "mathlib.h"

// The euler_count keeps track of the number of iterations taken
// by the function pi_euler().
static int euler_count = 0;

// The function pi_euler() calculates the value of pi using Euler's solution.
// The formula is pi = the square root of (6 times the sum
// from k = 1 to k = n of (1 / k^2))
// Inputs: None.
// Outputs: The value of pi as a double.

double pi_euler(void) {
    // Make sure we are starting from a count of 0.
    (euler_count = 0) ? euler_count : (euler_count = 0);

    // The "sum" keeps track of the sum of all terms
    double sum = 0.0;
    // The "fraction" represents the 1/k^2 term inside the sum
    double fraction = 1.0;
    // The variable k keeps track of the iterations, but is of type double
    double k = 1.0;

    while (absolute(fraction) > EPSILON) {
        // If its the first iteration, 1/(1^2) = 1
        // Otherwise, make the fraction 1/k^2
        if (euler_count == 0) {
            k = 1.0;
        } else {
            fraction = (double) (1.0 / (k * k));
        }

        // Increment the iteration counts and update the sum
        k += 1.0;
        sum += fraction;
        euler_count += 1;
    }

    // After the term becomes smaller than EPSILON, the square root
    // of 6 times the sum of all these terms is pi
    return sqrt_newton((double) (sum * 6.0));
}

// The function pi_euler_terms() calculates the number of iterations that the
// function pi_euler() took in order to produce the value of pi.
// Inputs: None.
// Outputs: The number of iterations taken by pi_euler().

int pi_euler_terms(void) {
    return euler_count;
}
