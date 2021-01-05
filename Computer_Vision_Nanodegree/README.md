# Software Development and Optimization

## Software Development
Writing functioning code is arguably your number one goal as a software developer. Depending on your application, code efficiency might be very important as well.

You could break down the code development process into the following steps:

- code design
- implementing the design
- testing for bugs and fixing the bugs
- optimization
For a more detailed explanation of each of these steps (design, implementation, testing), see this link.

As mentioned previously, there are many facets to code optimization related to hardware, compilers, algorithms and the C++ language itself. In this lesson, you'll focus on the C++ language. What you've just learned about the CPU and RAM will provide the context for why your code is able to run faster.

You will have the opportunity to learn and implement a few techniques that make C++ run even faster. Each exercise presents a "slow" version of the code and a technique for making the code faster. You will then implement the technique to see how much faster the code runs. While these techniques do not encompass all of the ways to optimize C++ code, you'll gain an understanding of how memory, the CPU and coding choices affect how fast your code runs.

At the end of the lesson, you are going to receive a set of files for a functioning C++ histogram filter. Your job will be to make the histogram filter code run faster using the techniques you've learned in the lesson.

## How to Optimize: Testing versus Instinct
To optimize your code, rely on testing and verification rather than instinct!

Test your code to find areas that are inefficient in terms of time, memory or power use. Then, verify that any changes you have made really do make the code more efficient. If you test first, you might even find that your code is already efficient enough for your particular application.

If you were optimizing a large amount of code, you would want to use something called a profiler. A profiler is a piece of software that measures how long parts of your code are taking to execute or how many resources the code uses. The profiler helps you find congestion points so that you can optimize the least efficient parts of the code first.

Both Visual Studio and Xcode come with profilers, which you can read about at these links:

- [Profiling in Visual Studio](https://docs.microsoft.com/en-us/visualstudio/profiling/beginners-guide-to-performance-profiling)
- [Profiling in Xcode](https://developer.apple.com/library/content/documentation/DeveloperTools/Conceptual/InstrumentsUserGuide/index.html)


## Testing your Code with Standard Clock
In the following exercises, we've set up some simple profiling code for you; you'll time how long it takes to run a function using the C++ standard clock.

You will optimize by:

- seeing how long it takes to run a function
- change some aspect of the code
- run the code again to see if the code runs faster
The profiling code has already been set up for you, and it looks like this:

```cpp
	#include <ctime>

	std::clock_t start;
	double duration;

	start = std::clock();

	function_name(var1, var2);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout << "duration milliseconds initialize beliefs " << 1000 * duration << '\n';
```

The code stores the current standard clock time, then runs a function, and then calculates the elapsed time.

The standard library clock measures time in terms of clock ticks. Clock ticks are like a counter variable that goes up at a constant rate of time. But the length of time varies from system to system; therefore, dividing by the constant CLOCKS_PER_SEC gives the results in terms of seconds. The CLOCKS_PER_SEC variable is defined in the ctime library.