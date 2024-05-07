//https://forthright48.com/divisor-summatory-function


//O(√N)
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n; cin>>n;
    int res =  0;
    int u = sqrt(n);
    for(int i=1;i<=u;i++){
        res+=(n/i)-i;           //number of ordered pair (A x B) , where A<B 
    }
    res*=2;
    res+=u;                     //number of ordered pair (A x B) , where A=B               
    cout<<res<<endl;

    return 0;
} 

NOD(1)=1,:(1,1)
NOD(2)=2,:(1,2)(2,1)
NOD(3)=2,:(1,3)(3,1)
NOD(4)=3,:(1,4)(2,2)(4,1)
NOD(5)=2,:(1,5)(5,1)
NOD(6)=4,:(1,6)(2,3)(3,2)(6,1)
NOD(7)=2,:(1,7)(7,1)
NOD(8)=4,:(1,8)(2,4)(4,2)(8,1)
NOD(9)=3,:(1,9)(3,3)(9,1)
NOD(10)=4,:(1,10)(2,5)(5,2)(10,1)

//O(N2)
int SNOD( int n ) {
    int res = 0;
    for ( int i = 1; i <= n; i++ ) { // For each number from 1 - N
        for ( int j = 1; j <= i; j++ ) { // Find possible divisors of "i"
            if ( i % j == 0 ) res++;
        }
    }
    return res;
} 


//O(N×√N/ln(√N))
int SNOD( int n ) {
    int res = 0;
    for ( int i = 1; i <= n; i++ ) {
        res += NOD(i);
    }
    return res;
}


//O(N)
int SNOD( int n ) {
    int res = 0;
    for ( int i = 1; i <= n; i++ ) {
        res += n / i;
    }
    return res;
}



 NOD(1)=1,:1
 NOD(2)=2,:1,2
 NOD(3)=2,:1,3
 NOD(4)=3,:1,2,4
 NOD(5)=2,:1,5
 NOD(6)=4,:1,2,3,6
 NOD(7)=2,:1,7
 NOD(8)=4,:1,2,4,8
 NOD(9)=3,:1,3,9
 NOD(10)=4,:1,2,5,10
 
 SNOD(10) = 10/1+10/2+10/3+10/4+10/5+10/6+10/6+10/7+10/8+10/9+10/10
 SNOD(10) = 10+5+3+2+2+1+1+1+1+1=27
