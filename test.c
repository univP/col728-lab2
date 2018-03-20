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

int main(int x) 
{
    int i;
    float j;
    i=2;
    j=4.5;
    if(i==j){
        i=95;
        return i;
    }
    y(i,j);
    return i*i;
}