# Polynomial

Allows you to create polynomials.  Currently only sin and cos functions are added, but you can easily add any function you want by editing Term.h & Term.cpp, just make sure that the index of the new function matches the index of the `signs_string` for the printing function to work correctly.

If you wish to add a constant instead of an expression you can use `Term::expression::num` or you can raise an create an exponent raised to the first power.

Each Polynomial object is made up of Term objects and signs.

Usage:
```c++
Term t1(1, Term::expression::x, 2); // x^2
Term t2(10, Term::expression::num, 12); // 10

Expr poly1(t1);
p.add(Expr::signs::PLUS, t2); // x^2 + 10
p.get_at(5); // (5)^2 + 10 = 35
```

## Todo
* Add support for exponential functions
* Add support for function composition e.g. sin(ln(x)), f(g(x))
* Add support for parenthesis