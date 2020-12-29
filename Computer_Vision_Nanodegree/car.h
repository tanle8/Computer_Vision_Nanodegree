#ifndef CAR_H
#define CAR_H

/* Header Code */
#include <string>
#include "engine.h"

class Car
{
private:
	std::string color;
	int doors;
	Engine enginetype;

public:
	Car(std::string, int);

	void setColor(std::string);
	void setDoors(int);
	void setEngine(std::string);

	std::string getColor();
	int getDoors();
	std::string getEngine();

};
/* End of Header Code */

#endif // !CAR_H


