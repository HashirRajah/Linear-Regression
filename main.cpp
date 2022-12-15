#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// function prototypes
void displayHeader();
void calculations();
void inputvalues_x_y_plus_calculations(double x[], double y[], double xy[], double xsquare[], double ysquare[], double sums[], int n);

int main()
{
    system("Color 02");
    //
    displayHeader();
    //
    calculations();
    //
    return 0;
}

// displayHeader function
void displayHeader()
{
    // open file
    ifstream fileObj("name.txt");
    cout << endl;
    //
    if (fileObj.is_open())
    {
        string ascii;
        while (getline(fileObj, ascii))
        {
            cout << ascii << endl;
        }
    }
    else
    {
        cout << "Linear Regression";
    }
    //
    cout << endl;
    // close file
    fileObj.close();
}
// calculations function
void calculations()
{
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    double x[n];
    double y[n];
    double xy[n];
    double xsquare[n];
    double ysquare[n];
    double sums[5];

    inputvalues_x_y_plus_calculations(x, y, xy, xsquare, ysquare, sums, n);

    cout << "x\t\ty\t\txy\t\tx_square\ty_square" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t\t" << y[i] << "\t\t" << xy[i] << "\t\t" << xsquare[i] << "\t\t" << ysquare[i] << endl;
    }

    cout << endl;
    cout << "Sumations" << endl
         << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << sums[j] << "\t\t";
    }
    cout << endl
         << endl;
    // Correlation coefficient
    double corre_coeff, a, b, c, d;
    a = (n * sums[2] * 1.0) - (sums[0] * sums[1]);
    b = (n * 1.0 * sums[3]) - (pow(sums[0], 2));
    c = (n * 1.0 * sums[4]) - (pow(sums[1], 2));
    d = b * c;
    corre_coeff = a / (sqrt(d));
    cout << "Correlation coefficient: " << corre_coeff << endl
         << endl;
    // equation regression line y on x
    double e, f, avgx, avgy;
    avgx = (sums[0]) / (n * 1.0);
    avgy = (sums[1]) / (n * 1.0);
    e = a / b;
    f = avgy - ((a / b) * avgx);

    cout << "Gradient of equation line y on x(Regression coefficient): " << e << endl;
    cout << "y-intercept of equation line y on x: " << f << endl
         << endl;
    cout << "Equation of the regression line y on x: " << endl
         << endl;
    cout << "y = " << f << " + " << e << "x" << endl
         << endl;
    // equation regression line x on y
    double g, h;
    g = a / c;
    h = avgx - ((a / c) * avgy);

    cout << "Gradient of equation line x on y(Regression coefficient): " << g << endl;
    cout << "y-intercept of equation line x on y: " << h << endl
         << endl;
    cout << "Equation of the regression line x on y: " << endl
         << endl;
    cout << "x = " << h << " + " << g << "y" << endl;
}
// inputvalues_x_y_plus_calculations function
void inputvalues_x_y_plus_calculations(double x[], double y[], double xy[], double xsquare[], double ysquare[], double sums[], int n)
{

    x[n];
    y[n];
    xy[n];
    xsquare[n];
    ysquare[n];
    sums[5];

    double sumx = 0;
    double sumy = 0;
    double sumxy = 0;
    double sumxsquare = 0;
    double sumysquare = 0;

    cout << "Enter pair of values for x and y." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x: ";
        cin >> x[i];
        cout << "y: ";
        cin >> y[i];

        xy[i] = x[i] * y[i];
        xsquare[i] = pow(x[i], 2);
        ysquare[i] = pow(y[i], 2);

        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + xy[i];
        sumxsquare = sumxsquare + xsquare[i];
        sumysquare = sumysquare + ysquare[i];
        system("cls");
    }

    sums[0] = sumx;
    sums[1] = sumy;
    sums[2] = sumxy;
    sums[3] = sumxsquare;
    sums[4] = sumysquare;
}