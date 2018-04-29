int printf(char* format, ...);

int test_cse(int x, int y, int w) {
    int u,v;
    u = x*y;

    if (w == 0) {
        w = 1;
    } else {
        w = 0; 
    }

    v = x*y;
    printf("%d %d %d\n", u, v, w);
    return 0;
}

int main() {
    test_cse(2, 3, 1);
    return 0;
}