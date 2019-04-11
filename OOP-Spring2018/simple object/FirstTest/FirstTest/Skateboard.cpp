#include "pch.h"
#include "Skateboard.h"


#define DEBUG 1
#if DEBUG > 0
template <typename T> void __assertEquals__(const char* file, int line,
					const char *exStr, const T &expected,
					const char *actStr, const T &actual) {
	if (expected != actual) {
		std::stringstream msg;
		std::cerr << "error: expected result on line " << line 
			<< " of file " << file 
			<< ": " << expected << " for " << exStr
			<< ", but got " << actual << " for " << actStr
			<< "." << std::endl;
#if DEBUG > 10
	std::cerr << msg.str() << std::endl;
#endif
	  throw AssertionError(msg.str());
	} else {
#if DEBUG > 1000
	 std::cerr << "passed test on line " << line << " of file " << file << ": "
		 << " got " << actual << " for " << actStr << "as expected. " << std::endl;
#endif
	}
 }
#define assertEquals(expected, actual) __assertEquals__(__FILE__,__LINE__,#expected, expected, #actual, actual)

#else
#define assertEquals(expected, actual)

#endif











// ---------------------------------------------------------------------

Skateboard::Skateboard() {
	moving = false;
	greased = false;
}

bool Skateboard::isMoving() {
	if (moving == false) {
		return false;
	} else if (moving == true) {
		return true;
	}
}

bool Skateboard::isGreased() {
	if (greased == false) {
		return false;
	} else if (greased == true) {
		return true;
	}
}

void Skateboard::grease() {
	greased = true;
}

void Skateboard::clean() {
	greased = false;
}

void Skateboard::kickOff() {
	if (isGreased() == true) {
		moving = true;
	}
	else {
		throw AssertionError("Wheels must be greased before board can be ridden.");
	}
}

void Skateboard::tailGrind(){
	if (isMoving() == true) {
		moving = false;
	}
	else {
		throw AssertionError("You must be moving to perform a tail grind.");
	}
}



/* POWERED SKATEBOARD METHODS */

PoweredSkateboard::PoweredSkateboard() {
	charged = false;
}

bool PoweredSkateboard::isCharged() {
	if (charged == false) {
		return false;
	}
	else if (charged == true) {
		return true;
	}
}

void PoweredSkateboard::charge() {
	charged = true;
}

void PoweredSkateboard::ActivateBoost() {
	if (isCharged() == true) {
		moving = true;
	}
	else {
		moving = false;
	}
}
