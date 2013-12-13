#ifndef MY_MATH_INCLUDED
#define MY_MATH_INCLUDED
#include <cmath>
double my_sin(double x, double e);
double my_cos(double x, double e);
double my_exp(double x, double e);
double my_ln(double x, double e);
double my_lg(double x, double e);
double my_log(double a, double x, double e);

double my_sin(double x, double e)
{
    if (e >= 0.5) return 0.5;
    double result = 0;
    int_fast8_t sign = 1;
    if ( x<0 ) {
        sign*= (-1);
        x=-x;
    }
    while (x>2*M_PI) x-=2*M_PI;
    if (x>M_PI) {
        sign*= (-1);
        x-=M_PI;
    }
    if ( x>M_PI_2 ){
        result = my_cos(x-M_PI_2,e);
    }
    else {
        if (x>M_PI_4) {

        }
    }
    return result;
}

double my_cos(double x, double e)
{
    return 0;
}

double my_exp(double x, double e)
{
    return 0;
}

double my_ln(double x, double e)
{
    return 0;
}

double my_lg(double x, double e)
{
    return 0;
}

double my_log(double a, double x, double e)
{
    return 0;
}

#endif // MY_MATH_INCLUDED
