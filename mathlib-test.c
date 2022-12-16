#include "mathlib.h"

#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(int const argc, char **argv) {

    // Declare all the options
    int option = 0;
    bool a_selected = false;
    bool e_selected = false;
    bool b_selected = false;
    bool m_selected = false;
    bool r_selected = false;
    bool v_selected = false;
    bool n_selected = false;
    bool s_selected = false;
    bool help = false;
    double pi = M_PI;
    double e_number = M_E;

    // As long as we have valid inputs, set the corresponding booleans to true
    while ((option = getopt(argc, argv, "aebmrvnsh")) != -1) {
        switch (option) {
        case 'a': a_selected = true; break;
        case 'e': e_selected = true; break;
        case 'b': b_selected = true; break;
        case 'm': m_selected = true; break;
        case 'r': r_selected = true; break;
        case 'v': v_selected = true; break;
        case 'n': n_selected = true; break;
        case 's': s_selected = true; break;
        case 'h': help = true; break;
        default: help = true; break;
        }
    }

    // In case something goes wrong
    if ((a_selected == false) && (e_selected == false) && (b_selected == false)
        && (m_selected == false) && (r_selected == false) && (v_selected == false)
        && (n_selected == false)) {
        help = true;
    }

    // If the user wanted all values to be printed, set them all to true
    if ((a_selected) && (help == false)) {
        e_selected = true;
        b_selected = true;
        m_selected = true;
        r_selected = true;
        v_selected = true;
        n_selected = true;
    }

    // If e was selected, print our function's value of e, the real
    // value of e, and the difference between them
    if ((e_selected) && (help == false)) {
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", e(), e_number,
            absolute(e() - e_number));
        // If statistics display was also selected, show the iterations count
        if (s_selected) {
            printf("e() terms = %d\n", e_terms());
        }
    }

    // If r was selected, print our euler function's value of pi, the real
    // value of pi, and the difference between them
    if ((r_selected) && (help == false)) {
        printf("pi_euler = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_euler(), pi,
            absolute(pi_euler() - pi));
        // If statistics display was also selected, show the iterations count
        if (s_selected) {
            printf("pi_euler() terms = %d\n", pi_euler_terms());
        }
    }

    // If b was selected, print our bbp function's value of pi, the real
    // value of pi, and the difference between them
    if ((b_selected) && (help == false)) {
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_bbp(), pi,
            absolute(pi_bbp() - pi));
        // If statistics display was also selected, show the iterations count
        if (s_selected) {
            printf("pi_bbp_terms() terms = %d\n", pi_bbp_terms());
        }
    }

    // If m was selected, print our madhava function's value of pi, the real
    // value of pi, and the difference between them
    if ((m_selected) && (help == false)) {
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_madhava(), pi,
            absolute(pi_madhava() - pi));
        // If statistics display was also selected, show the iterations count
        if (s_selected) {
            printf("pi_madhava_terms() terms = %d\n", pi_madhava_terms());
        }
    }

    // If v was selected, print our viete function's value of pi, the real
    // value of pi, and the difference between them
    if ((v_selected) && (help == false)) {
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", pi_viete(), pi,
            absolute(pi_viete() - pi));
        // If statistics display was also selected, show the iterations count
        if (s_selected) {
            printf("pi_viete_factors() terms = %d\n", pi_viete_factors());
        }
    }

    // If n was selected, print our newton function's value of the square root of some number, the real
    // value of the square root of that number, and the difference between them. We iterate through
    // values from 0 to 10 incremented by 0.1 and compare the square roots of all of them.
    if ((n_selected) && (help == false)) {
        for (double i = 0.0; i < 10.0; i += 0.1) {
            printf("sqrt_newton(%7.6lf) = %16.15lf, sqrt(%7.6lf) = %16.15lf, diff = %16.15lf\n", i,
                sqrt_newton(i), i, sqrt(i), absolute(sqrt_newton(i) - sqrt(i)));
            // If statistics display was also selected, show the iterations count
            if (s_selected) {
                printf("sqrt_newton(%7.6lf) terms = %d\n", sqrt_newton(i), sqrt_newton_iters());
            }
        }
    } else if ((s_selected) && (argc == 2)) {
        // in the case that no function was specified but the user wanted
        // to display statistics, lead them to the help page
        help = true;
    }

    // If h was selected, or something went wrong, print out the proper use of this test program.
    if ((help) || (argc == 1)) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n");
        printf("\nUSEAGE\n   ./mathlib-test [-aebmrvnsh]\n");
        printf("\nOPTIONS\n");
        printf("  -a   Runs all tests.\n");
        printf("  -e   Runs e tests.\n");
        printf("  -b   Runs BBP pi test.\n");
        printf("  -m   Runs Madhava pi test.\n");
        printf("  -r   Runs Euler pi test.\n");
        printf("  -v   Runs Viete pi test.\n");
        printf("  -n   Runs Newton square root tests.\n");
        printf("  -s   Print verbose statistics.\n");
        printf("  -h   Display program synopsis and usage.\n");
    }

    return 0;
}
