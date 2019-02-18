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
   
   **Example of linear recurrence** f(i) = f(i-1)*f(i-1)

   **We can solve linear recurrence in simple 4 steps**
   1. Determine K, Number of terms on which f(i) depends <br> **For Exapmle**<br> f(i) = f(i-1) + 3f(i-6) has K = 6<br>
   For better understanding, It can be rewritten as f(i) = f(i-1) + 0f(i-2) + 0f(i-3) + 0f(i-4) + 0f(i-5) + 3f(i-6)

   2. Precompute f(i) upto K and store it in 1-D array as F<sub>0</sub>

   3. Determine transformation matrix T, Such that<br>
       **TF<sub>i</sub> = F<sub>i+1</sub>**
       <br>Suppose,<br>
       &nbsp;&nbsp;&nbsp;&nbsp; f(i) = C<sub>1</sub>f(i-1) + C<sub>2</sub>f(i-2) + C<sub>3</sub>f(i-3) + ... + C<sub>k</sub>f(i-k) ...............(1)  <br>
       Here, C<sub>1</sub>, C<sub>2</sub>, ..., C<sub>k</sub>, are coefficient <br>
       Substitute i = K+1 in equation 1, <br> 
       We get, <br>
       &nbsp;&nbsp;&nbsp;&nbsp; f(k+1) =  C<sub>1</sub>f(k) + C<sub>2</sub>f(k-1) + C<sub>3</sub>f(k-2) + ... + C<sub>k</sub>f(1)
       <br> Hence T is,<br>
        &nbsp;&nbsp;&nbsp;&nbsp; ![alt text](F:\t.png)