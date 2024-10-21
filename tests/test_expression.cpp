#include "expression.h"
#include <gtest/gtest.h>

using namespace h10;

// Test Constant class
TEST(ExpressionTest, ConstantEvaluation) {
    Constant c1(5.0);
    EXPECT_DOUBLE_EQ(c1.evaluate(), 5.0);
    EXPECT_EQ(c1.toString(), "5.000000");
}

TEST(ExpressionTest, ConstantStringConversion) {
    Constant c1(2.5);
    EXPECT_EQ(c1.toString(), "2.500000");
}

TEST(ExpressionTest, ConstantSetValue) {
    Constant c1(3.0);
    EXPECT_DOUBLE_EQ(c1.evaluate(), 3.0);
    c1.setValue(6.5);
    EXPECT_DOUBLE_EQ(c1.evaluate(), 6.5);
}

// Test BinaryPlus class
TEST(ExpressionTest, BinaryPlusEvaluation) {
    Constant c1(2.0);
    Constant c2(3.0);
    BinaryPlus bp(c1, c2);
    EXPECT_DOUBLE_EQ(bp.evaluate(), 5.0);
}

TEST(ExpressionTest, BinaryPlusStringConversion) {
    Constant c1(1.0);
    Constant c2(2.0);
    BinaryPlus bp(c1, c2);
    EXPECT_EQ(bp.toString(), "(1.000000 + 2.000000)");
}

// Test complex expressions
TEST(ExpressionTest, ComplexExpression) {
    Constant c1(1.0);
    Constant c2(2.0);
    Constant c3(3.0);
    BinaryPlus bp(c1, c2);
    BinaryPlus bp2(bp, c3);
    EXPECT_EQ(bp2.toString(), "((1.000000 + 2.000000) + 3.000000)");
    EXPECT_DOUBLE_EQ(bp2.evaluate(), 6.0);
}

// Test polymorphism and switch value
TEST(ExpressionTest, PolymorphismAndSwitchValue) {
    Constant c1(1.0);
    Constant c2(2.0);
    BinaryPlus bp(c1, c2);
    
    // Try to switch value of c1 (successful)
    switchValue(c1, 10.0);
    EXPECT_DOUBLE_EQ(c1.evaluate(), 10.0);
    
    // Try to switch value of BinaryPlus (should fail)
    testing::internal::CaptureStderr();
    switchValue(bp, 5.0); // Should not modify bp
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Cannot switch value of non-constant expression\n");
}

