#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;
using ::testing::_;



template <class TestServer>
class TestMachine {
	TestServer* TestServer_;

public:
	TestMachine(TestServer* testServer) : TestServer_(testServer) {}

	void print() {
		printf("hello\n");
		return;
	}

	void toCall() {
		TestServer_->print();
		return;
	}
};


class MockTest {
public:
	MOCK_METHOD(void, print, (), ());
};


TEST(TestServerTest, printHello) {

	
	MockTest mock_testserver;

	EXPECT_CALL(mock_testserver, print()).Times(1);

	TestMachine<MockTest> testmachine(&mock_testserver);
	testmachine.toCall();

	EXPECT_TRUE(true);
}