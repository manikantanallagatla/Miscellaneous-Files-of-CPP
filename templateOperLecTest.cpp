#include<iostream>
using namespace std;
template<class T>
class mypair{
T a, b;
public:
mypair(T first,T second)
{
a=first;
b=second;
}
T getmax();
};
template<class T>
T mypair<T>::getmax(){
return a>b? a:b;
}
main()
{
mypair<int> myints(100, 75);
mypair<float> myfloats(12.0,2.0);
cout<<myints.getmax()<<endl;
cout<<myfloats.getmax()<<endl;
}
