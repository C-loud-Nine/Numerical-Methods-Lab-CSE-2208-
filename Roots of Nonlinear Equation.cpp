#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char ch[101];
double a, b, c;

double f(double x) {
    return 1 * x * x * x - 1 * x * x + 1 * x - 10; // Updated equation
}

double diff(double x) {
    return 3 * 1 * x * x - 2 * 1 * x + 1; // Derivative of the updated equation
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
    int maxIterations = 1000; 
    double tolerance = 0.0001; 

    while (abs(x2 - x1) > tolerance && cnt < maxIterations) {
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
            x1 = x3;-

        cnt++;#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch[101];
double a, b, c;

double f(double x) {
    return a * x * x + b * x + c;
}

double diff(double x) {
    return 2 * a * x + b;
}

void newmethod() {
    double x1 = 0;
    double x2 = x1 - f(x1) / diff(x1);
    while (abs(x2 - x1) > 0.0001) {
        double x3 = x2 - f(x2) / diff(x2);
        cout << x2 << " " << x3 << endl;
        x1 = x2;
        x2 = x3;
    }
    cout << x1 << endl;
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
    a = 0, b = 0, c = 0;
    double x1, x2;

    cout << "Enter equation (ax^2+bx+c=0):\n";
    char s[1000];
    scanf("%[^\n]%*c", s);
    sscanf(s, "%lfx^2%lfx%lf=0", &a, &b, &c);
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    // cout << "Enter initial values of x1 and x2:\n";
    // cin >> x1 >> x2;

    false_position(x1, x2); // Call False Position method

    bisection(x1, x2); // Call Bisection method

    return 0;
}
    }

    if (cnt == maxIterations) {
        cout <<"Max it reached"<<endl;
    } else {
        cout << "False Position Solution: " << x2 << " " << cnt << endl;
    }
}

int main() {
    double a = 0, b = 0, c = 0,d=0;
    double x1, x2;

    cout << "Enter equation (ax^3-bx^2+cx=d):\n";  // Prompt the user for the equation
    char s[1000];
    scanf("%[^\n]%*c", s);

    // Use sscanf to extract coefficients a, b, c, and d from the input string
    sscanf(s, "%lfx^3%lfx^2%lfx=%lf", &a, &b, &c, &d);

    cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

    cout << "Enter initial values of x1 and x2:\n";
    cin >> x1 >> x2;
   
   cout<<x1<<" "<<x2<<endl;
   false_position(x1, x2); 

   secant(x1, x2); 

    return 0;
}