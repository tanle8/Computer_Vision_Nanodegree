#include <iostream>


void traffic_light(int time) {
	int elapsed_time = time;

	while (elapsed_time > 0)
	{
		std::cout << "Traffic Light is Red" << std::endl;
		elapsed_time = elapsed_time - 1;
	}

	std::cout << "Traffic Light is Green" << std::endl;
}


void quiz_for_loop() {
	//TODO: Use this as a playground to write a for loop and if statements
	// in the same program.

	// For example, write a for loop that iterates from 0 to 80.
	// If the iterator is greater than or equal to 0 but less than 10, 
	//      output the phrase 'slow'
	// If the iterator is between 10 inclusive
	//      and less than 30, output the phrase 'medium'
	// If the iterator is between 30 inclusive and 70, output the phrase 'fast'
	// If the iterator is greater than 70 inclusive, output the phrase 'too fast'
	for (int iterator = 0; iterator <= 80; iterator++) {
		if (iterator < 10) {
			std::cout << iterator << " slow" << std::endl;
		}
		else if (iterator < 30) {
			std::cout << iterator << " medium" << std::endl;
		}
		else if (iterator < 70 ) {
			std::cout << iterator << " fast" << std::endl;
		}
		else {
			std::cout << iterator << " too fast" << std::endl;
		}
	}
}


/*

int main() {
	//traffic_light(15);
	quiz_for_loop();

	return 0;
}

*/
