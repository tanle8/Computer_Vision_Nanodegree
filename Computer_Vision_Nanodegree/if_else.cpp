#include <iostream>


void posOrNeg() {
    /*
   * TODO: Use this as a playground for writing if, else if and else statements
   * To get you started here, are some ideas:
   *
   * 1. Create an integer variable and a set of if, elseif and else statements that
   * output whether the number is positive or negative.
   */

    int num = 0;

    if (num < 0)
    {
        std::cout << "The number is negative." << std::endl;
    }
    else if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }
}

void drive() {
    /*
    * 2. Create a character variable containing 'a' for acceleration, 'b' for braking,
    * 'p' for parked, or 'n' for neutral and outputs whether or not the vehicle is accelerating, braking,
    * parked or in neutral.
    */

    char character = 'j';

    if (character == 'a') {
        std::cout << "accelerating" << std::endl;
    }
    else if (character == 'b') {
        std::cout << "braking" << std::endl;
    }
    else if (character == 'p') {
        std::cout << "parked" << std::endl;
    }
    else if (character == 'n') {
        std::cout << "neutral" << std::endl;
    }
    else {
        std::cout << "unknown." << std::endl;
    }
}

/*

int main() {

    posOrNeg();
    drive();

    return 0;
}

*/

