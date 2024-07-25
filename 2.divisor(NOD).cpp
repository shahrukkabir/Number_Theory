
 int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }                                 // O(n)
    }
    return count;
}



 int countDivisors(int n) {
    int count = 0;
    int sqrtNum = sqrt(n);
    for (int i = 1; i <= sqrtNum; i++) {
        if (n % i == 0) {
            count++;                                 //O(√N)
            if (i != sqrtNum) {
                count++;
            }
        }
    }
    return count;
} 
            


//     1  2  3  4      6      9  12  18  36  -> 9 divisor of 36 
// If i is a divisor, count it
// If i is not the square root, count its pair



 
            int lim=1e6;
            for(int i=1;i<=lim;i++){
                for(int j=i;j<=lim;j+=i){        //Harmony Series -> n*ln(n)
                    cnt[j]++;
                }
            }



