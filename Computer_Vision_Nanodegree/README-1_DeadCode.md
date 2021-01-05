# Dead Code

## What is Dead Code?

Dead code is extra code in your program that no longer serves a purpose. Maybe while implementing a solution, you started down a path that did not end up working out. Or you put in extra code for debugging purposes, but this code is not actually part of the solution. The dead code just sits in your program without affecting the implementation.

Dead code can slow down a program; the code will still be executed on the CPU and might include reads and writes to memory although the code is never used.

Two other issues related to dead code, and sometimes also considered to be dead code, are redundant code and unreachable code.
-----------------------------------

## Redundant Code
Redundant code is just like it sounds; this is code that gets repeated multiple times although isn't necessary. Here's a quick example:

```cpp
    // example of redundant code
    int x = 6;
    if (x > 5) {
       return true;
    }
    else {
       return false;
    }
```

Essentially, saying x > 5 and then returning True is redundant. You could eliminate the if statement by just saying

```
return x > 5;
```

Here's another example

```cpp
    if (x < 5) {
           x = x + 1;
    }
    else if (x >= 5 && x < 10) {
        x = x + 2;
    }
```

There is no need to check if `x >= 5`; the first if statement has essentially already proven whether x is greater than or less than five.

Finding redundant code, however, might not be so easy. It could be an extra variable declaration or maybe some extra logical statements like in the above example.
---------------------------------------

## Unreachable Code
Unreachable code never gets executed. Unreachable code might not have too much of an effect on code speed, but the code still takes up space in memory and can make memory management less efficient.

A simple example would be the following:

```cpp
    unsigned int x;

    ... 

    if (x >= 0) {
       do_something ..
    }
    else {
      do_something ..
    }
```

An unsigned integer is always zero or positive, so the else statement will never execute. The code inside the else statement is unreachable.
-----------------------------------
When you get to Andy's code at the end of the lesson, just keep an eye out for dead code or redundant code. You might find a couple of spots.

In the next part of the lesson, you will see a program that adds two matrices together. You'll execute the code to see how fast it runs. But the program contains dead code. So you will remove the dead code to see if the program runs faster.
-----------------------------------