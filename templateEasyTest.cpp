#include <iostream>
using namespace std;
template <class T>
T square(T x)
{
T result;
result = x * x;
return result;
};
main()
{
int i, ii;
float x, xx;
double y, yy;
i = 2;
x = 2.2;
y = 2.2;
ii = square<int>(i);
cout << i << ": " << ii << endl;
xx = square<float>(x);
cout << x << ": " << xx << endl;
// Explicit use of template
yy = square<double>(y);
cout << y << ": " << yy <<endl;
yy = square(y);
cout << y << ": " << yy << endl;
}