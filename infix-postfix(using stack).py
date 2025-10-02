#converting infix to postfix using stack
#We will convert infix expression to postfix using stack based approach implemented in python using this code

#code
def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    if op == '^':
        return 3
    return 0

def is_operand(ch):
    return ch.isalnum()

def infix_to_postfix(expression):
    result = []
    stack = []

    for ch in expression:
        if is_operand(ch):
            result.append(ch)
        elif ch == '(':
            stack.append(ch)
        elif ch == ')':
            while stack and stack[-1] != '(':
                result.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(stack[-1]) >= precedence(ch):
                result.append(stack.pop())
            stack.append(ch)

    while stack:
        result.append(stack.pop())

    return "".join(result)


'''expr = "A*(B+C)/D"
print("Infix:", expr)
print("Postfix:", infix_to_postfix(expr))''' #example code to try
