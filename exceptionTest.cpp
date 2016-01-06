
// calc_err.cpp: Tests the function calc(),
// which throws exceptions.
// ----------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
class Error
{
// Infos about the error cause
};
double calc( int a, int b )
{
if ( b < 0 )
throw (string)"Denominator is negative!";
if( b == 0 )
{
Error errorObj;
throw errorObj;
}
return ((double)a/b);
}
int main()
{
int x, y;
double res;
bool flag = false;
do
{
try // try block
{
cout << "Enter two positive integers: ";
cin >> x >> y;
res = calc( x, y);
cout << x << "/" << y << " = " << res << endl;
flag = true; // Then to leave the loop.
}
catch( string& s) // 1st catch block
{
cerr << s << endl;
}
catch( Error& ) // 2nd catch block
{
cerr << "Division by 0! " << endl;
}
catch(...) // 3rd catch block
{
cerr << "Unexpected exception! \n";

}
}while( !flag);
// continued ...
return 0;
}
