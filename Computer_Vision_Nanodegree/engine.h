#ifndef ENGINE_H
#define ENGINE_H

/* Header Code */
#include <string>

class Engine
{
private:
	std::string enginesize;

public:

	Engine();

	Engine(std::string);

	void setSize(std::string);

	std::string getSize();

};
/* End of Header Code */


#endif // !ENGINE_H

