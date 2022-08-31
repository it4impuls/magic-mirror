#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MainSystem.h"
#include "API.h"

using namespace std;
using ::testing::_;
using ::testing::Return;
using ::testing::NiceMock;


class APIMock : public API {
public:
    MOCK_METHOD(void, setupSettings, (const int), (override));
    MOCK_METHOD(void, setupService, (const std::function< void(Service&) >&), (override));
    MOCK_METHOD(void, startService, (), (override));
    MOCK_METHOD(void, publishResource,(string operation, string path, const std::function< void(const std::shared_ptr< Session >) >& callback), (override));
    MOCK_METHOD(string, HTTPrequest,(const string& uri), (override));
};

class mainSystemTest : public ::testing::Test {
protected:
    NiceMock<APIMock> theMock;
    MainSystem* theSystem;

    bool systemUp;

    void SetUp() override {
        theSystem = new MainSystem(&theMock);
    }
    void TearDown() override {
        delete theSystem;
    }
};


TEST_F(mainSystemTest, initSystem) {

    EXPECT_CALL(theMock, setupSettings(1984)).Times(1);
    EXPECT_CALL(theMock, setupService(_)).Times(1);

    systemUp = theSystem->initSystem();
    ASSERT_TRUE(systemUp);

}

TEST_F(mainSystemTest, getTime) {

    EXPECT_CALL(theMock, HTTPrequest("http://worldtimeapi.org/api/timezone/Europe/Berlin")).WillRepeatedly(Return("{\"Time\":\"12:30\",\"Date\":\"02.02.2022\",\"Day\":\"Monday\"}"));

    auto theTime = theSystem->getTimeJSON();

    ASSERT_TRUE(theTime == "{\"Time\":\"12:30\",\"Date\":\"02.02.2022\",\"Day\":\"Monday\"}");
}
