int printf(char* format, ...);

void shift(int x, int y) {
    x = x * 8;
    y = y / 8;
    x = 8 * x;
}

int main() {
    int y,x;
    x = (y = 3) * 2;
    return 0;
}