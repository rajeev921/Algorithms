#include <fstream>
#include <iostream>
#include <streambuf>

class teebuf: public std::streambuf {

public:
    typedef std::char_traits<char> traits_type;
    typedef traits_type::int_type  int_type;

    teebuf(std::streambuf* sb1, std::streambuf* sb2): myStreamBuffer1(sb1),myStreamBuffer2(sb2) {}

    // overflow will be invoked in case of output
    // sputc sends the char c to the underlying buffer
    virtual int_type overflow(int_type c) {

        if (myStreamBuffer1->sputc(c) == traits_type::eof() || 
            myStreamBuffer2->sputc(c) == traits_type::eof())   return traits_type::eof();
        return c;
      }
private:
    std::streambuf * myStreamBuffer1;
    std::streambuf * myStreamBuffer2;
};

int main() {

  std::cout << std::endl;
  
  std::ofstream logfile("logfile.txt");
  teebuf myTeebuf(std::cout.rdbuf(), logfile.rdbuf());

  std::ostream log(&myTeebuf);

  log << "1" << std::endl;
  log << "2" << std::endl;
  log << "3" << std::endl;
  
  std::cout << std::endl;
  
}