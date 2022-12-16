#include "mathlib.h"

// The madhava_count keeps track of the number of iterations taken
// by the function pi_madhava().
static int madhava_count = 0;

// The function pi_madhava() calculates the value of pi using the Madhava series.
// The formula is pi = the square root of 12 times the sum from k = 0 to k = n
// of 1 / ((-3)^k) (2k + 1))
// Inputs: None.
// Outputs: The value of pi as a double.

double pi_madhava(void) {
    // Make sure we are starting from a count of 0.
    (madhava_count = 0) ? madhava_count : (madhava_count = 0);

    // The "sum" keeps track of the sum of all terms
    double sum = 0.0;
    // The "term_two" refers to the (2k + 1) part of the formula
    double term_two = 0.0;
    // The "exp_part" refers to the (-3)^k part of the formula
    double exp_part = 1.0;
    // The "fraction" is the term 1/(exp_part)(term_two) inside the sum
    double fraction = 1.0;

    while (absolute(fraction) > EPSILON) {
        // If it's the first iteration, 1/((-3)^0) (2(0) + 1)) = 1
        // Otherwise, calculate each part of the fraction
        if (madhava_count == 0) {
            fraction = 1.0;
        } else {
            exp_part = (double) exp_part * (-3.0);
            term_two = (double) (2.0 * madhava_count) + 1.0;
            fraction = (double) 1.0 / (exp_part * term_two);
        }

        // Increment the iteration count and update the sum
        sum += fraction;
        madhava_count += 1;
    }

    // After the term becomes smaller than EPSILON, the
    // square root of 12 multiplied by the sum of all terms is pi
    return ((sqrt_newton(12.0)) * sum);
}

// The function pi_madhava_terms() calculates the number of iterations that the
// function pi_madhava() took in order to produce the value of pi.
// Inputs: None.
// Outputs: The number of iterations taken by pi_madhava().

int pi_madhava_terms(void) {
    return madhava_count;
}
