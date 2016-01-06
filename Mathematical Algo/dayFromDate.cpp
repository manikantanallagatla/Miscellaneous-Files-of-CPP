/* A program to find day of a given date */
#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
string dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int x =  ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    switch(x){
    case 0:
        return "Sunday";
    case 1:
        return "Monday";
    case 2:
        return "Tuesday";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday";
    case 5:
        return "Friday";
    case 6:
        return "Saturday";

    }
}

/* Driver function to test above function */
int main()
{
    string day = dayofweek(18, 1, 1995);
    cout<<day<<endl;

    return 0;
}
