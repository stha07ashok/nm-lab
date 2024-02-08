#include <stdio.h>
#include <math.h>

double f(double x) { return x * x - 4; }  // Define the function f(x)
double g(double x) { return sqrt(x + 4); } // Define the iterative function g(x)

double fixedPointIteration(double x, double tol, int maxIter) {
    for (int iter = 1; iter <= maxIter; ++iter) {
        x = g(x);
        if (fabs(f(x)) < tol) {
            printf("Root found: %lf\n", x);
            return x;
        }
    }
    printf("Max iterations reached. No convergence.\n");
    return NAN;
}

int main() {
    double x, tol;
    int maxIter;

    printf("Enter initial guess: ");
    scanf("%lf", &x);

    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    printf("Enter max iterations: ");
    scanf("%d", &maxIter);

    fixedPointIteration(x, tol, maxIter);

    return 0;
}
