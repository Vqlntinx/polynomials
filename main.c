#include "polynomial.h"

int main() {
    Term *poly1 = NULL;
    Term *poly2 = NULL;

    addTerm(&poly1, 5, 2);
    addTerm(&poly1, 3, 3);
    addTerm(&poly1, 2, 0);
    addTerm(&poly2, 4, 1);
    addTerm(&poly2, 3, 3);
    addTerm(&poly2, 7, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    Term *sum = addPoly(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);

    return 0;
}