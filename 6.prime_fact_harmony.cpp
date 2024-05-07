#include<bits/stdc++.h>
using namespace std;
const int mx = 1e7+123;
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

const int pMX = 1e7+123;
vector<int> factors[pMX];

int main()
{

    int lim = 1e6;
    primeGen(lim);

    for ( auto p : primes ) {
        for ( int i = p; i <= lim; i += p ) {
            int n = i;

            while ( n % p == 0 ) {
                factors[i].push_back(p);
                n /= p;
            }
        }
    }

    for ( int i = 1; i <= 10; i++ ) {
        cout << i << ": ";
        for ( auto p : factors[i] ) cout << p << " ";
        cout << endl;
    }



    return 0;
}

/* 

1: 
2:  2 
3:  3 
4:  2 2 
5:  5 
6:  2 3 
7:  7 
8:  2 2 2 
9:  3 3 
10: 2 5  

*/