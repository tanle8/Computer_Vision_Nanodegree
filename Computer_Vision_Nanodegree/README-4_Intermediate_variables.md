# Intermediate Variables

In Andy's code, you'll notice that he sometimes uses intermediate variables. Intermediate variables could be considered redundant code.

For example:

```cpp
float x = 5.8;
float y = 7.1;

float area = x * y;
float reciprocal_area = 1/(area);
```

If you only needed to calculate the reciprocal, you could have written:

```cpp
float x = 5.8;
float y = 7.1;
float reciprocal_area = 1/(x*y);
```

Fundamental variable types like float, int, and char are relatively efficient. So you probably won't notice much of a different when running these two versions of the code. In fact, your compiler might end up eliminating any inefficiencies between the first version and the second version.

So why discuss intermediate variables?
---------------------------------------------

## Intermediate Matrix Variables

You'll find a spot in Andy's code where he actually uses a 2D vector as an intermediate variable. It's not as obvious as the above example. But if you find it, you can definitely make the code run faster by eliminating the extra variable.

As mentioned in the beginning of the lesson, vectors are convenient but not particularly efficient; the compiler allocates a certain amount of memory for a new vector and adds a few more bytes as a buffer. The buffer can hold extra elements that you might push to the back of the vector.

But when the vector increases beyond its allocated size, the whole entire vector gets copied to another part of RAM. That is super inefficient!

So if you already have a variable vector that you can update directly, avoid making a copy of the vector!
--------------------------------------------

## Exercise
In the next exercise, you'll get to see just how inefficient it is to create new vectors. The code iterates through a 2-dimensional vector dividing each element by a constant. But instead of iterating the vector directly, the code creates a new, but unnecessary 2-D vector.
--------------------------------------------