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

    int x;
    x = 1;

    if (x) {
        y = -12 * x;
    }

    if (x) {
        if (y) {
            y = 34 * y;
        }
    }

    x = (y = 3) * 2;
    
    if (y = 0) {
        y = 23;
    }

    for (;y;) {
        y = 21;
    }

    y = 12;

    for (;y;) {
        y = 0;
    }

    return 0;
}