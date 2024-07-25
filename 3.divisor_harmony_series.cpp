#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6+123;
int cnt[mx];

int main(){
    int lim=1e6;
    for(int i=1;i<=lim;i++){          //Number of divisor
        for(int j=i;j<=lim;j+=i){
            cnt[j]++;                //T.C: n*ln(n)
        }
    }
    // cout<<cnt[100]<<endl;
    return 0;
} 


1 : 1 
2 : 1 2 
3 : 1 3 
4 : 1 2 4 
5 : 1 5 
6 : 1 2 3 6 
7 : 1 7 
8 : 1 2 4 8 
9 : 1 3 9 
10 : 1 2 5 10 

#include<bits/stdc++.h>
using namespace std;
const int mx = 1e3+123;
vector<int>v[mx];
int main(){
    int lim=10;
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i){       //see all the divisor
            v[j].push_back(i);
        }
    }
    for(int i=1;i<=lim;i++){           
        cout<<i<<" : ";
        for(auto u: v[i]){
            cout<<u<<" ";
        }
        cout<<endl;
    }
    
    return 0;
} 



#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6+123;
int sum[mx];
int main(){
    int lim=10;
    for(int i=1;i<=lim;i++){
        for(int j=i;j<=lim;j+=i){       //sum of divisor
            sum[j]+=i;
        }
    }
    for(int i=1;i<=10;i++){
        cout<<sum[i]<<" ";
    }
    
    return 0;
}