#ifndef INTEGRAL_HPP_INCLUDED
#define INTEGRAL_HPP_INCLUDED

#include <cmath>
double l_rectangle(double h);
double c_rectangle(double h);
double 	trapeze(double h);
double simpson(double h);
double fun(double x);

double l_rectangle(double h){
    double result = 0;
    for(double x=-2;x<2;x+=h){
        result+=h*fun(x);
    }
    return result;
}

double c_rectangle(double h){
    double result = 0;
    for(double x=-2+h/2;x<2;x+=h){
        result+=h*fun(x);
    }
    return result;
}

double r_rectangle(double h){
    double result = 0;
    for(double x=-2+h;x<=2;x+=h){
        result+=h*fun(x);
    }
    return result;
}

double 	trapeze(double h){
    double result = (fun(-2)+fun(2))*h/2;
    for(double x=-2+h;x<2;x+=h){
        result+=h*fun(x);
    }
    return result;
}

double simpson(double h){
    double result = 0;
    for(double x=-2;x<2-h;x+=h){
        result += h/3*(fun(x)+4*fun(x+h)+fun(x+2*h));
    }
    return result;

}

double fun(double x){
    return x*sqrt(49-x*x);
}
#endif // INTEGRAL_HPP_INCLUDED
