#pragma once
using namespace std;


/* automobile Class */

class car {
public:
	virtual bool hasWheels() { return true; }
	virtual bool hasEngine() { return true; }
};


/* cityCar Class */

class cityCar : public car {
public:
	virtual float GoodMPG() { return 19.0; }
};


/* rallyCar Class */

class rallyCar : public car {
public:
	virtual bool hasAWD() { return true; }
};


/* should have 4 functions
*
* GoodMPG	from cityCar
* hasAWD	from rallyCar
* hasEngine from automobile
* hasWheels	from automobile
*
*/

class subaru : public cityCar, public rallyCar {
};