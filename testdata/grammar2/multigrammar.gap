
signature Bill(alphabet, answer) {
  answer f(int);
  answer add(answer, alphabet, answer);
  answer mult(answer, alphabet, answer);
  choice [answer] h([answer]);
}


algebra buyer implements Bill(alphabet = char, answer = int) {

  int f(int i) { return i; }

  int add(int i, char c, int j)
  {
    return i + j;
  }

  int mult(int i, char c, int j)
  {
    return i * j;
  }

  choice [int] h([int] i)
  {
    return list(minimum(i));
  }
}

algebra seller extends buyer {
  choice [int] h([int] l)
  {
    return list(maximum(l));
  }
}


grammar bill uses Bill (axiom=formula) {

  // Uncomment for an explicit table configuration
  // instead of deriving a good one via 'gapc -t'
  // tabulated { formula, number }

  formula = number |
            add(formula, plus, formula) |
            mult(formula, times, formula) # h ;

  number = f(INT);

  plus = CHAR('+') ;
  times = CHAR('*') ;

}

grammar bill2 uses Bill (axiom=formula) {

  // Uncomment for an explicit table configuration
  // instead of deriving a good one via 'gapc -t'
  // tabulated { formula, number }

  formula = number |
            add(formula, plus, formula) |
            mult(formula, times, formula) # h ;

  number = f(INT);

  plus = CHAR('+') ;
  times = CHAR('*') ;

}

instance buyer = bill ( buyer ) ;
instance seller = bill2 ( seller ) ;


