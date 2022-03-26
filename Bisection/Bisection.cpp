#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//test function for bisection function to solve
double func(double x)
{
    return sqrt(x*x) - x * x + 2;
}

// bisection solver function
void bisection(double a, double b, double error)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "f(a): " << func(a) << " f(b): " << func(b) << " f(a)*f(b): " << func(a)*func(b) << endl;
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
        if (func(c) == 0.0)
            break;
        

        // Decide which bound to replace to repeat the steps
        else if (func(c) * func(a) < 0) {
            err = abs(b - c);
            b = c;
        }
        else {
            err = abs(a - c);
            a = c;
        }
        
        cout << setw(15); cout << Iteration; cout << setw(15); cout << setprecision(4); cout << x0; cout << setw(15); cout << setprecision(4); cout << x1; cout << setw(15); cout << setprecision(4); cout << c; cout << setw(15); cout << setprecision(4); cout << func(x0); cout << setw(15); cout << setprecision(4); cout << func(x1); cout << setw(15); cout << setprecision(4); cout << func(c); cout << setw(15); cout << setprecision(4); cout << err << endl;
        Iteration++;
    } while (abs(err) >= error);
    cout << "The value of root is : " << c;
}

// Driver program to test above function
int main()
{
    cout << "input lower bound x0: " << endl;
    double a,b;
    cin >> a;
    cout << "input upper bound x1: " << endl;
    cin >> b;
    cout << "input Absolute error value" << endl;
    double error;
    cin >> error;
    bisection(a, b, error);
    return 0;
}
