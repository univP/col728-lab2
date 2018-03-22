int printf(char* format, ...);

int main() {
    int x, y;
    x = 10;
    y = 5;
    printf("x + y = %d, x - y = %d, x * y = %d, x / y = %d, x % y = %d\n",
        x+y, x-y, x*y, x/y, x%y);
    float m, n;
    m = 8.0;
    n = 5.0;
    printf("m + n = %f, m - n = %f, m * n = %f, m / n = %f\n",
        13.0, m-n, m*n, m/n);
    return 0;
}