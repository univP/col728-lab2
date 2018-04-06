int printf(char* format, ...);

int add0(int x) {
    return x + 0;
}

int mul0(int x) {
    return x*0; 
}

int mul1(int x) {
    return x*1;
}

int mod0(int x) {
    return 0%x;
}

int div0(int x) {
    return 0/x;
}

int sub01(int x) {
    return -x;
}

int sub02(int x) {
    return x-0;
}

int compl(int x) {
    return (x+0)*(x-0) + x*1;
}

int main() {
    int y,x;
    x = (y = 3) * 2;
    printf("%d\n", add0(x));
    printf("%d\n", mul0(x));
    printf("%d\n", mul1(x));
    printf("%d\n", mod0(x));
    printf("%d\n", div0(x));
    printf("%d\n", sub01(x));
    printf("%d\n", sub02(x));
    printf("%d\n", compl(x));
    return 0;
}