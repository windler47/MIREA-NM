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
double my_log(double a, double x, double e);

double my_sin(double x, double e)
{
    if (e >= 0.5) return 0.5;
    double result = 0;
    int_fast8_t sign = 1;
    //make argument positive
    if ( x<0 )
    {
        if (fabs(sin(x)+sin(-x))<e)
        {
            sign*= (-1);
            x=-x;
        }
        else std::cout<<"You are wrong!";
    }
    //make argument < 2 pi
    while (x>2*M_PI) x-=2*M_PI;
    if (x>M_PI)
    {
        if (fabs(sin(x)+sin(x-M_PI))<e)
        {
            x-=M_PI;
            sign*=(-1);
        }
        else std::cout<<"You are wrong!";
    }
    if (x>M_PI_2)
    {
        if( (fabs(sin(x) - sin(fabs(x-M_PI))))<e)
        {
            x=fabs(x-M_PI);
        }
        else std::cout<<"You are wrong!";
    }
    if (x>M_PI_4)
    {
        if (fabs(sin(x)-cos(M_PI_2-x))<e)
        {
            result=my_cos(M_PI_2-x,e);
        }
        else std::cout<<"You are wrong!";
    }
    else
    {
//        result = sin(x);
        int den = 1;
        double denf = 1;
        double xp = x;
        result = x;
        while ( fabs(xp/denf) > e )
        {
            denf *= (den+1) * (den+2);
            den+=2;
            xp *= (-1)*x*x;
            result+=xp/denf;
        }
        if (fabs(sin(x)-result)>e) {
                std::cout<<"bad series!";
        }
    }
    return sign*result;
}

double my_cos(double x, double e)
{
    return cos(x);
//    if (e >= 0.5) return 0.5;
//
//    double result = 0;
//    int_fast8_t sign = 1;
//    //make argument positive
//    if ( x<0 )
//    {
//        x=fabs(x);
//    }
//    //make argument < 2 pi
//    while (x>2*M_PI) x-=2*M_PI;
//    if (x>M_PI)
//    {
//        x-=M_PI;
//        sign*=(-1);
//    }
//    if (x>M_PI_2)
//    {
//        if( (fabs(cos(x) + cos(fabs(x-M_PI))))<e)
//        {
//            x=fabs(x-M_PI);
//            sign*=(-1);
//        }
//        else std::cout<<"You are wrong!";
//    }
//    if (x>M_PI_4)
//    {
//        if (fabs(cos(x)-sin(M_PI_2-x))<e)
//        {
//            result=my_sin(M_PI_2-x,e);
//        }
//        else std::cout<<"You are wrong!";
//    }
//    else
//    {
//        int den = 2;
//        double denf = 2;
//        double xp = (-x)*x;
//        result = 1 + xp/denf ;
//        while ( fabs(xp/denf) >= e )
//        {
//            denf *= (den+1) * (den+2);
//            den+=2;
//            xp *= (-1)*x*x;
//            result+=xp/denf;
//        }
//    }
//    return result;
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
    double denf = 1;
    double xp = 1;
    result = xp/denf;
    while (abs(xp/denf)>=e)
    {
        xp*=x;
        den++;
        denf*=den;
        result+=xp/denf;
    }
    return result;
}

double my_ln(double x, double e)
{
    double result = 0;
    if (x==0) return std::numeric_limits<double>::signaling_NaN();
    if (x==1) return 0;
    if (abs(x)<1)
    {
        double y = x-1;
        double yp = y;
        double den = 1;
        result = yp/den;
        std::cout << abs(yp/den);
        while (abs(yp/den) > e)
        {
            den = (-1)*(den+1);
            yp*=y;
            result += yp/den;
        }
    }
    else
    {
        int tp = 0;
        while (x>1)
        {
            x = x/10;
            tp++;
        }
        result = my_ln(x,e)+tp*M_LN10;
    }
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
