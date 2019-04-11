#include "pch.h"
#include "Skateboard.h"


/* START TESTING,SKATEBOARD */

TEST(Skateboard, isMoving) {
	Skateboard obj;
	bool res = obj.isMoving();
	EXPECT_FALSE(res);
}

TEST(Skateboard, isGreased) {
	Skateboard obj;
	bool res = obj.isGreased();
	EXPECT_FALSE(res);
}

TEST(Skateboard, grease) {
	Skateboard obj;
	obj.grease();
	bool res = obj.isGreased();
	EXPECT_TRUE(res);
}

TEST(Skateboard, clean) {
	Skateboard obj;
	obj.grease();
	bool first = obj.isGreased();
	obj.clean();
	bool second = obj.isGreased();
	EXPECT_NE(first, second);
}

TEST(Skateboard, kickOff) {
	Skateboard obj;
	bool expResult = false;
	bool result = true;
	try {
		obj.kickOff();
	}
	catch (AssertionError) {
		result = false;
	}
	EXPECT_EQ(expResult, result);
}

TEST(Skateboard, tailGrind) {
	Skateboard obj;
	bool expResult = false;
	bool result = true;
	try {
		obj.tailGrind();
	}
	catch (AssertionError) {
		result = false;
	}
	EXPECT_EQ(expResult, result);
}

/* END TESTING, SKATEBOARD */

/* START TESTING, POWERED SKATEBOARD */

TEST(PoweredSkateboard, isCharged) {
	PoweredSkateboard obj;
	bool res = obj.isCharged();
	EXPECT_FALSE(res);
}

TEST(PoweredSkateboard, charge) {
	PoweredSkateboard obj;
	obj.charge();
	bool res = obj.isCharged();
	EXPECT_TRUE(res);
}

TEST(PoweredSkateboard, ActivateBoost) {
	PoweredSkateboard obj;
	obj.ActivateBoost();
	bool res = obj.isMoving();
	EXPECT_FALSE(res);
}

/* END TESTING, POWERED SKATEBOARD */

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}