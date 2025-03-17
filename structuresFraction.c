#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int whole;
    int num;
    int den;
} Fraction;

Fraction createFraction(int num, int den);
void displayFraction(Fraction f);
Fraction addFraction(Fraction f1, Fraction f2);
Fraction subtractFraction(Fraction f1, Fraction f2);
Fraction multiplyFraction(Fraction f1, Fraction f2);
Fraction divideFraction(Fraction f1, Fraction f2);

int main(){
    Fraction f1 = createFraction(1, 2);
    Fraction f2 = createFraction(1, 2);
    displayFraction(f1);
    displayFraction(f2);
    displayFraction(addFraction(f1, f2));
    displayFraction(subtractFraction(f1, f2));
    displayFraction(multiplyFraction(f1, f2));
    displayFraction(divideFraction(f1, f2));
    return 0;
}

void displayFraction(Fraction f){
    if(f.whole == 0){
        printf("%d/%d\n", f.num, f.den);
    }else if(f.num == 1){
        printf("%d\n", f.whole);
    }else{
        printf("%d %d/%d\n", f.whole, f.num, f.den);
    }
}


Fraction createFraction(int num, int den){
    Fraction fraction;
    int newNum, newDen;
    if(num > den){
        fraction.whole = num/den;
        newNum = num % den;
        fraction.num = newNum;
        fraction.den = den;
        return fraction;
    }else if(num == den){
        fraction.whole = 1;
        fraction.num = 0;
        fraction.den = 0;
        return fraction;
    }else{
        fraction.whole = 0;
        fraction.num = simplifyFraction(fraction).num;
        fraction.den = simplifyFraction(fraction).den;
        return fraction;
    }
}
Fraction addFraction(Fraction f1, Fraction f2){
    int numTot, sum;
    Fraction total;
    if(f1.den == f2.den){
        numTot = f1.num + f2.num;
        total = createFraction(numTot, f1.den);

    }else{
        int newDen, newNum; 
        newDen = f1.den * f2.den;
        newNum = (f1.num * f2.den)+(f2.num * f1.den);
        total = createFraction(newNum, newDen);
    }
    return total;
}
Fraction subtractFraction(Fraction f1, Fraction f2){
    int numTot, sum;
    Fraction total;
    if(f1.den == f2.den){
        numTot = f1.num - f2.num;
        total = createFraction(numTot, f1.den);

    }else{
        int newDen, newNum; 
        newDen = f1.den * f2.den;
        newNum = (f1.num * f2.den)-(f2.num * f1.den);
        total = createFraction(newNum, newDen);
    }
    return total;
}
Fraction multiplyFraction(Fraction f1, Fraction f2){
    int numTot, sum;
    Fraction total;
    numTot = f1.num * f2.num;
    sum = f1.den * f2.den;
    total = createFraction(numTot, sum);
    return total;
}
Fraction divideFraction(Fraction f1, Fraction f2){
    int numTot, sum;
    Fraction total;
    numTot = f1.num * f2.den;
    sum = f1.den * f2.num;
    total = createFraction(numTot, sum);
    return total;
}

Fraction simplifyFraction(Fraction f){
    int num = f.num;
    int den = f.den;
    int gcd;
    while(num != den){
        if(num > den){
            num = num - den;
        }else{
            den = den - num;
        }
    }
    gcd = num;
    f.num = f.num / gcd;
    f.den = f.den / gcd;
    return f;
}

