#!/bin/bash

FILE="./examples/testing.txt"

cd ..

"./stastpa8" < "tests/0000_in.txt"

if test -f "$FILE";
then
    echo "0000_in.txt is correct"
else
    echo "0000_in.txt is wrong"
fi
