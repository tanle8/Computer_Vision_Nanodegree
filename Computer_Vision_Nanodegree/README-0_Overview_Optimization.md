# Optimization Techniques

## Overview of Techniques in this Lesson
Here is an overview of the techniques you will be learning and using to optimize C++ code. Refer back to this page as you work through the exercises and on the final project. Each of these techniques will be expanded further throughout the lesson.

If you are wondering why we chose these techniques, it's because you can use all of them to optimize Andy's histogram filter code. This is not a comprehensive list of optimization techniques by any means; rather, practicing these techniques will get you thinking about your code from a new perspective. While your focus up until now has been on code implementation, now you will appreciate the consequences of your coding decisions.

## Remove Dead Code
When you write your code, you might end up with a chunk of code that is no longer used but still part of the program. Watch out for cases like these: remember that every line of code involves some work by the CPU and oftentimes a read or write to memory. Any unnecessary code could slow things down.

## Avoid Extra if Statements
Code with multiple branching if statements is oftentimes inefficient:

```cpp
    int x = 5;
    if (x >= 5) {x = x + 1;}
    if (x < 5) {x = x - 1;}
```

You could transform the above code into if else statements, which avoids the CPU checking whether x is less than 5.

## Avoid Nested for Loops
A section of code like this:

```cpp
    for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 4; j++) {
             matrix[i][j];   
       } 
    }
```
should look somewhat familiar. This is how you have been iterating over the values in a matrix. Sometimes you have no choice but to use a nested for loop; however, depending on the application, you might not need a nested for loop if you think about the problem in a different way. And instead of needing twenty iterations like in the above code, you might only need 9 or fewer iterations.

## Avoid Creating Extra Variables
You'll see that Andy sometimes creates extra variables that aren't needed. For example,

```cpp
    float x = 2;
    float y = 7;
    float z = 4;

    float volume = x * y * z;

    float volume_reciprocal = 1 / volume;
```

The volume variable isn't really necessary. You could calculate the reciprocal directly:

```cpp
    volume_reciprocal = 1 / (x * y * z);
```

You might not get much of a performance boost; float variables are relatively efficient in C++. But imagine creating a new variable to hold a larger variable like a 2D vector. All of the extra memory writes will definitely slow things down.

## Reserve Space in Memory for Vectors
You've been using 2D vectors to represent matrices. C++ vectors have a big benefit in terms of convenience; you can add new elements to the vector as needed. Arrays, on the other hand, have a fixed length that cannot be changed after declaring them.

But this flexibility comes at a cost; C++ vectors are very inefficient in terms of execution time. In fact, programs that require speedy execution would generally not use C++ vectors and especially not big for loops to iterate through vectors; instead, programs are written to take advantage of parallel processing on either the CPU or a GPU (graphics processing unit).

When you declare and define a vector, the compiler reserves space in memory plus some extra bytes in case the vector expands. Once the vector's length expands past the reserved memory, the entire vector will get copied over to a different place in RAM with enough available space.

That is very inefficient! In Andy's histogram filter code, you already know how large your vectors need to be because the robot world has a fixed number of grid spaces. If you reserve space for the vector, then you can avoid all of the extra memory reallocations as you expand the vector's length. The syntax is as simple as coding:

```cpp
    std::vector<int> foo;
    foo.reserve(15);
```

Now the foo vector is guaranteed to have enough space for holding fifteen integers.

## Passing Variables by Reference
Whenever you call a function, C++ copies any input variables into memory even if those variables are already in memory. For fundamental data types like int, char, or float, this might not be a problem.

But with variables that take up a more significant amount of space, such as vectors, the extra copying can slow down your programs.

You'll learn how to pass variables by reference instead of by value. Passing by reference tells your function to use the variable directly in memory rather than copying the entire variable to memory over again.

## Using Static
In Andy's code, you'll see that he calculates certain vectors and values inside a function, but these values are always the same every time the function is called.

Instead of calculating the variables over and over again, you can declare these variables as static. When the function is called the first time, C++ stores the values in memory and re-uses the values every time the function is called.

## Next Part of the Lecture
The next part of the lessons has a series of exercises that will get you ready for the project. In each exercise, you will receive code that has one of the issues discussed on this page. And then you will change the code to get the program to run faster.

You'll see that every time you run the code, the timer gives slightly different results; when you run your C++ program, the CPU might be carrying out other tasks that could affect timing. Be sure to execute your code multiple times to convince yourself that your code is (or isn't) running faster.