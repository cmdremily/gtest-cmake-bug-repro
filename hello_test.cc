#include <gmock/gmock.h>

using ::testing::Return;

struct foo {
    virtual int f() = 0;
};

struct mock_foo {
    MOCK(int, f, (), (override));
};

struct bar {
    bar(foo* f) : f_(f) {}

    int baz() { return f_.f(); }
    foo* f_;
};

TEST(mock_test, test) {
    mock_foo m;
    EXPECT_CALL(m, f).WillOnce(Return(3));

    bar cut(&m);
    EXPECT_EQ(cut.baz(), 3);
}
