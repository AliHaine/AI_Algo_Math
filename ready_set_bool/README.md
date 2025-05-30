# Ready set bool

_Computer-related mathematics with Boolean Algebra and Sets Theory_

## ex00 and ex01 - Bitwise

For this two exercices, we have to implement the operator + (addition) and * (multiplication) (with positif numbers) using bitwise operator, in this case, ^ and <<.

### Addition

Doing binary addition is very easy and similar to decimal addition. It basically works the same way
0 and 1 = 1
1 and 0 = 1
0 and 0 = 0
1 + 1 = 0 (with a carry of 1) → which becomes 10 in binary

This is why we use:
^ (XOR) to compute the sum without carry
& << 1 to compute the carry bits
We repeat until there are no more carry bits left.

Let's say that we have 5 (0101) and 10 (1010). The expected result is 15 (1111).

5 = 0101
10 = 1010
-> First line we have 0 (for 5) and 1 (for 10) = 1 
-> Second line 1 and 0 = 1
-> Thrid line 0 and 1 = 1
-> Last line 1 and 0 = 1

![ex00 image](public/ex00.png)

### Multiplication

Binary multiplicatoin works just like decimal multiplication:

- Go through each digit (bit) of the multiplier (b)
- If the bit is 1, you add the current value of a (shited to the left)
- You shift a left (a <<= 1) every time, like moving to the next column in decimal
- You shift b right (b >>= 1) to check the next bit

![ex01 image](public/ex01.png)

## ex02 - Graycode

Gray code is a type of binary encoding with a simple but powerful rule: only one bit changesat a time when incrementing by one unit.
This can be very useful in many contexts, as it helps avoid  'transitional states' that occur in standard cinary encoding.

For example, in standard binary encoding, when incrementing from 1 to 2:
0001 (1)
0000 (?) -> Set the 1 to 0 (transition)
0010 (2) -> End by setting a 1 to create the number 2

This intermediate state (0000) doesn't represent either value and may result in undefined behavior, which can be problematic or even damaging in certain context and critical apps.

## ex03 - Boolean evaluation

_Write a function that takes as input a string that contains a propositional formula in reverse polish notation, evaluates this formula, then returns the result_

| Symbol | Mathematical Equivalent | Description               | Bitwise Equivalent |
|--------|--------------------------|--------------------------|---------------------|
| 0      | ⊥                        | false                    | 0                  |
| 1      | ⊤                        | true                     | 1                  |
| !      | ¬                        | Negation                 | ~                  |
| &      | ∧                        | Conjunction              | & (AND)            |
| \|      | ∨                        | Disjunction             | \| (OR)            |
| ^      | ⊕                        | Exclusive disjunction   | ^   (XOR)           |
| >      | ⇒                        | Material condition       | !a \| b (no native)|
| =      | ⇔                        | Logical equivalence     | a == b             |

This exercice is not as difficult as it may seem at first. If you're unfamiliar with Reverse Polish Notation (RPN) you can [read more about it here](https://en.wikipedia.org/wiki/Reverse_Polish_notation)

So the goal is to evaluate bitwise expressions written in RPN using specific symbol for operations. 
Example:
11| Result to 1, which is the equivalent of 1 | 1 (Disjunction, bitwise OR).
More complexe example: 
10|111=&=
10| → 1 | 0 = 1
11= → 1 == 1 = 1
11& → 1 & 1 = 1
11= → 1 == 1 = 1
Final result 1

## ex04 - Truth table

_Write a function that takes as input a string that contains a propositional formula in reverse polish notation, and writes its truth table on the standard output_

A truth table is a diragram showing how the truth or falsity of a proposition varies with that of its components (in our case, variables). This concept is fundamental in many domains, especially in hardwar logic design and artificial intelligence.

### Example 
_formula AB&C| equivalent to (A ∧ B) ∨ C_

| A | B | C | = |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

The number of rows in the truth table is calculated as $2^N$. 
Where N is the number of distinct variables (in this case 3), so we have $2^3$ = 8 rows. Every possible combination of input values is precomputed.

### Algorithm to generate a Truth table

To build a truth table:
- Count the number of distinct variables (3)
- Compute the number of rows ($2^3$ = 8)
- Start with the row | 0 | 0 | 0 |
- For each step (from 0 to $2^n$-1), convert the step number to binary and use it to fill the table
- 
Or conceptually:
- Try to set a 1 at the rightmost possible position.
- Reset all bits to the right of that position to 0.

This generates all binary combinations in order, which are used to fill the truth table.

## ex05 - Negation Normal Form
_Write a function that takes as input a string that contains a propositional
formula in RPN, and returns an equivalent formula in Negation Normal Form (NNF), meaning that every negation operators must be located right
after a variable._

A formula is in Negation Normal Form (NNF) when:
- The only logical operators are ∧ (AND), ∨ (OR), ¬ (NOT).
- NOT (¬) is applied only to variables (like ¬A) not to compound expressions.

To convert an expression into NNF, we must first rewrite expressions using only the allowed operators. That mean removing: ⊕ (XOR), ⇒ (Implication), ⇔ (Equivalence).

