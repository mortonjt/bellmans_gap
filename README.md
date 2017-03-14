# bellmans_gap
Fork of the Bellmans Gap prgoramming language

Specifically, this repository contains Gap-C used to compile programs written in Gap-L

Checkout BiBiServ for more details
https://bibiserv.cebitec.uni-bielefeld.de/gapc

# Installation

To install the compiler, run
```
./configure
make
make install  # might require sudo access
```

To install helper functions run
```
make test-mod
```

# Tutorial
To make sure things are working, take a look at `testdata/aliglob2.gap`.

Try running the following code

```
gapc aliglob2.gap
make -f out.mf
./out "airline darling"
```
Calling the resulting executable should give all possible 48k possible alignments between the words `airline` and `darling`.

To compile another algebra within `aliglob2.gap` such as `count`, run the following command

`gapc -p count aliglob2.gap`

This will only output the total number of alignments.
