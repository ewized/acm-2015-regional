# ACM 2015 Regional

This contains problems from the regional contest.
The problems were created after the regional contest.

# Verifying the program
There is a python script called `verify.py`.
This script will compile and check the output with the samples.

Each program must be named with the schema `p##.cpp`.

> ./verify.py p##.cpp

The script takes one position argument of the **cpp** file.
It will pipe the sample input into the program and redirect the output to a tmp file.
It then checks the tmp output and sample output.

