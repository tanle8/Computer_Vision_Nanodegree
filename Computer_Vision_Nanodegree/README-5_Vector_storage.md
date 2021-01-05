# Vector Storage

## Vector Memory Storage
As previously mentioned, vectors are not the most efficient variable type in C++. One reason is because you do not need to specify a vector's length when declaring a vector variable. So the compiler will not know ahead of time how much memory to allocate. And once the vector's length goes beyond the initial allocated memory, the entire vector gets copied to a part of RAM with more space.

A vector is more efficient if you specify the vector's length before pushing values. You can do this with the reserve() method, which will guarantee that the vector can hold the number of elements reserved.
----------------------------------------

## Example
Here is an example of how to use the reserve() method.

```cpp
    #include <iostream>
    #include <vector>

    using namespace std;

    int main() {
        vector<int> myvector;
        int vector_size = 50;
        myvector.reserve(vector_size);

        for (int i = 0; i < vector_size; i++) {
            myvector.push_back(i);
        }

        return 0;
    }
```
----------------------------------------
In C++, there are multiple ways to initialize a 2D vector. When optimizing your programs, you'll need to test out different ways to initialize to see which works best in your specific program.

The fastest way could end up depending on the vector length and vector types.
----------------------------------------
## Exercise
In this next exercise, you're given three different functions in three separate files:

- reserved.cpp
- unreserved.cpp
- initializer.cpp
Your task will be to change the code in reserved.cpp so that the 2D vector variable and the 1D vector variable reserve their sizes before using the push_back method. You'll see if that change helps to make the code run faster.

The unreserved() function will initialize a 2D vector using a for loop. The initializer() function uses a standard library method for initializing a vector. The code in reserved.cpp is exactly the same as the code in unreserved.cpp. Your job will be to changed reserved.cpp to use the reserve() method.
------------------------------------------
