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

int main() {
    printf("is_odd(3): %d\n", is_odd(3));
    printf("is_odd(6): %d\n", is_odd(6));
    printf("is_vowel('i'): %d\n", is_vowel('i'));
    printf("is_vowel('g'): %d\n", is_vowel('g'));
    printf("is_vowel('6'): %d\n", is_vowel('6'));
    return 0;
}