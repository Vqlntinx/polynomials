#include "polynomial.h"

Term* createTerm(int coef, int exp) {
    Term* newTerm = (Term *)malloc(sizeof(Term));
    newTerm-> coef = coef;
    newTerm-> exp = exp;
    newTerm-> next = NULL;
    return newTerm;
}

void appendTerm(Term **head, int coef, int exp) {
    Term *newTerm = createTerm(coef, exp);
    if (*head == NULL || (*head)-> exp < exp) {
        newTerm-> next = *head;
        *head = newTerm;
    } else {
        Term *temp = *head;
        while (temp->next!=NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next !=NULL && temp->next->exp == exp) {
            temp->next->coef = temp->next->coef + coef;
            free(newTerm);
        } else {
            newTerm->next = temp->next;
            temp->next = newTerm;
        }
    }
}

void printPoly(Term *head) {
    Term *temp = head;
    int firstTerm = 1;

    while (temp != NULL) {
        if (temp->coef != 0) {
            if (firstTerm) {
                printf("%.2fx^%d", temp->coef, temp->exp);
                firstTerm = 0;
            } else {
                if (temp->coef > 0)
                    printf(" + %.2fx^%d", temp->coef, temp->exp);
                else
                    printf(" - %.2fx^%d", -temp->coef, temp->exp);
            }
        }
        temp = temp->next;
    }
    printf("\n");
}

void freePoly(Term *head) {
    Term *temp;
    while (head!=NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

static Term *__addPoly(Term *poly1, Term *poly2, int sign) {
    Term *result = NULL;
    Term *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            addTerm(&result, p1->coef, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            addTerm(&result, sign * p2->coef, p2->exp);
            p2 = p2->next;
        } else {
            addTerm(&result, p1->coef + sign * p2->coef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        addTerm(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        addTerm(&result, p2->coef, sign * p2->exp);
        p2 = p2->next;
    }

    return result;
}

Term *addPoly(Term *poly1, Term *poly2) {
    return __addPoly(poly1, poly2, 1);
}

Term *subPoly(Term *poly1, Term *poly2) {
    return __addPoly(poly1, poly2, -1);
}
