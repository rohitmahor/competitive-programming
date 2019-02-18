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
        &nbsp;&nbsp;&nbsp;&nbsp; **T =** ![alt text](https://github.com/rohitmahor/competitive-programming/blob/master/images/t.png)

   4. Determine F(n) <br>
      &nbsp;&nbsp;&nbsp;&nbsp; F<sub>2</sub> = TF<sub>1</sub><br>
      &nbsp;&nbsp;&nbsp;&nbsp; F<sub>3</sub> = TF<sub>2</sub><br>
      &nbsp;&nbsp;&nbsp;&nbsp; F<sub>n</sub> = TF<sub>n-1</sub><br>

      **Note:** For computing T<sup>n-1</sup> use squaring method that works in O(logn)

      **Time to try:**<br>
       * [SEQ](https://spoj.com/problems/SEQ/) <br>
       * [SPP](https://spoj.com/problems/SPP/) <br>
       * Finding out nth fibonacci number for very large 'n' ( <= 10<sup>18</sup>)

# 3. Based on Pigeonhole Principle

## Principle
If number of pigeons is greater than holes then there wil be at least one hole which contain at least two pigeons.

## Time to try
* [Divisible Subset](https://www.codechef.com/problems/DIVSUBS)
* [The Gray Code Similar](https://www.codechef.com/problems/GRAYSC)
* [Holiday Accommodation](https://spoj.com/problems/HOLI/) 

# 4. The Inclusion-Exclusion Principle

Every group of objects A can be associated with a quantity - denoted |A| - called the number of elements in A.<br>
If X = A∪B and A∩B = Ø, then |X| = |A| + |B|.<br>
If A and B are not disjoint, we get the simplest form of the Inclusion-Exclusion Principle:<br>
1. |A∪B| = |A| + |B| - |A∩B|.
2. |A∪B∪C| = |A| + |B| + |C| - |A∩B| - |B∩C| - |A∩C| + |A∩B∩C|

**Example**<br>
&nbsp;&nbsp;&nbsp;&nbsp; How many number are there less than 10<sup>9</sup> such that composite but not divisble by 2, 3 or 5.<br>

&nbsp;&nbsp;&nbsp;&nbsp; **Solution Approach**
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |A| = numbers divisible by 2
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |B| = numbers divisible by 3
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; |C| = numbers divisible by 5
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  |A∩B| = numbers divisible by 2 & 3
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  |B∩C| = numbers divisible by 3 & 5
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  |A∩C| = numbers divisible by 2 & 5

<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; **Required answer** = (10<sup>9</sup>-1) - |A∪B∪C|

**Note** :- We can also compute by using Bitmasks:

**Pseudocode using Bitmasks**
```
arr = {2,3,5};
|AUBUC| = 0;
for mask = 1 to 2^3:
       temp = 1;
       numBit = CountBits(mask);
       currMask = mask;
       pos = 0;
       while(currMask > 0):
              if(currMask&1 == 1): //if last bit of currMask is set
                     temp = temp*a[pos];
              currMask = currMask >> 1;
              pos++;

       if(numBit%2 == 1): //if numBit is odd
              |AUBUC| += (10^9-1)/temp;
       else
              |AUBUC| -= (10^9-1)/temp;

return (10^9-1) - |AUBUC|;
```

       