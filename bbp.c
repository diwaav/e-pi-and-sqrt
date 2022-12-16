#include "mathlib.h"

// The bbp_count keeps track of the number of iterations taken
// by the function pi_bbp().
static int bbp_count = 0;

// The function pi_bbp() calculates the value of pi using the Bailey-Borwein-Plouffe
// formula. I used the Horner normal form for this function.
// The formula is pi = sum from k = 0 to k = n
// of (16^-k times (k (120k + 151) + 47) / (k (k (k (512k + 1024) + 712) + 194) + 15))
// Inputs: None.
// Outputs: The value of pi as a double.

double pi_bbp(void) {
    // Make sure we are starting from a count of 0.
    (bbp_count = 0) ? bbp_count : (bbp_count = 0);

    // The "sum" keeps track of the sum of all terms, but we start with 0.
    double sum = 0.0;
    // The "fraction" represents the fraction portion of the summation.
    double fraction = 0.0;
    // The variable "top" is the top of the fraction,
    // and "bottom" is the bottom of the fraction.
    double top = 0.0;
    double bottom = 0.0;
    // The variable "outside" is the 16^-k portion of the summation is represented by the variable
    double outside = 1.0;
    // The variable "term" puts the fraction and the 16^-k portions
    // together as one term in the summation
    double term = 1.0;

    while (absolute(term) > EPSILON) {
        // Calculate fraction part
        top = (bbp_count * (120.0 * bbp_count + 151.0) + 47.0);
        bottom = (bbp_count * (512.0 * bbp_count + 1024.0) + 712.0);
        bottom = bbp_count * (bbp_count * (bottom) + 194.0) + 15.0;
        fraction = (double) top / bottom;

        // Calculate the 16^-k part of the summation
        if (bbp_count == 0) {
            outside = 1.0;
        } else {
            outside = (double) outside * (1.0 / 16.0);
        }

        // Increment the count of iterations
        bbp_count += 1;
        // Put the two parts of the summation together and update the total sum
        term = (double) outside * fraction;
        sum += term;
    }

    // After the term becomes smaller than EPSILON, the sum of all these terms is pi
    return sum;
}

// The function pi_bbp_terms() calculates the number of iterations that the
// function pi_bbp() took in order to produce the value of pi.
// Inputs: None.
// Outputs: The number of iterations taken by pi_bbp().

int pi_bbp_terms(void) {
    return bbp_count;
}
