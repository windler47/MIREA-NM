#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>      // std::setw
#include <cstdlib>      //string to double function
#include "my_math.hpp"

using namespace std;

int lab3(string fun, double x, double e, double a = 0);
void print_help();

int main(int argc, char *argv[])
{
    std::string digits[] = {"1","2","3","4","5","6","7","8","9"};
    bool wrong_param = false;
    int result = 1;
    if (argc>1) {
        if ( !digits[0].compare(argv[1]) || !digits[1].compare(argv[1]) ) {
            cerr << "no program for this lab";
            return 2;
        } else if ( !digits[2].compare(argv[1]) ) {
            string functions[] = {"sin","cos","exp","ln","lg","log"};
            wrong_param = true;
            for (int i=0; i<5; i++) {
                if ( !functions[i].compare(argv[2]) && argc>3 ) {
                    result = lab3(functions[i], strtod(argv[3],nullptr), strtod(argv[4],nullptr));
                    wrong_param = false;
                }
            }
            if ( !functions[5].compare(argv[2]) && argc>4 ) {
                result = lab3(functions[5], strtod(argv[3],nullptr), strtod(argv[4],nullptr), strtod(argv[5],nullptr));
                wrong_param = false;
            }
        } else {
            wrong_param = true;
        }
    } else {
        wrong_param = true;
    }
    switch (result) {
    case 1:
        wrong_param = true;
    }

    if (wrong_param) {
        print_help();
        return 1;
    }

    return 0;
}

int lab3(string fun, double x, double e, double a)
{
    cout << "function: "<< fun << "\n";
    cout << "argument = " << x << "\n";
    cout << "epsilon = " << e << "\n";
    cout << "optional argument = " << a;
    double result = my_sin(5,0.001);
    cout << "M_PI = " << result;
    return 0;
}

void print_help()
{
    cout << setw(10);
    cout << "lab3:" << "%{function} %{x} %{eps} [%{a}]";
}


