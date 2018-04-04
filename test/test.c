int printf(char* format, ...);

int main() {
    int y;
    y = !54;
    y = ~10;
    y = -4;
    y = (2*4)%5;
    y = y*4;

    if (0) {
        y = 12 - 5;
    } else {
        y = 5 - 12;
    }

    if (1) {
        y = 12 - 5;
    } else {
        y = 5 - 12;
    }

    for (; 0;) {
        y = 12*5*9;
    }

    return 0;
}