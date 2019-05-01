



#ifndef BLOBRACTORPRO_H
#define BLOBRACTORPRO_H


#include <string>
#include <sstream>
#include <cstdint>  // C++11, needed for uint32_t





class blobractorpro
{
public:
  ~blobractorpro();
  blobractorpro();
  blobractorpro(const blobractorpro &X);
  void operator=(const blobractorpro &X);



  // Returns 0 upon success, non-zero upon failure.
  int export_one(
    const std::string &infname,
    const std::string &oudir
    );


private:
  static int get32(uint32_t &out, const char* buf, const size_t &N_buf);
  // Returns 0 upon success, non-zero upon failure.

};//blobractorpro










#endif


