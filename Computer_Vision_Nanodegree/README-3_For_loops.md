# For Loops

There is nothing wrong with using nested for loops (ie for loops inside of for loops). Sometimes you need them when working with C++ vectors.

However, don't use them if you don't need them! There are a few places in Andy's code where he has used nested for loops that were not needed.

If you are iterating through or initializing an m by n matrix, you might be tempted to always use nested for loops like this:

```cpp
    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix[0].size(); j++) {
            do something...
        }
    }
```

Iterating through the entire matrix involves m times n operations. However, depending on what you are trying to do, you might be able to get away with doing something like this:

```cpp
    for (unsigned int i = 0; i < matrix.size(); i++) {
        do something
    }

    for (unsigned int j = 0; j < matrix[0].size(); j++) {
        do something
    }
```

This only requires m + n operations instead of m * n operations. Remember that fewer instructions for the CPU will get your code to execute faster!

To see a specific example, go to the for loops exercise in the next part of the lesson.
-----------------------------------
## Exercise
In the next section, you'll find an exercise for optimizing a for loop. The code initializes a 2D vector using a for loop inside another for loop, which uses m*n operations. Think about how you could initialize the same 2D vector using only m + n operations (hint: remember that every position in the 2D vector has the same value).
-----------------------------------
