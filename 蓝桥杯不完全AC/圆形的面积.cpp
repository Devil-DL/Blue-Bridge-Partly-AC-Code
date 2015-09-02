#include <iostream>
#include <iomanip>  
#define PI 3.141592653589793238463
#define eightPI 314159265.3589793238463
using namespace std;
int main()
{
    long  a;
    cin>>a;
    long long ans=PI*a*a;//答案的整数部分 
    long long ans1=eightPI*a*a;
    ans1=(ans1+5)/10;
    ans1=ans1%(10000000);
    double ans2=(double)ans1/1e7;
    cout<<fixed<<setprecision(7)<<ans+ans2<<endl;
    return 0;
    
}