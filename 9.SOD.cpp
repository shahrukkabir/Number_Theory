/* 
int sumOfDivisors(int n) {
    int sum = 0;
    int sqrtNum = sqrt(n);
    for (int i = 1; i <= sqrtNum; i++) {
        if (n % i == 0) {
            sum += i; 
            if (i != n/i) {
                sum += n / i;
            }
        }
    }
    return sum;
}
*/


/* 
int sumOfDivisors(int N) {
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        if (N % i == 0) {  
            sum += i;     
        }
    }
    return sum;
}
*/

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
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

ll SOD ( int n )
{
    ll sod = 1;
    for ( auto p : primes ) {
        ll sum = 1;
        if( 1LL * p * p > n ) break;
        if( n % p == 0 ) {
            ll a = 1;
            while ( n % p == 0 ) {
                a*=p;                     // 5292 = 2^2 * 3^3 * 7
                sum+=a;                   // SOD(5292) = (2^0+2^1+2^2)*(3^0+3^1+3^2+3^3)*(7^0+7^1)
                n /= p;                   // SOD(5292) = (1+2^1+2^2)*(1+3^1+3^2+3^3)*(1+7)
            }
        }
        sod*=sum;
        
    }
    if(n > 1) {
        sod*=(n+1);
    }

    return sod;
}

int main()
{

    int lim = 1e8;
    primeGen(lim);

    int n; cin>>n;
    cout<<SOD(n)<<endl;

    return 0;
}
