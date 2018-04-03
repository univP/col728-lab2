int printf(char* format, ...);

int compute(int x) {
    return (1 + 2 + x)*(x + (1 + 2));
}

int main() {
    printf("%d\n", compute(5));
    return 0;
}