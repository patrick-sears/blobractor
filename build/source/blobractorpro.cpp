




#include "blobractorpro.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>






blobractorpro::~blobractorpro()
{

}


blobractorpro::blobractorpro()
{
}


blobractorpro::blobractorpro(const blobractorpro &X)
{
}


void blobractorpro::operator=(const blobractorpro &X)
{
}// blobractorpro::


int blobractorpro::export_one(
    const std::string &infname,
    const std::string &oudir
    )
{
  int rv;

  // Export all images from one blob file.
  using std::cout;
  std::ifstream fi( infname.c_str() );
  if( ! fi.is_open() )
  {
    std::cerr << "ERROR\n"
    << "  File [" << infname << "] did not open.\n"
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 1;
  }
  else cout << "File opened.\n";

  const size_t N_buf = 4;
  char buf[N_buf];
  uint32_t kk;

  fi.read(buf, N_buf);

  uint32_t N_im = 0;
  rv = get32(N_im, buf,N_buf);
  if( rv != 0 )
  {
    std::cerr << "ERROR\n"
    << "  Bad get32() rv, " << rv << '\n'
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 1;
  }


  cout << "N_im:  " << N_im << '\n';

  int N_im_i = static_cast<int>(N_im);
  cout << "N_im_i:  " << N_im_i << '\n';

  const size_t N_buf_im = 1000000;  // Changed in version 0.1.1
  char buf_im[N_buf_im];
  size_t im_size;


  std::ofstream fo;
  std::string imfname;
  std::string imbasename( oudir );
  imbasename += "/im";
  
  std::string s_i;
  int i;
  for(i=0; i<N_im_i; i++)
  {
    fi.read(buf, N_buf);
    
    rv = get32(kk, buf, N_buf);
    if( rv != 0 )
    {
      std::cerr << "ERROR\n"
      << "  Bad get32() rv, " << rv << '\n'
      << "  File:  " << __FILE__ << '\n'
      << "  Line:  " << __LINE__ << '\n';
      return 1;
    }
    im_size = static_cast<size_t>(kk);
    s_i = std::to_string(i);
    //cout << "  " << i << ".  size = " << im_size << '\n';
    cout << "  " << i << ".  number = " << s_i << '\n';

    imfname = imbasename;
    if( i <= 9 ) imfname += '0';
    if( i <= 99 ) imfname += '0';
    if( i <= 999 ) imfname += '0';
    imfname += s_i;
    imfname += ".jpg";

    // if( im_size > 100000 ) // Old in version 0.1.0.
    if( im_size > N_buf_im ) // Changed in version 0.1.1.
    {
      std::cerr << "ERROR\n"
      << "  size too large\n"
      << "  File:  " << __FILE__ << '\n'
      << "  Line:  " << __LINE__ << '\n';
      return 2;
    }
    fi.read(buf_im, im_size);
    cout << "Writing [" << imfname << "]\n";
    fo.open( imfname.c_str() );
    if( ! fo.is_open() ) 
    {
      std::cerr << "ERROR\n"
      << "  File [" << imfname << "] did not open.\n"
      << "  File:  " << __FILE__ << '\n'
      << "  Line:  " << __LINE__ << '\n';
      return 3;
    }
    fo.write(buf_im, im_size);
    fo.close();
  }

  return 0;
}// void blobractorpro::export_one(





int blobractorpro::get32(uint32_t &out, const char* buf, const size_t &N_buf)
{
  using std::cout;
  if( N_buf != 4 )
  {
    std::cerr << "ERROR\n"
    << "  N_buf != 4\n"
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 1;
  }
  if( buf == 0 )
  {
    std::cerr << "ERROR\n"
    << "  buf == 0\n"
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 1;
  }

  //unsigned char k;
  int k;

  out = 0;

  size_t i;
  for(i=0; i<N_buf; i++)
  {
    k = static_cast<unsigned char>(buf[i]);
    out += k;
    if( i != N_buf-1 )  out <<= 8;
  }
  return 0;
}// blobractorpro::









