#include "mathlib.h"

// The e_count keeps track of the number of iterations taken
// by the function e().
static int e_count = 0;

// The funtion e() approximates the value of Euler's number, e.
// The formula is e = sum from k = 0 to k = infinite of (1 / k!).
// Inputs: None
// Outputs: The value of e as a double.

double e(void) {
    // Make sure we are starting from a count of 0.
    (e_count = 0) ? e_count : (e_count = 0);

    // The "sum" keeps track of the sum of all terms, but we start with 0.
    double sum = 0.0;
    // The "fraction" represents one term, 1 / k!, inside the summation.
    double fraction = 1.0;

    while (absolute(fraction) > EPSILON) {
        // If we are on the first iteration, 1/(0!) = 1
        // Otherwise, do the 1/k! part by dividing the previous fraction
        // by the count (which is k in the formula)
        if (e_count == 0) {
            fraction = 1.0;
        } else {
            fraction = (double) fraction / e_count;
        }

        // Update the sum by adding in the current term,
        // then increment the count
        sum += fraction;
        e_count += 1;
    }

    // After the fraction becomes smaller than EPSILON, the sum of all these terms is e
    return sum;
}

// The function e_terms() counts how many terms were required for the summation in e().
// Inputs: None
// Outputs: The number of terms used to make e in the function e().

int e_terms(void) {
    return e_count;
}
