#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::_;

class FooInterface {
public:	
		virtual bool Transform(bool b) = 0;
		virtual void toCall() = 0;
};

class RealFoo : public FooInterface {
public:
		FooInterface* Foo_;

		RealFoo(FooInterface* theFoo) : Foo_(theFoo) {}

		bool Transform(bool b) {
			return true;
		}

		void toCall() {
			Foo_->Transform(true);
			return;
		}
};


class MockFoo : public FooInterface {
public:
	
		MOCK_METHOD(bool, Transform, (bool b), (override));
		MOCK_METHOD(void, toCall, (), (override));
};



TEST(TestFooTest, FooExecute) {

	MockFoo turtle;                 
	EXPECT_CALL(turtle, Transform(_)).Times(1);

	RealFoo realTester(&turtle);

	realTester.toCall();
	EXPECT_TRUE(true);
}