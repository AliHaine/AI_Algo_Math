# Set-Builder Notation in Mathematics

## Definition

Set-builder notation is a concise way to describe sets by **specifying properties that its elements must satisfy**, rather than listing every element individually.  

This is a fundamental concept in mathematics, especially for **understanding functions, relations, logic, and advanced topics like combinatorics and set theory**, because it allows us to define sets rigorously and concisely without listing every element.

## General

$\{ \text{expression} \mid \text{conditions} \}$

- **Expression (before the `|`)**: the "output" or "return value" of each element in the set.  
- **Conditions (after the `|`)**: constraints or rules that the variables must satisfy.  
- Variables appearing in the conditions act as "inputs" that generate the set elements.

## Examples

### Simple Even Numbers

$\{ x \in \mathbb{N} \mid \exists y \in \mathbb{N} : x = 2y \}$

Take all natural numbers \(x\) such that there exists a natural number \(y\) with \(x = 2y\) (i.e., all even numbers).

Result: {2, 4, 6, 8, ...}

### Squares of Natural Numbers Below 6

$\{ x^2 \mid x \in \mathbb{N}, x < 6 \}$

Step 1: Allowed \(x\) values: \(1,2,3,4,5\)

Step 2: Return \(x^2\) → \(1,4,9,16,25\)

**Result**: {1, 4, 9, 16, 25}

### Two Variables (Cartesian Product)

$\{ (x,y) \mid x \in \mathbb{N}, y \in \mathbb{N}, x < 4, y < 3 \}$

Step 1: Allowed values: (x = 1,2,3), (y = 1,2)

Step 2: Form all ordered pairs (x,y). We pair every allowed x with every allowed y

**Result**: {(1,1), (1,2), (2,1), (2,2), (3,1), (3,2)}

> Notice: Each element is an **ordered pair**, not a set.

### Multiple Conditions

$\{ x \in \mathbb{N} \mid \exists y \in \mathbb{N} : x = 2y, x > 10, x < 20 \}$

Step 1: Take all even natural numbers greater than 10 and less than 20.  

**Result**: {12, 14, 16, 18}

## Programming Analogy (Python)

```python
# Simple even numbers
{x for x in range(1, 20) if x % 2 == 0}

# Squares of natural numbers below 6
{x**2 for x in range(1, 6)}

# Cartesian product example
{(x, y) for x in range(1, 4) for y in range(1, 3)}