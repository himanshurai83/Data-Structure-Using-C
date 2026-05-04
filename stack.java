import java.util.Scanner;

public class stack {
    int MAX_SIZE = 10;
    int[] stack = new int[MAX_SIZE];
    int top = -1;
    int size;

    void displayStack() {
        if (top < 0)
            System.out.println("Stack is Empty!..");
        else {
            for (int i = top; i >= 0; i--) {
                System.out.print(" | ");
                System.out.print(stack[i]);
                System.out.print(" | ");
            }
        }
    }

    void checkSpace() {
        System.out.println("Stack total size: " + MAX_SIZE);
        System.out.println("Stack total size Full: " + (top + 1));
        System.out.println("Stack total size Empty: " + (MAX_SIZE - size));
    }

    void push() {
        if (top == MAX_SIZE - 1) {
            System.out.println("Stack is Full!...Overflow!!!!");
        } else {

            Scanner sc = new Scanner(System.in);
            System.out.print("Enter the element: ");
            int data = sc.nextInt();
            top = top + 1;
            size++;
            stack[top] = data;
            System.out.println(data + " is pushed....");
            checkSpace();
        }
    }

    void pop() {
        if (top < 0) {
            System.out.println("Stack is Empty....Underflow!!!!");
        } else {
            int data = stack[top];
            top = top - 1;
            size--;
            System.out.println(data + " is popped...");
            checkSpace();
        }
    }

    void count() {
        if (top < 0)
            System.out.println("Stack is Empty");
        else
            System.out.println("Count is: " + (top + 1));
    }

    void peek() {
        System.out.println("Top of the element is: " + stack[top]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        stack obj = new stack();
        obj.checkSpace();
        while (true) {
            System.out.println("\n1. for Display Stack");
            System.out.println("\n2. for Push");
            System.out.println("\n3. for Pop");
            System.out.println("\n4. for Peek");
            System.out.println("\n5. for Check Stack Count");
            System.out.println("\n6. for Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            if (choice == 6)
                break;
            switch (choice) {
                case 1:
                    obj.displayStack();
                    break;
                case 2:
                    obj.push();
                    break;
                case 3:
                    obj.pop();
                    break;
                case 4:
                    obj.peek();
                    break;
                case 5:
                    obj.count();
                    break;
                default:
                    System.out.println("Invalid choice!..");
                    break;

            }
        }
        System.out.println("Thanks for using this APP....");
        System.out.println("Hope you are enjoy it!");

    }
}