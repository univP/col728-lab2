int printf(char* format, ...);

int recse(int x) {
    return (1 + 2 + x)*(x + (1 + 2));
}

int dce(int x) {
    if (0) {
        return 0;
    }

    int y;
    y = 5;
    return x;
}

int main() {
    printf("recse(5): %d\n", recse(5));
    printf("dce(10): %d\n", dce(10));
    return 0;
}