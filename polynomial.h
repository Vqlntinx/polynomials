#ifndef POLY_POLYNOMIAL_H
#define POLY_POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Term {
    float coef;
    int exp;
    struct Term* next;
} Term;

Term *createTerm(int coef, int exp);
void appendTerm(Term **head, int coef, int exp);
void printPoly(Term *head);
void freePoly(Term *head);
Term *addPoly(Term *poly1, Term *poly2);
Term *subPoly(Term *poly1, Term *poly2);

#endif //POLY_POLYNOMIAL_H
