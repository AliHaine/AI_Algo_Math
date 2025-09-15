# Logarithm

![basic log](public/base_log.png)

## Definition

A logarithm grows continuously, but as the input gets larger, growth slows down.

In fact, a logarithm answer the question: **To what power must I raise the base to get this number?**.

$a^b = c \\\Longleftrightarrow\\ \log_{a}(c) = b$

In other words: a logarithm is the inverse of an exponential.

## Formula

The fundamental formula is

$a^b = c \\\Longleftrightarrow\\ \log_{a}(c) = b \;\;\Longleftrightarrow\;\; log_a(c) = \frac{ln(c)}{ln(a)}$

Iteration formula using Newton's method, _(Using $e$)_

$y_{n+1} = y_n - 1 + \frac{x}{e^{y_n}}$

## General notes

### Bases

There are 3 bases most commonly used:

- Base $e ≈ 2.718$ (natural log, ln) → Mathematics, calculus, continuous growth.
- Base 2($log_2$) → computer science (binary tress, complexity like $O(logn)$).
- Base 10($log_10$) → engineering, scales, orders of magnitude (decibels, pH)

### Conversion

No matter the base, logarithms can always be expressed using the natural logarithm

$log_a(c) = \frac{ln(c)}{ln(a)}$

## Example using Newton's method

We want

$2^3 = 8 \\\Longleftrightarrow\\ \log_{2}(8) = 3$

### Step 1: Approximate ln(8)

Start with $y0$ = 2

$y1 = 2 - 1 + \frac{8}{e^{2}} ≈ 1 + \frac{8}{7.3875} ≈ 2.0829$

Next iteration 

$y2 = 2.0829 - 1 + \frac{8}{e^{2.0829}} ≈ 1.0829 + \frac{8}{8.0829} ≈ 2.0797$

At this point, values are very close, so

$ln(8) ≈ 2.0797$

### Step Final: Convert to base 2

We also know 

$ln(2) ≈ 0.693$

So,

$log_2(8) = \frac{ln(8)}{ln(2)} = \frac{2.079}{0.693} = 3$

Final result 

$log_2(8) = 3$
