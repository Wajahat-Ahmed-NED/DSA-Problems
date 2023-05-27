# Problem Source : Coding Ninjas
def minimumParentheses(pattern):

    # Write your code here
    # Return the minimum number of parentheses required.
    stack=[]
    count=0
    for char in pattern:

        # running time is 788ms
        # if i==")" and len(stack)>0:
        #     if stack[0]=="(":
        #         stack.pop(0);
        #     else:
        #         stack.insert(0,i)
        # else:
        #     stack.insert(0,i)
        
        # running time is 588ms
        if char == ")" and stack and stack[-1] == "(":
            stack.pop()
        else:
            stack.append(char)


    return len(stack)