#include "Polynomial.h"

void demo1() {
    Term term1(1, Term::expression::x, 1);
    Term term2(2, Term::expression::cos, 2);
    Term term3(3, Term::expression::x, 3);
    Term term4(4, Term::expression::sin, 4);
    Poly poly1(term1);

    poly1.add(Poly::signs::PLUS, term3);
    poly1.add(Poly::signs::DIVIDE, term2);
    poly1.add(Poly::signs::MINUS, term4);
    poly1.add(Poly::signs::PLUS, term4);
    poly1.add(Poly::signs::MULTIPLY, term2);

    fmt::print("{}\n", poly1.to_string());
    fmt::print("{}\n", poly1.get_at(4));
}

void demo2() {
    Term t1(1, Term::expression::x, 2); // x^2
    Term t2(10, Term::expression::num, 12); // 10
    Term t3(2, Term::expression::cos, 2);

    Poly p(t1);
    p.add(Poly::signs::PLUS, t2);
    p.add(Poly::signs::MINUS, t3);

    fmt::print("f(x) = {}\n", p.to_string());
    fmt::print("f(5) = {}\n", p.get_at(5));
}

int main() {
//    demo1();
    demo2();
}