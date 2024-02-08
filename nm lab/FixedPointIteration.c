#include <stdio.h>
#include <math.h>
#define f(x) (x*x - 8)
#define g(x) ((8 + x*x)/(2*x))
int main() {
    int step = 1, N;
    float x0, x1, e;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);
    printf("Fixed Point Iteration Method\n\n");
    do {
        x1 = g(x0);
        printf("Iteration-%d: x1 = %f and f(x1) = %f\n", step, x1, f(x1));
        step++;
        if (step > N) {
            printf("Not Convergent.");
            return 0;
        }
        x0 = x1;
    } while (fabs(f(x1)) > e);
    printf("\nRoot is %f", x1);
    return 0;
}
