#include <gtest/gtest.h>
#include "add.h"

TEST(TextEditor, positionpositive) {
  TextEditor pos;
  ASSERT_NO_THROW(pos.position(5, 5));
}

TEST(TextEditor, positionnegative) {
  TextEditor pos;
  ASSERT_ANY_THROW(pos.position(-5, -5));
}

TEST(TextEditor, constructorinitialization) {
  ASSERT_NO_THROW(TextEditor init(10, 10));
}

TEST(TextEditor, constructordeff) {
  ASSERT_NO_THROW(TextEditor init());
}

TEST(TextEditor, hirvisnegative) {
  TextEditor hv;
  ASSERT_ANY_THROW(hv.iftext("text", 20));
}

TEST(TextEditor, constrs) {
  TextEditor a(1, 1), b;
  EXPECT_EQ(a, b);
}

TEST(TextEditor, constrss) {
  TextEditor a, b(1, 1);
  EXPECT_EQ(a, b);
}
