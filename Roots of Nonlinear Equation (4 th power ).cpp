//  1x^4-2x^3-4x^2+4x+4=0
//  -2 3

//roots : 1.41, -1.41 , 2.73 , -0.73 


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double a, b, c, d, e;

double f(double x) {
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}

double diff(double x) {
    return 4 * a * x * x * x + 3 * b * x * x + 2 * c * x + d;
}

void newmethod(double x1, double x2) {
    double x = x1;

    while (abs(f(x)) > 0.0001) {
        x = x - f(x) / diff(x);
    }

    cout << "Root found at x = " << x << endl;
}


void secant(double x1, double x2) {
    int cnt = 0;
    double x3, xm;

    while (abs(x2 - x1) > 0.0001) {
        x3 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        cout << "x1 =" << x1 << "  f(x1)" << f(x1) << endl;
        cout << "x2 =" << x2 << "->  f(x2)" << f(x2) << endl;
        x1 = x2;
        x2 = x3;
        cnt++;
    }
    cout << x2 << " " << cnt << endl;
}

void false_position(double x1, double x2) {
    int cnt = 0;

    while (abs(x2 - x1) > 0.0001) {
        double fx1 = f(x1);
        double fx2 = f(x2);

        if (fabs(fx1 - fx2) < 1e-9) {
            cout << "False Position: division by 0\n";
            return;
        }

        double x3 = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);

        cout << "x1 = " << x1 << "  f(x1) = " << fx1 << endl;
        cout << "x2 = " << x2 << "  f(x2) = " << fx2 << endl;

        if (f(x3) == 0) {
            cout << "False Position: converged after " << cnt << " iterations\n";
            cout << "False Position Solution: " << x3 << " " << cnt << endl;
            return;
        }

        if (f(x1) * f(x3) < 0)
            x2 = x3;
        else
            x1 = x3;

        cnt++;
    }

    cout << "False Position Solution: " << x2 << " " << cnt << endl;
}

void bisection(double x1, double x2) {
    int cnt = 0;

    while (abs(x2 - x1) > 0.0001) {
        double x3 = (x1 + x2) / 2;
        double fx3 = f(x3);

        if (fx3 == 0) {
            cout << "Bisection: converged after " << cnt << " iterations\n";
            cout << "Bisection Solution: " << x3 << " " << cnt << endl;
            return;
        }

        if (f(x1) * fx3 < 0)
            x2 = x3;
        else
            x1 = x3;

        cout << "x1 = " << x1 << "  f(x1) = " << f(x1) << endl;
        cout << "x2 = " << x2 << "  f(x2) = " << f(x2) << endl;
        cnt++;
    }

    cout << "Bisection Solution: " << x2 << " " << cnt << endl;
}

int main() {
    a = 0, b = 0, c = 0, d = 0, e = 0;
    double x1, x2;

    cout << "Enter equation (ax^4+bx^3+cx^2+dx+e=0):\n";
    char s[1000];
    scanf("%[^\n]%*c", s);
    sscanf(s, "%lfx^4%lfx^3%lfx^2%lfx%lf=0", &a, &b, &c, &d, &e);
    cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << ", e: " << e << endl;

    // cout << "Enter initial values of x1 and x2:\n";
     cin >> x1 >> x2;

    //newmethod(x1,x2);

    //secant(x1,x2);
    //false_position(x1, x2); // Call False Position method

    //bisection(x1, x2); // Call Bisection method

    return 0;
}
