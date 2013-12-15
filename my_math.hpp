#ifndef MY_MATH_INCLUDED
#define MY_MATH_INCLUDED
#include <cmath>
#include <limits>
#include <iostream>
double my_sin(double x, double e);
double my_cos(double x, double e);
double my_exp(double x, double e);
double my_pow(double x, int n);
double my_pow(double x, double y);
double my_ln(double x, double e);
double my_lg(double x, double e);
double my_log(double x, double a, double e);

double my_sin(double x, double e)
{
    if (e >= 0.5) {
        return 0.5;
    }
    double result = 0;
    int_fast8_t sign = 1;
    //make argument positive
    if ( x < 0 ) {
        sign *= (-1);
        x = -x;
    }
    //make argument < 2 pi
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }
    if (x > M_PI) {
        x -= M_PI;
        sign *= (-1);
    }
    if (x > M_PI_2) {
        x = fabs(x - M_PI);
    }
    if (x > M_PI_4) {
        result = my_cos(M_PI_2 - x, e);
    } else {
        int den = 1;
        double denf = 1;
        double xp = x;
        result = x;
        while ( fabs(xp / denf) > e ) {
            denf *= (den + 1) * (den + 2);
            den += 2;
            xp *= (-1) * x * x;
            result += xp / denf;
        }
    }
    return sign * result;
}

double my_cos(double x, double e)
{
    if (e >= 0.5) {
        return 0.5;
    }

    double result = 0;
    int_fast8_t sign = 1;
    //make argument positive
    if ( x < 0 ) {
        x = -x;
    }
    //make argument < 2 pi
    while (x > 2 * M_PI) {
        x -= 2 * M_PI;
    }

    if (x > M_PI) {
        x -= M_PI;
        sign *= (-1);
    }
    if (x > M_PI_2) {
        x = fabs(x - M_PI);
        sign *= (-1);
    }
    if (x > M_PI_4) {
        result = my_sin(M_PI_2 - x, e);
    } else {
        int den = 2;
        double denf = 2;
        double xp = (-x) * x;
        result = 1 + xp / denf ;
        while ( fabs(xp / denf) >= e ) {
            denf *= (den + 1) * (den + 2);
            den += 2;
            xp *= (-1) * x * x;
            result += xp / denf;
        }
    }
    return sign * result;
}

double my_exp(double x, double e)
{
    double result;
    if (x == 0) {
        return 1;
    }
    if (x < 0) {
        result = 1 / my_exp(fabs(x), e);
    } else if (x > 1) {
        double int_part ;
        double frac_part = modf(x, &int_part);
        e = e / int_part;
        result = my_pow( M_E , (int)int_part ) * my_exp( frac_part, e);
    } else {
        int den = 0;
        double denf = 1;
        double xp = 1;
        result = xp / denf;
        while (fabs(xp / denf) >= e) {
            xp *= x;
            den++;
            denf *= den;
            result += xp / denf;
        }
    }
    return result;
}

double my_ln(double x, double e)
{
    double result = 0;
    if (x <= 0) {
        return std::numeric_limits<double>::signaling_NaN();
    }
    if (x == 1) {
        return 0;
    }
    if (x <= 2) {
        x--;
        int den = 1;
        double xp = result = x;
        while (fabs(xp / den) > e) {
            xp *= (-1) * x;
            den++;
            result += xp / den;
        }
    } else {
        int tp = 0;
        while (x > 1) {
            x = x / 10;
            tp++;
        }
        result = my_ln(x, e) + tp * M_LN10;
    }
    return result;
}

double my_lg(double x, double e)
{
    return my_ln(x, e) / M_LN10;
}

double my_log(double x, double a, double e)
{
    return my_ln(x, e) / my_ln(a, e );
}

double my_pow(double x, double y)
{
    if (x == 0) {
        return 0;
    }
    if ( y < 0 ) {
        return 1 / my_pow(x, -y);
    }
    if (y == 0) { return 1; }
    double result;
    double int_part ;
    double frac_part = modf(y, &int_part);
    if (frac_part != 0 && x < 0 ) { result = std::numeric_limits<double>::signaling_NaN(); }
    else if (int_part != 0) { result = my_pow(x, (int)int_part) * my_pow(x, frac_part); }
    else {
        result = exp(y * log(x));
    }
}
double my_pow(double x, int n)
{
    if (x == 0) {
        return 0;
    }
    if ( n < 0 ) {
        return 1 / my_pow(x, -n);
    }
    switch (n) {
    case 0:
        return 1;
    case 1:
        return x;
    case 2:
        return x * x;
    default:
        if(n % 2 == 0) {
            return my_pow(x * x, (int)n / 2);
        } else {
            return x * my_pow(x * x, (int)((n - 1) / 2));
        }
    }
}

#endif // MY_MATH_INCLUDED
