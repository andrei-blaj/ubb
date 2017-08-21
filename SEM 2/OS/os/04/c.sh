#!/bin/bash 

C=asdf.c
E=asdf

cat > $C <<EOF
#include <stdio.h>

int main() {
    printf("yes, it is really gcc");
    return 0;
}
EOF

for G in $*; do
    if [ ! -f $G ] || [ ! -x $G ]; then
        continue
    fi

    $G -Wall -o $E $C > /dev/null 2>&1 || continue
    if [ ! -f $E ] || [ ! -x $E ]; then
        continue
    fi
    if [ ! "`./$E`" = "yes, it is really gcc" ]; then
        continue
    fi
    ./$E > /dev/null || continue
    echo "$G is GCC"
done

rm $C $E 2> /dev/null

