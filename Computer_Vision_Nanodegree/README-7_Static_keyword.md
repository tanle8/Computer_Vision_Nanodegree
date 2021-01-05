# The Static Keyword

Sometimes you'll need to use the same variable over and over again in your functions. If you think back on Andy's Python histogram filter code, the blur() function was an example.

The blur function contains a handful of blurring factors that are always the same every time the function gets called; however, in Andy's C++ code, which you'll be working with soon, he recalculates these blurring factors every time the code gets run.

What if you could declare and define these variables once no matter how many times your function gets called? You'd be able to eliminate some reads and writes to memory. This is the perfect use case for the C++ static keyword.
----------------------------------------

## Example
When you declare and define a variable inside a C++ function, the value gets allocated to memory.

For example,
```
    some_function() {
       int x = 5;
    }
```
allocates space in memory for the variable x and then assigns the value five. Then, when the function finishes, the CPU will remove the x variable from RAM. That means every time you run the function, the CPU will allocate and deallocate memory for the x variable.

If, on the other hand, your code uses the static keyword, the x variable gets allocated to memory the first time the function runs. And the x variable just stays allocated in memory for the duration of the entire program. You've just saved yourself some reads and writes to RAM:
```
    some_function() {
        static int x = 5;
    }
```
Notice that you need to declare and define the variable simultaneously. You cannot define a variable with the static keyword without giving the variable a value.
----------------------------------------
## Global Variables versus Static Variables
Static variables are actually placed in the same area of RAM as global variables. The difference is that global variables are declared outside of functions and are available anywhere in your program to any file or function. On the other hand, static variables remain in scope. So in the above example, some_function() is the only place that can access the x variable.
----------------------------------------
## Exercise
In this exercise, you'll see how much faster code can run when using the static keyword. You'll also have an opportunity to eliminate some for loops!

Think back on how the blur() function worked in the Python histogram filter lesson. You had a 2D grid representing the robot's world. Each grid space had a probability representing the likelihood that the robot was on that square. After the robot used its sensors and updated its beliefs, a blur function smoothed out the probability values.

In this exercise, you'll be working with a part of Andy's blur function: more specifically the part that calculates the blur window. You'll eliminate some for loops and also use the static keyword to get the code to run faster.