#ifndef MY_MATH_INCLUDED
#define MY_MATH_INCLUDED
#include <cmath>
double my_sin(double x, double e);
double my_cos(double x, double e);
double my_exp(double x, double e);
double my_pow(double x, int n);
double my_pow(double x, double y);
double my_ln(double x, double e);
double my_lg(double x, double e);
double my_log(double a, double x, double e);

double my_sin(double x, double e)
{
    if (e >= 0.5) return 0.5;
    double result = 0;
    int_fast8_t sign = 1;
    //make argument positive
    if ( x<0 )
    {
        sign*= (-1);
        x=-x;
    }
    //make argument < 2 pi
    while (x>2*M_PI) x-=2*M_PI;

    if ( x > 3 * M_PI_4)
    {
        x = 2*M_PI - x;
        sign*= (-1);
    }
    else if ( x > M_PI )
    {
        x-=M_PI;
        sign*= (-1);
    }
    else if ( x > M_PI_2 )
    {
        x = abs(x-M_PI);
    }
    if ( x > M_PI_4 )
    {
        result = my_cos(x - M_PI_4 , e);
    }
    else
    {
        int den = 1;
        double xp = x;
        result = x;
        while ( xp/den >= e )
        {
            den *= (den+1) * (den+2);
            xp *= (-1)*x*x;
            result+=xp/den;
        }
    }
    return result;
}

double my_cos(double x, double e)
{
    if (e >= 0.5) return 0.5;
    double result = 0;
    int_fast8_t sign = 1;
    //make argument positive
    if ( x<0 )
    {
        x=-x;
    }
    //make argument < 2 pi
    while (x>2*M_PI) x-=2*M_PI;

    if ( x > 3 * M_PI_4)
    {
        x = 2*M_PI - x;
    }
    else if ( x > M_PI )
    {
        x-=M_PI;
        sign*= (-1);
    }
    else if ( x > M_PI_2 )
    {
        x = abs(x-M_PI);
        sign*= (-1);
    }
    if ( x > M_PI_4 )
    {
        result = my_sin(x - M_PI_4 , e);
    }
    else
    {
        int den = 2;
        double xp = (-x)*x;
        result = 1 + xp/den ;
        while ( xp/den >= e )
        {
            den *= (den+1) * (den+2);
            xp *= (-1)*x*x;
            result+=xp/den;
        }
    }
    return result;
}

double my_exp(double x, double e)
{
    double result;
    if (x<0) return 1/my_exp(abs(x),e);
    if (x==0) return 1;
    /*    if (x>1){
            double frac_part;
            int int_part = modf(x,&frac_part);
            result = my_pow(my_exp( M_E , int_part ) * my_exp(frac_part,e)
        } //Bad medicine (Don't know how to determine error
        */
    int den = 0;
    int denf = 1;
    double xp = 1;
    result = xp/denf;
    while (xp/den>=e)
    {
        xp*=x;
        den+=1;
        denf*=den;
        result+=xp/denf;
    }
    return result;
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

double my_pow(double x, double y)
{
    return 0;
}
double my_pow(double x, int n)
{
    if (x==0) return 0;
    if ( n<0 ) return 1/my_pow(x,-n);
    switch (n)
    {
    case 0:
        return 1;
    case 1:
        return x;
    case 2:
        return x*x;
    default:
        if(n%2==0)
        {
            return my_pow(x*x,(int)n/2);
        }
        else
        {
            return x*my_pow(x*x,(int)((n-1)/2));
        }
    }
}

#endif // MY_MATH_INCLUDED
