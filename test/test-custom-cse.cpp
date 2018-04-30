int printf(char* format, ...);

void test_op(int op0, int op1) {
    int add0, add1, sub0, sub1, mul0, mul1, div0, div1, mod0, mod1;
    int comp0, comp1, neg0, neg1, not0, not1;
    add0 = op0 + op1;
    add1 = op0 + op1;
    sub0 = op0 - op1;
    sub1 = op0 - op1;
    mul0 = op0 * op1;
    mul1 = op0 * op1;
    div0 = op0 / op1;
    div1 = op0 / op1;
    mod0 = op0 % op1;
    mod1 = op0 % op1;
    comp0 = ~op0;
    comp1 = ~op0;
    neg0 = -op0;
    neg1 = -op0;
    not0 = !op0;
    not1 = !op0;
    printf("%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n", add0, add1, sub0, sub1, mul0, mul1, div0, div1, mod0, mod1);
    printf("%d;%d;%d;%d;%d;%d\n", comp0, comp1, neg0, neg1, not0, not1);
}

void test_if(int x, int y, int w) {
    int u, v;
    u = x*y;

    if (w == 0) {
        w = 1;
    } else {
        w = 0; 
    }

    v = x*y;
    printf("test_if: (u: %d, v: %d, w: %d)\n", u, v, w);
}

void test_for(int x, int y, int n) {
    int u, v, i, j;
    u = x / y;

    for (i = 0; i < n; i = i + 1) {
        j = i + x + y;
    }

    v = x / y;
    printf("test_for: (u: %d, v: %d, j: %d)\n", u, v, j);
}

void test_overwrite(int x, int y, int n) {
    int u, v, i;
    u = x / y;

    for (i = 0; i < n; i = i + 1) {
        x = x + y;
    }

    v = x / y;
    printf("test_for: (u: %d, v: %d)\n", u, v);
}

int main() {
    test_op(2, 3);
    test_if(2, 3, 1);
    test_for(2, 3, 5);
    test_overwrite(2, 3, 5);
    return 0;
}