int printf(char* format, ...);

int main() {
    int i, n;
    n = 10;
    
    for (i = 0; i < 20; i = i + 1) {
        printf("Counter: %d\n", i);
    }

    return 0;
}