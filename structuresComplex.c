#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float real;
    float imag;
}Complex;

Complex createComplex(float r, float i);
void displayComplex(Complex c);
Complex sumComplex(Complex c1, Complex c2);
Complex differenceComplex(Complex c1, Complex c2);
Complex productComplex(Complex c1, Complex c2);
Complex quotientComplex(Complex c1, Complex c2);

int main(){
    float r, i;
    printf("Enter complex number: "); scanf("%f %f", &r, &i);
    Complex c1 = createComplex(r, i);displayComplex(c1);

    printf("Enter complex nubmer: "); scanf("%f %f", &r, &i);
    Complex c2 = createComplex(r, i); displayComplex(c2);
    printf("==================\n");
    printf("Sum = "); displayComplex(sumComplex(c1, c2));
    printf("Difference = "); displayComplex(differenceComplex(c1, c2));
    printf("Product = "); displayComplex(productComplex(c1, c2));
    printf("Quotient = "); displayComplex(quotientComplex(c1, c2));
    return 0;
}

void displayComplex(Complex c){
    if(((c.real < 1)&&(c.real >0))||((c.imag<1)&&(c.imag>0))){
        printf("%.2f + %.2fi \n", c.real, c.imag);
    }else{
     printf("%.0f + %.0fi \n", c.real, c.imag);
    }
}

Complex createComplex(float r, float i){
    Complex complex;
    complex.real = r;
    complex.imag = i;
    return complex;
}

Complex sumComplex(Complex c1, Complex c2){
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

Complex differenceComplex(Complex c1, Complex c2){
    Complex diff;
    diff.real = c1.real - c2.real;
    diff.imag = c1.imag - c2.imag;
    return diff;
}

Complex productComplex(Complex c1, Complex c2){
    Complex prod;
    prod.real = c1.real * c2.real;
    prod.imag = c1.imag * c2.imag;
    return prod;
}

Complex quotientComplex(Complex c1, Complex c2){
    Complex quo;
    quo.real = c1.real/c2.real;
    quo.imag = c1.imag/c2.imag;
    return quo;
}