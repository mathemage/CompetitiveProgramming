# Problem Statement
A string is valid only if it has three consecutive *b*'s in a string  and can only have character *a* and *b* in it.

For an input *t* which is equal to length of the string, we need to print the output *count*.
The integer *count* is the number of combinations of strings which it can have.

You can also print the result using modulo of 100007 because output can be abnormally high.

## Example
* for *t=3* there is only one valid string *bbb*
* for *t=4* there can be 3 strings: *bbba*, *abbb*, *bbbb*

Actually, what Prakhar did was to first mathematically calculate the total combinations for a particular integer length:
* for n=3 it is 1
* for n=4 it is 3
* for n=5 it is 8
* for n=6 it is 20
* for n=7 it is 48
* for n=8 it is 112
* for n=9 it is 256
* for n=10 it is 576

and then calculated general term *n* for any string of length *n*
the general term came out to be: [(result of previous n)*2 + (2**(n-4))]  for  t<3 it was zero and for t=3 i hard coded it to be 1
Karel

## Constraints
*1 < n < 10^7*
