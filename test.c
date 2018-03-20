// Parsing:
//  expression
//      identifiers, constants, bracketed expressions 
// declaration
//      declaration specifiers, init declarator list
// direct declarator
//      identifier, parameter list
int y(int p) {
    for (int i; i < p; i = i + 1) {
        p = p*p;
        i = i + 1;
    }

    return p;
}