#include "Demo.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <catch/catch.hpp>

int run_tests(char* argc, char* argv[])
{

}

int run_app(char* argc, char* argv[])
{

}

int main (char* argc, char* argv[])
{
   int result = 0;

   if(argc == 2 && strcmp(argv[1], "test")== 0)
   {
      result = run_tests(argc, argv);
   }
   else
   {
      result = run_app(arc, argv);
   }

   return result;
}