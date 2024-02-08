#include<stdio.h>
#include<math.h>
double func(double x){
    return x*x*x - 4*x + 1;
}
double func1(double x){
    return 3*x*x - 4;
}
double raphson(double a, double e){
    double b;
    do {
        b = a - (func(a) / func1(a));
        if(fabs(func(b)) <= 0.000) {
            return b;
        }
        a = b;
    } while(fabs((b - a) / b) <= e);
    return b;
}
int main(){
    double a, e = 0.001;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("The root is: %.6lf\n", raphson(a, e));
    return 0;
}

