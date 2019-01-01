#include "FileWriter.h"


FileWriter::FileWriter()
{

}

bool FileWriter::Open(const std::string& filename)
{
   Close();

   handle_.open(filename);
   return handle_.is_open();
}

void FileWriter::Write(const std::string& text)
{
   if(handle_.is_open())
   {
      handle_ << text;
   }
}

void FileWriter::Close(void)
{
   if(handle_.is_open())
   {
      handle_.close();
   }
}