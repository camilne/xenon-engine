#include "Window.hpp"
#include "gtest/gtest.h"

TEST(WindowTest, CanCreateWindow) {
    xe::Window window(1280, 720, "Test");
}

TEST(WindowTest, CanGetShouldWindowClose) {
    xe::Window window(1280, 720, "Test");

    ASSERT_EQ(false, window.shouldClose());
}

TEST(WindowTest, CanUpdateWindow) {
    xe::Window window(1280, 720, "Test");

    window.update();
}

TEST(WindowTest, CanGetWidthOfWindow) {
    xe::Window window(1280, 720, "Test");

    ASSERT_EQ(1280, window.getWidth());
}

TEST(WindowTest, CanGetHeightOfWindow) {
    xe::Window window(1280, 720, "Test");

    ASSERT_EQ(720, window.getHeight());
}