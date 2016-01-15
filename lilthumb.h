#ifndef lilthumb
#define lilthumb

#include <ctime>
namespace lilthumb{

std::string timeString()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  std::string str(buffer);

  return str;
}
}

#define logger(stream,message) stream << lilthumb::timeString() << " | "<< message << std::endl;
#endif
