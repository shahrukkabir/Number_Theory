
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {    //i<number/2 , i<number
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}


// i * i <= number -> i<=sqrt(number)


////     1  2  3  4      6      9  12  18  36  -> 9 divisor of 36 


//সেসব সংখ্যাই প্রাইম যাদেরকে সংখ্যাটির বর্গমূলের সমান বা ছোটো কোনো প্রাইম দিয়ে ভাগ করা যায় না |