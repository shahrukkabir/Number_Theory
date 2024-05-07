/* #include<bits/stdc++.h>
using namespace std;
int main(){
    int a,m; cin>>a>>m;
    int res = a%m;
    if(res<0){
        res+=m;
    }
    cout<<res<<endl;
    return 0;
} */

//Determine 100 factorial modulo 97

#include<bits/stdc++.h>
using namespace std;
int main(){
    int fact=1; 
    
    for(int i=1;i<=10;i++){
        fact=((fact%97)*(i%97))%97;   //fact = (fact*i)%97
        
    }
    cout<<fact<<endl;
}
    
