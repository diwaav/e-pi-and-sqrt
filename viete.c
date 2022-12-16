#include "mathlib.h"

// The viete_count keeps track of the number of iterations taken
// by the function pi_viete().
static int viete_count = 0;

// The function pi_madhava() calculates the value of pi using the Madhava series.
// The formula is 2 / pi = the product from k = 1 to k = infinite
// of ai / 2 where the first a is the square root of 2 and the rest is
// the square root of (2 + the previous a) for all k > 1.
// Inputs: None.
// Outputs: The value of pi as a double.

double pi_viete(void) {
    // Make sure we are starting from a count of 0.
    (viete_count = 0) ? viete_count : (viete_count = 0);

    // Let a represent the square root of 2 which repeats so much in the formula
    double root_two = sqrt_newton(2.0);
    // The "product" keeps track of the product of all terms, so we start with 1
    double product = 1.0;
    // The "fraction" is one term in product
    double fraction;
    // The "top" keeps track of the previous square root of 2 terms
    double top = root_two;

    while (absolute(2 - top) > EPSILON) {
        // If it's the first iteration, the top of the term should be square root of 2
        // Otherwise, it should be the square root of 2 + previous top
        if (viete_count == 0) {
            top = root_two;
        } else {
            top = sqrt_newton(2 + top);
        }

        // Put the term together as a fraction, update the product
        // of all terms, then increment the iteration count
        fraction = (double) top / 2.0;
        product = (double) product * fraction;
        viete_count += 1;
    }

    // After the difference between 2 and the top of the fraction
    // becomes smaller than EPSILON, then the value of pi is 2 / product
    return 2.0 / product;
}

// The function pi_viete_factors() calculates the number of iterations that the
// function pi_viete() took in order to produce the value of pi.
// Inputs: None.
// Outputs: The number of iterations taken by pi_viete().

int pi_viete_factors(void) {
    return viete_count;
}
