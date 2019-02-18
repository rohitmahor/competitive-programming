# 1. Birthday Paradox (Probability)
## Problem Statement:
    What is the minimum number of people that should be present in a room so that there's 50% chance of two people having same birthday?

## Solution Approach
    1. probability of two people having same birthday is equal to 1 - probability of all people have different birthday.

    2. find how many people require in the room to have 50% chance all people have different birthdays.

    3. probability of all n people having different birtdays

       365*(365-1)*(365-2)....(365-(n-1))/(365)^(n) = 0.5
       find n and n will be the answer.


## Time to try
    What is the minimum number of people that should be present in a room so that there's 99.9% chance of two people having same birthday ?


# 2. Solving Linear Recurrences
    It is possible to solve with dynamic programming if n is small, problem arise when n is larger than 10^8.

    **We can solve linear recurrence in simple 4 steps**

    
