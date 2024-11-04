#include "polynomial.h"

int main() {
    Term *poly1 = NULL;
    Term *poly2 = NULL;

    appendTerm(&poly1, 5, 2);
    appendTerm(&poly1, 3, 3);
    appendTerm(&poly1, 2, 0);
    appendTerm(&poly2, 4, 1);
    appendTerm(&poly2, 3, 3);
    appendTerm(&poly2, 7, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    Term *sum = addPoly(poly1, poly2);
    printf("Sum: ");
    printPoly(sum);

    Term *difference = subPoly(poly1, poly2);
    printf("Diff: ");
    printPoly(difference);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(sum);

    return 0;
}
