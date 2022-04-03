#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>

#include"exprtk.hpp"
using namespace std;

//parses string and evaluates given function
double func(string fun,double z)
{
    typedef double T;
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>   expression_t;
    typedef exprtk::parser<T>       parser_t;

    const string funct = fun;
    
    double x;
    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(fun, expression);
    x = z;

    return expression.value();
}

// bisection solver function
void bisection(string fun, double a, double b, double error)
{
    if (func(fun, a) * func(fun, b) >= 0)
    {
        cout << "f(a): " << func(fun, a) << " f(b): " << func(fun, b) << " f(a)*f(b): " << func(fun, a)*func(fun, b) << endl;
        cout << "Invalid x0 and x1, f(a)*f(b) is not less than zero" << endl;
        return;
    }
    cout << setw(15); cout << "Iteration"; cout << setw(15); cout << "x0"; cout << setw(15); cout << "x1"; cout << setw(15); cout << "x2"; cout << setw(15); cout << "f(x0)"; cout << setw(15); cout << "f(x1)"; cout << setw(15); cout << "f(x2)"; cout << setw(15); cout << "Absolute Error" << endl;
    double c = a, err;
    int Iteration = 1;
    do
    {
        double  x0 = a, x1 = b;
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (fun, (c) == 0.0)
            break;

        // Decide which bound to replace to repeat the steps
        else if (func(fun, c) * func(fun, a) < 0) {
            err = abs(b - c);
            b = c;
        }
        else {
            err = abs(a - c);
            a = c;
        }
        
        cout << setw(15); cout << Iteration; cout << setw(15); cout << setprecision(4); cout << x0; cout << setw(15); cout << setprecision(4); cout << x1; cout << setw(15); cout << setprecision(4); cout << c; cout << setw(15); cout << setprecision(4); cout << func(fun, x0); cout << setw(15); cout << setprecision(4); cout << func(fun, x1); cout << setw(15); cout << setprecision(4); cout << func(fun, c); cout << setw(15); cout << setprecision(4); cout << err << endl;
        Iteration++;

    } while (abs(err) >= error);
    cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
    cout << "input fuction to solve(write 'e^x' as 'exp(x)', '2e^x' as '2(exp(x)) or 2*exp(x),'\n";
    cout << "'logbase(x)' as '(log(x))/(log(base))', 2sqrt(x) as '2(sqrt(x)) or 2*sqrt(x),'\n ";
    cout << "'2sinx' as '2(sin(x))', 'sin^2(x)' as (sin(x))^2, same rules apply for other trig functions'\n";
    cout << "use x as variable): ";
    string fun;
    getline(cin, fun);
    cout << "input lower bound x0: ";
    double a,b;
    cin >> a;
    cout << "input upper bound x1: ";
    cin >> b;
    cout << "input Absolute error value: ";
    double error;
    cin >> error;
    bisection(fun, a, b, error);
    return 0;
}
