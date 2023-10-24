#!/bin/bash

FILE="./examples/testing.txt"

if ! test -f "$FILE";
then
        ./testCreate.sh
fi

cd ..

"./stastpa8" < "tests/0001_in.txt"

if test -f "$FILE";
then
    echo "0000_in.txt is wrong"
else
    echo "0000_in.txt is correct"
fi
