#include "Window.hpp"
#include "gtest/gtest.h"

TEST(window_test, create) {
    xe::Window window(1280, 720, "Test");
}