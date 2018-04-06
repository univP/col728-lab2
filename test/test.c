int printf(char* format, ...);

int and(int x, int y) {
    int z;
    z = x & y;
    z = x & 0;
    z = 0 & x;
    z = -1 & y;
    z = y & -1;
    z = x % 8;
    return z;
}

int main() {
    int y,x;
    x = (y = 3) * 2;
    printf("%d\n", and(31, 23));
    return 0;
}