| Expression | NNF equivalent      |
|------------|---------------------|
| A ⇒ B          | ¬A ∨ B              | 
| A ⇔ B          | (A ∧ B) ∨ (¬A ∧ ¬B) |
| A ⊕ B          | (A ∨ B) ∧ ¬(A ∧ B)  |

Then we have to push negations inward using [De Morgan's laws](https://en.wikipedia.org/wiki/De_Morgan%27s_laws) and eliminate double negations

| Expression | De Morgan's laws equivalent |
|-------|---------------------------|
| ¬(A ∧ B)    | ¬A ∨ ¬B    | 
| ¬(A ∨ B)  | ¬A ∧ ¬B       |
| ¬¬A   | A         |

## ex06 - Conjunctive Normal Form

_Write a function that takes as input a string that contains a propositional
formula in RPN, and returns an equivalent formula in Conjunctive
Normal Form (CNF). This means that in the output, every negation must be located
right after a variable and every conjunction must be located at the end of the formula._

A formula is in Conjunctive Normal Form (CNF) when:
- The only logical operators are ∧ (AND), ∨ (OR), ¬ (NOT).
- NOT (¬) is applied only to variables (like ¬A) not to compound expressions.
- It is a conjunction ∧ (AND) of one or more clauses.
- Each clause is a disjunction ∨ (OR) of literals.

As we can see, CNF is quite similar to NNF, expect that in CNF, **every** ∧ (AND) must be applied between clauses, and every ∨ (OR) must be used within a clause.
To convert a standard expression into CNF, the most common and straightforward way is to first convert it to NNF, and then convert from NNF to CNF.

The CNF conversion relies on the following distributive law:

(A ∧ B) ∨ C ≡ (A ∨ C) ∧ (B ∨ C)

| NNF expression | CNF equivalent                        |
|------------|---------------------------------------|
| (A ∨ B) ∧ C  | (A ∨ B) ∧ C                           |
| (A ∧ B) ∨ C  | (A ∨ C) ∧ (B ∨ C)                     |
| (A ∨ B) ∨ (C ∧ D)  | (A ∨ B ∨ C) ∧ (A ∨ B ∨ D)             |
| (A ∧ B) ∨ (C ∧ D)  | (A ∨ C) ∧ (A ∨ D) ∧ (B v C) ∧ (B ∨ D) |

## ex07 - SAT

_Write a function that takes as input a string that contains a propositional
formula in reverse polish notation and tells whether it is satisfiable_

SAT-solver is an algorithm which aim to solve the boolean satisfiability problem.

Given a Boolean expression, a SAT-solver explores all possible truth assignments to the variables and reports whether at least one assignment makes the expression evaluate to true. 
If such an assignment exists, the formula is satisfiable, otherwise, it is unsatisfiable.

Expression which will never be true, so unsatisfiable: A!A=

Expression which have true case; so satisfiable: AA|

## ex08 - PowerSet

_Write a function that takes as input a set of integers, and returns its powerset_

To do this exercice; we have to understand several thinks.

### Set

A **set** is an unordered collection of unique elements
quick example;
set = [1,2,3] This is a set of integer with the int 1 2 and 3
set = [1,1,2] By definition, this is not and can't be a set, because 1 appears twice

### SubSet

A **set B** is a **subset** of A, when every element of B is also in A.

### Example

A = [1,2,3]
B = [2,3]

Here, B is a subset of A

### Type of Subsets

**Possible equality**  
If `B ⊆ A` **and** `A ⊆ B`, then `A` and `B` have exactly the same elements, so `A = B`.

**Proper subset**  
`B ⊂ A` means `B ⊆ A` but `B ≠ A`; that is, `A` has at least one element not in `B`.

**Empty set**  
The empty set `∅` is a subset of every set (there is no element that can violate the definition).

**Power set**  
The collection of **all** subsets of a set `A` is called the *power set* of `A`, written `P(A)`.

### PowerSet

A powerset, wrote 𝒫(E) is a set of all subset for a given set.
The powerset must contain a empty set, can be written ∅, and the entire given set.

We can calculat the unmber of subset with the formula $2^N$ where n is the number of variables in the initiale set.

### Example 

For E = {A,B,C}, 3 elements, $2^3$ = 8 subset.

𝒫(E) = {
∅,
{A}, {B}, {C},
{A,B}, {A,C}, {B,C},
{A,B,C}
}

## ex09 - Set Evaluation

| Symbol | Mathematical Equivalent | Set‑theory equivalent   | Description                               |
|--------|---------------|-------------------------|-------------------------------------------|
| `!`    | ¬ | \ (Complement)          | pick everything *not* in A                |
| `&`    | ∧ | ∩ (Intersect)           | Keep only things common to both           |
| `\|`   | ∨ | ∪ (Union)               | Unification of both                       |
| `ˆ`    | ⊕ | Δ (sym. Diff.)          | Everything, except the things they share  |
| `>`    | ⇒ | (𝐔\\A)∪B (Implication) | same as “¬A∨B”                            |
| `=`    | ⇔ | = (Equivalence)         | Both have exactly the same values         |

We might think that we can simply reuse the evaluator function that we wrote for Boolean RPN expressions. However, even though the symbols may look the same,
their interactions and purposes are different.

In boolean operation, the operators evaluate true/false, whereas in Set-Theroy, the operators
transform sets.
