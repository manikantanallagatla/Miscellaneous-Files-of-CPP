#include <iostream>
using namespace std;


LL solve(LL n) // 1^2^3^...^n
{
    LL p=1;
    LL r=0;
    while(n>=p)
    {
        LL x=n/p;
        LL sum=0;
        if(x&1)
        {
            sum+=((x-1)>>1)*p;
            sum+=(n%p)+1;
        }
        else
        {
            sum+=(x>>1)*p;
        }
        r+=(sum&1) ? p : 0;
        p<<=1;
    }
    return r;
}
int main() {
	cout<<solve(5)<<endl;
	return 0;
}

