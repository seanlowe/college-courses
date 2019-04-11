#include "pch.h"
#include "car.h"

/* --------------------------------------- */
/* automobile tests */
TEST(car, hasEngine) {
	car obj;
	bool res;
	res = obj.hasEngine();
	ASSERT_TRUE(res);
}

TEST(car, hasWheels) {
	car obj;
	bool res;
	res = obj.hasWheels();
	ASSERT_TRUE(res);
}

/* --------------------------------------- */
/* cityCar tests */
TEST(cityCar, hasEngine) {
	cityCar obj;
	bool res;
	res = obj.hasEngine();
	ASSERT_TRUE(res);
}

TEST(cityCar, hasWheels) {
	cityCar obj;
	bool res;
	res = obj.hasWheels();
	ASSERT_TRUE(res);
}

TEST(cityCar, GoodMPG) {
	cityCar obj;
	float exp, res;
	exp = 19.0;
	res = obj.GoodMPG();
	ASSERT_EQ(exp, res);
}

/* --------------------------------------- */
/* rallyCar tests */
TEST(rallyCar, hasEngine) {
	rallyCar obj;
	bool res;
	res = obj.hasEngine();
	ASSERT_TRUE(res);
}

TEST(rallyCar, hasWheels) {
	rallyCar obj;
	bool res;
	res = obj.hasWheels();
	ASSERT_TRUE(res);
}

TEST(rallyCar, hasAWD) {
	rallyCar obj;
	bool res;
	res = obj.hasAWD();
	ASSERT_TRUE(res);
}

/* --------------------------------------- */
/* subaru tests */
TEST(subaru, hasEngine) {
	subaru obj;
	bool res;
	res = obj.car::hasEngine();
	ASSERT_TRUE(res);
}

TEST(subaru, hasWheels) {
	subaru obj;
	bool res;
	res = obj.car::hasWheels();
	ASSERT_TRUE(res);
}

TEST(subaru, GoodMPG) {
	subaru obj;
	float exp, res;
	exp = 19.0;
	res = obj.GoodMPG();
	ASSERT_EQ(exp, res);
}

TEST(subaru, hasAWD) {
	subaru obj;
	bool res;
	res = obj.hasAWD();
	ASSERT_TRUE(res);
}