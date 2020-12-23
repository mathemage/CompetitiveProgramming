# SRM-796-Div-2-250
## Approach
math (+- graph theory), +- simulation

0. count `n_unhappy` = # of *unhappy* guests
1. return this $n_unhappy - 1$
  - each cracker reduces $n_unhappy$ by 1, when scheduled without redundancies
  - can be achieved by "zipping" over $n_unhappy - 1$ guests
    - by always matching the loser of the last match with the next guest
2. in case of at most 1 unhappy guest rectify:
  - `return max(0, n_unhappy - 1)`

## Lessons learnt
- can be submitted without crisp, strict idea of proof
- challenge achieved by a sample testcase
  -> **always open up the problem statement** to have sample testcases ready


# SRM-796-Div-2-500
## Approach
- count combinations of preceding `set_width`
- TODO

## Lessons learnt
- combination numbers can be precomputed
  - via DP
  - i.e. Pascal's triangle
