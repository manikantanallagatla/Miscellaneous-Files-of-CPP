#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
using namespace std;
void printPascal(int n)
{
  for (int line = 1; line <= n; line++)
  {
    int C = 1;  // used to represent C(line, i)
    for (int i = 1; i <= line; i++)
    {
      printf("%d ", C);  // The first value in a line is always 1
      C = C * (line - i) / i;
    }
    printf("\n");
  }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n = 7;
    printPascal(n);
    return 0;
}
