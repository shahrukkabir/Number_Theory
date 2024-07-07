#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int mx = 1e8+123;
bitset<mx> isPrime;
vector<int> primes;

void primeGen ( int n )
{
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int sq = sqrt(n);
    for ( int i = 3; i <= sq; i += 2 ) {
        if(isPrime[i]) {
            for ( int j = i*i; j <= n; j += i ) {
                isPrime[j] = 0;
            }
        }
    }

    isPrime[2] = 1;
    primes.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
}

ll eulerPhi ( ll n )
{
    int res = n;

    for ( auto p : primes ) {
        if( 1LL * p * p > n ) break;
        if( n % p == 0 ) {
            while ( n % p == 0 ) {
                n /= p;
            }
            res/=p;
            res*=(p-1);       // res *= (p-1)/p
        }
    }

    if(n > 1) {
        res/=n;               //res *= (n-1)/n
        res*=(n-1);
    }
    return res;
}

int main()
{

    int lim = 1e8;
    primeGen(lim);

    cout<<eulerPhi(12)<<endl;
    

    return 0;
}



//using harmony series


const int MX = 5e6+123;
ll eulerPhi[MX];

int main(){
    FAST
    int lim = 5e6;
    primeGen(lim);
    for(int i=1;i<=lim;i++){
        eulerPhi[i]=i;
    }
    for(auto p:primes){
        for(int j=p;j<=lim;j+=p){
            eulerPhi[j]/=p;
            eulerPhi[j]*=(p-1);
        }
    }
    for(int i=1;i<=10;i++){
        cout<<i<<" : "<<eulerPhi[i]<<endl;
    }


    return 0;
}