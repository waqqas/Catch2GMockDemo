#include "FileWriter.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <catch2/catch.hpp>


int run_tests(int argc, char* argv[])
{
   ::testing::GTEST_FLAG(throw_on_failure) = true;
   ::testing::InitGoogleMock(&argc, argv);

   return Catch::Session().run(argc, argv);

}

int run_app(int argc, char* argv[])
{
   FileWriter writer;

   writer.Open("output.txt");
   writer.Write("hello world");
   writer.Close();
   return 0;
}

int main (int argc, char* argv[])
{
   int result = 0;

   if(argc >= 2 && strcmp(argv[1], "test")== 0)
   {
      result = run_tests(--argc, &argv[1]);
   }
   else
   {
      result = run_app(argc, argv);
   }

   return result;
}