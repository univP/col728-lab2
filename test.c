// Parsing:
//  expression
//      identifiers, constants, bracketed expressions 
// declaration
//      declaration specifiers, init declarator list
// direct declarator
//      identifier, parameter list
int y(int p, float q) {
    p;
}

int main(int x) {
    int i,j;
    i = 12;
    j = 4;
    i < j;
    j <= i;
    j == i;
    y(i,j);
}