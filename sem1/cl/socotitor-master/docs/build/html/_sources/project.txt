Project Summary
===============

Requirements
------------

In order to run Socotitor, two dependencies must be installed:
    * Python (version 3.4 or newer)
    * Numpy

Author
------

Socotitor was built by Sergiu Puscas, group 917.

Contact at srg.pscs@gmail.com or psie1996@cs.ubbcluj.ro.

Operations
----------

The implemented operations are:
    * addition
    * subtraction
    * multiplication
    * integer division (quotient + remainder)
    * exponentiation

For each operation, both operands must be represented in the same base (2, 3, ..., 10, 16). If not, than one of them must first be converted to the other base.

Conversions
-----------

Socotitor implements three methods of converting bases:
    * substitution method
    * successive divisions
    * rapid conversions

The best of the three methods is chosen automatically by the application, depending on the bases of the conversion.

Expressions
-----------

Moreover, some more complex expressions can be evaluated. These allow using operands written in different bases. In addition, parantheses are allowed for specifying the priority of an operation.
