Tests
=====

.. automodule:: tests.test

Testing conversions
-------------------

A base 10 number is generated at random.
Afterwards, it is converted successively a number of times, into random bases.
In the end, the number is converted back into base 10.

If the initial value is equal to the final value, then there is an extremely high chance that all conversions were performed correctly.

Testing expressions
-------------------

There are some hard-coded expressions that are tested.
In addition, the application runs the tests from http://infoarena.ro/problema/evaluare (similar problem, large input files, only base 10).

Testing operations
------------------

Two random base 10 numbers are generated. Both of them are converted to the same arbitrary base, and all possible operators are applied on them. The results are compared to the correct values, which are obtained by applying the corresponding built-in Python operators, and converted using the **numpy** collection.

.. autoclass:: tests.test.Test
   :members:
   :private-members:
   :special-members:

