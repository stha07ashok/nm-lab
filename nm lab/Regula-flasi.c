#include <stdio.h>
#include <math.h>
double f(double x) {
    return x * x - 2;
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
    xn = (a * f(b) - b * f(a)) / (f(b) - f(a));
    fxn = f(xn);
    while (fabs(b - a) > E) {
        if (fxn > 0)
            b = xn;
        else
            a = xn;
        xn = (a * f(b) - b * f(a)) / (f(b) - f(a));
        fxn = f(xn);
    }
    printf("Root: %lf\n", xn);
    return 0;
}
