int printf(char* format, ...);

int fib_rec(int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return 1;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_iter(int n) {
    int a,b;
    a = 1;
    b = 1;
    int i;

    for (i = 1; i < n; i = i + 1) {
        int c;
        c = a+b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    printf("Fib Rec: %d\n", fib_rec(0));
    printf("Fib Iter: %d\n", fib_iter(0));
    printf("Fib Rec: %d\n", fib_rec(1));
    printf("Fib Iter: %d\n", fib_iter(1));
    printf("Fib Rec: %d\n", fib_rec(6));
    printf("Fib Iter: %d\n", fib_iter(6));
    return 0;
}