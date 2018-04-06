int printf(char* format, ...);

void and(int x, int y) {
    x = x & y;
    int p, q, r, s;
    p = x & 0;
    p = 0 & x;
    r = -1 & y;
    s = y & -1;
}

int main() {
    int y,x;
    x = (y = 3) * 2;
    return 0;
}