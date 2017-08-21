The Number Class
================

.. automodule:: models.number

The format for representing a number in some base is:
    **<value> + '_' + <base>**

Examples: **5_10**, **-1010110_2**, **123F_16**.
If not base is specified when defining a number, then base **10** is used by default.


.. autoclass:: models.number.Number
   :members:
   :private-members:
   :special-members:
