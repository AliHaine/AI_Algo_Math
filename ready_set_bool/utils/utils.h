#ifndef UTILS_H
#define UTILS_H

    bool isVariable(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    bool isOperator(char c) {
        return c == '&' || c == '>' || c == '|' || c == '^' || c == '=';
    }

    bool isUnary(char c) {
        return c == '!';
    }

    int power(int number, int power) {
        int result = number;
        while (--power > 0)
            result *= number;
        return result;
    }

    bool isValidRPN(std::string formula) {
        int stack_size = 0;
        for (char c : formula) {
            if (isVariable(c))
                stack_size++;
            else if (isOperator(c)) {
                if (stack_size < 2) return false;
                stack_size--;
            }
            else if (isUnary(c)) {
                if (stack_size < 1) return false;
            }
            else
                return false;
        }
        return stack_size == 1;
    }
#endif