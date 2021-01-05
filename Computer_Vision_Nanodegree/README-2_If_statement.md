# If Statements

---------------------------------
Many compilers will try to optimize if statements for you. So writing something like this:

```cpp
    int x = 7;

    if (x > 0) {
      return y;
    if (x <= 0) {
       return z;
    }
```
might become

```cpp
    int x = 7;
    if (x > 0) {
       return y;
    else {
       return z;
    }
```
The compiler won't literally rewrite your C++ code into optimized C++ code; the compiler does the optimization when outputting assembly language or machine code. But in general, you'll want to avoid too many if branches because each branch's logical expression requires time on the CPU.
-----------------------------------------
Thinking about how if statements are executed, it's also more efficient to put the most common cases on a higher branch.

Here is a simple example:

```cpp
    for (int i = 0; i < 1000; i++) {
        if (i > 0 && i < 5) {
            cout <<  "low \n";
        }
        else if (i >= 990) {
            cout << "high \n";
        }
        else {
            cout << "normal \n";
        }
    }
```

Most of the time, the above code will print out the word "normal". So the code needs to go through all of the if and else branches most of the time as the CPU compares i in each branch.
------------------------------------
It would be more efficient to put the "normal" case at the top of the branches instead of at the bottom:

```cpp
    for (int i = 0; i < 1000; i++) {
        if (i >= 5 && i < 990) {
            cout <<  "normal \n";
        }
        else if (i >= 990) {
            cout << "high \n";
        }
        else {
            cout << "low \n";
        }
    }
```

Now, most of the time, the CPU can skip the else if and else branches.
---------------------------------
## If Statements on the CPU

There's one other aspect of if statements that you don't have much control over when using a high level language like C++. The CPU also tries to optimize if statement calculations by running simultaneous calculations.

When running a calculation, the CPU can look ahead and start working on another calculation in parallel. In terms of if statements, the CPU will try to predict which branch will be taken next and starts running the calculations inside the predicted branch. When it's time to evaluate the logical expression, the CPU might realize that it made a bad prediction. If the prediction is wrong, the predicted calculation stops and the CPU starts running the correct calculation.

So be aware that you might not get too much of a time boost when rearranging or eliminating if statements. Both the compiler and the CPU are already trying to optimize these operations for you.
---------------------------------
## Exercise
Move on to the next section to try out an if statement optimization exercise.

