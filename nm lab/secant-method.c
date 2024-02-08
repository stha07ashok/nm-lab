#include <stdio.h>
#include <math.h>
double f(double x) {
    return x * x - 2;
}
int main() {
    double x1 = 1.0, x2 = 2.0, xn, E = 0.0001;
    double fx1, fx2, fxn;
    fx1 = f(x1);
    fx2 = f(x2);
    do {
        xn = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
        fxn = f(xn);
        x1 = x2;
        fx1 = fx2;
        x2 = xn;
        fx2 = fxn;
        if (fabs(xn - x1) > E) {
            continue; 
        } else {
            printf("Root: %lf\n", xn);
            break;
        }
    } while (1);
    return 0;
}
