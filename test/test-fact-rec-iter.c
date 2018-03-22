int printf(char* format, ...);

int fact_rec(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fact_rec(n-1);
}

int fact_iter(int n) {
    int i, result;
    result = 1;

    for (i = 1; i <= n; i = i + 1) {
        result = result * i;
    }

    return result;
}

int main() {
    printf("Fact Rec: %d\n", fact_rec(0));
    printf("Fact Iter: %d\n", fact_iter(0));
    printf("Fact Rec: %d\n", fact_rec(6));
    printf("Fact Iter: %d\n", fact_iter(6));
    return 0;
}