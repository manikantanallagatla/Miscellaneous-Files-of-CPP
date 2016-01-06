#include <iostream>

using namespace std;

int main ()
{
long long factorOf  = (600851475143);
int num = 2;

while ((num * num) <= factorOf)

if (factorOf % num == 0)
{
cout << num << endl;
factorOf /= num;
}else
num++;

cout << factorOf << endl;
}
