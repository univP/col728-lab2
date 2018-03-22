int printf(char* format, ...);

int is_odd(int n) {
    return n%2;
}

int is_vowel(char c) {
    if (c < 'a') {
        return 0;
    }

    if ('z' < c) {
        return 0;
    }

    if (c == 'a') {
        return 1;
    }

    if (c == 'e') {
        return 1;
    }

    if (c == 'i') {
        return 1;
    }

    if (c == 'o') {
        return 1;
    }

    if (c == 'u') {
        return 1;
    }

    return 0;
}

int is_leap_year(int year) {
    if (year%400 == 0) // Exactly divisible by 400 e.g. 1600, 2000
        return 1;
    else if ( year%100 == 0) // Exactly divisible by 100 and not by 400 e.g. 1900, 2100
        return 0;
    else if ( year%4 == 0 ) // Exactly divisible by 4 and neither by 100 nor 400 e.g. 2016, 2020
        return 1;
    else // Not divisible by 4 or 100 or 400 e.g. 2017, 2018, 2019
        return 0;  
    
    return 0;
}

int sum_digits(int n) {
    int sum, t, rem;
    sum = 0;
    t = n;

    for (;0 < t;) {
        rem = t %10;
        sum = sum + rem;
        t = t/10;
    }

    return sum;
}

int main() {
    printf("is_odd(3): %d\n", is_odd(3));
    printf("is_odd(6): %d\n", is_odd(6));
    printf("is_vowel('i'): %d\n", is_vowel('i'));
    printf("is_vowel('g'): %d\n", is_vowel('g'));
    printf("is_vowel('6'): %d\n", is_vowel('6'));
    printf("is_leap_year(2012): %d\n", is_leap_year(2012));
    printf("is_leap_year(2100): %d\n", is_leap_year(2100));
    printf("sum_digits(213): %d\n", sum_digits(213));
    return 0;
}