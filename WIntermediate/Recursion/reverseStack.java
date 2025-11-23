import java.util.Stack;

public
class ReverseStack
{

public
    static void reverse(Stack<Integer> stack)
    {
        if (stack.isEmpty())
            return;

        int top = stack.pop();
        reverse(stack);
        insertAtBottom(stack, top);
    }

private
    static void insertAtBottom(Stack<Integer> stack, int value)
    {
        if (stack.isEmpty())
        {
            stack.push(value);
            return;
        }

        int top = stack.pop();
        insertAtBottom(stack, value);
        stack.push(top);
    }

public
    static void main(String[] args)
    {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        reverse(stack);

        System.out.println(stack); // [1,2,3,4] -> reversed output [4,3,2,1]
    }
}
