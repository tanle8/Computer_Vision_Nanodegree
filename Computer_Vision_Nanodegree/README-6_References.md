# References

Did you know that every time you call a function, those input variables get copied into memory? You can prove this to yourself with the following code:

```cpp
    #include <iostream>
    #include <vector>

    using namespace std;

    // function declaration that prints out a matrix's address in memory
    void matrix_address(vector< vector<int> > my_matrix);

    int main() {

        // initialize a matrix
        vector< vector<int> > matrix(5, vector<int>(6,2));

        // print out the matrix address
        cout << "original variable address: " << &matrix << "\n";

        // run a function that prints out a matrix address
        matrix_address(matrix);


        return 0;
    }

    // function to print out a matrix address
    void matrix_address(vector< vector<int> > my_matrix) {

        cout << "function variable address: " << &my_matrix << "\n";

    }
```

When you run this code, you'll get output that looks something like this:

**original variable address: 0x7fff5fbff650**

**function variable address: 0x7fff5fbff608**

So what is this code doing? The code initializes a 5x6 2D vector in a variable called matrix. Then the code prints out the address in memory where the 2D vector starts.

Next, the code calls a function that prints out the address in memory of the function's input variable. Notice that the addresses are not the same even though the two variables hold the same value.

This is because C++ is copying the 2D vector into memory again when you call the matrix_address() function.
-----------------------------------
## Ampersand Symbol
In the above code, you might have noticed the ampersand symbol: &.

This symbol gives you the address of a variable rather than the value of a variable. Do you remember in the previous lesson when you briefly learned about pointers? The ampersand is an easy way to access a variable's address without the danger of you mistakenly messing something up in memory.

And you can use the ampersand to help speed up your code!
-----------------------------------
## How the Ampersand Can Speed Up Code
C++ has a few fundamental data types like int, char, and float that are relatively fast to work with. So the coding strategy you're about to learn might not make much of a different with fundamental data types; however, with variables that take up a lot of memory such as arrays or vectors, the ampersand can be quite useful.

What if the matrix_address function shown above had been defined like this?
```
void matrix_address(vector< vector<int> >&my_matrix);
```
The ampersand (&) tells the compiler to pass the input variable by reference. That means inside your function, you'll be working with the original variable instead of a copy. In the case of a 2D vector, you've just saved yourself a lot of reads and writes.

And, depending on your application, you might be able to modify the input vector directly instead of creating a new vector inside your function. For example, if you were going to code scalar multiplication on a vector, and you didn't need to keep the original vector, you could modify the original vector directly. You'll see what this means in the exercise.
-----------------------------------
## Exercise
In this exercise, you're going to go back to the matrix addition function presented earlier in the lesson. You'll rewrite a version of the code passing matrices by reference. Let's see if this gets the code to run faster!
-----------------------------------