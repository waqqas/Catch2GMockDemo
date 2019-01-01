#pragma once

#include <string>
#include <fstream>

class FileWriter
{
   public: 
      FileWriter();
      virtual bool Open(const std::string& filename);
      virtual void Write(const std::string& text);
      virtual void Close();

   private:
      std::fstream handle_;
};