#include <stdio.h>
#include <math.h>
double f(double x) {
    return 2 * x * x * x +4 * x * x-4 * x- 6;
}
int main() {
    double E = 0.0001;
    double x1 = 1.0, x2 = 2.0;
    double fx1 = f(x1), fx2 = f(x2);
    if (fx1 * fx2 > 0) {
        printf("Root does not lie between %lf and %lf\n", x1, x2);
        return 1; // Stop
    }
    double a, b;
    if (fx1 < 0) {
        a = x1;
        b = x2;
    } else {
        a = x2;
        b = x1;
    }
    double xn, fxn;
    xn = (a + b) / 2;
    fxn = f(xn);
    while (fabs(b - a) / 2 > E) {
        if (fxn > 0)
            b = xn;
        else
            a = xn;
        xn = (a + b) / 2;
        fxn = f(xn);
    }
    printf("Root: %lf\n", (a + xn) / 2);
    return 0;
}
