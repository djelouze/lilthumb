#ifndef lilthumb
#define lilthumb

#include <ctime>
#include <ostream>

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

void stone( std::ostream& stream, double* c_array, int n_values = 0 )
{
  stream << timeString() << " | ";
  if( n_values == 0 )
  {
    stream << c_array << std::endl;
  }
  else
  {
    for( int i = 0; i < n_values - 1; i++ )
    {
      stream << c_array[i] << "/";
    }
    stream << c_array[n_values - 1] << std::endl;
  }
}

void stone( std::ostream& stream, std::string message )
{
  stream << timeString() << " | " << message << std::endl;
}

}

#endif
