

#include "blobractorpro.h"
#include "cconfig.h"


#include <iostream>





int go( const int argc, const char** argv );

int parse_arguments( cconfig &cc, const int argc, const char** argv );


int main( const int argc, const char** argv )
{
  int rv=0;

  using std::cout;
  try
  {
    cout << "A la bataille!\n";  
  
    rv = go(argc, argv);
  }
  catch(const int e)
  {
    std::cout << "\n\nAn int error was caught in main.\n"
    << "   e = " << e << "\n\n";
    rv=1;
  }
  catch(...)
  {
    std::cout << "\n\nA (...) error was caught in main.\n\n";
    rv=1;
  }

  std::cout << "Exiting main(), rv = " << rv << '\n';
  return rv;
}//main









int go( const int argc, const char** argv )
{
  using std::cout;

  cconfig cc;

  int rv = parse_arguments( cc, argc, argv );
  if( rv != 0 )
  {
    std::cerr << "ERROR\n"
    << "  Bad parse_arguments() rv, " << rv << '\n'
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 1;
  }


  blobractorpro pro;

  rv = pro.export_one(cc.blobfname, cc.oudir);
  if( rv != 0 )
  {
    std::cerr << "ERROR\n"
    << "  Bad pro.export_one() rv, " << rv << '\n'
    << "  File:  " << __FILE__ << '\n'
    << "  Line:  " << __LINE__ << '\n';
    return 2;
  }

  return 0;
}// int go




int parse_arguments( cconfig &cc, const int argc, const char** argv )
{
  int rv = 0;
  std::string sarg;

  int i;
  for(i=1; i<argc; i++)
  {
    sarg = argv[i];
    if( sarg == "--install_dir" )
    {
      i += 1;
      if( i >= argc )
      {
        std::cout << "Error.  i >= argc.\n"
        << "  Expected a config file.\n"
        << "  i = " << i << '\n';
        rv = 1;
        break;
      }
      cc.install_dir = argv[i];
    }
    else if( sarg == "--config" )
    {
      i += 1;
      if( i >= argc )
      {
        std::cout << "Error.  i >= argc.\n"
        << "  Expected a config file.\n"
        << "  i = " << i << '\n';
        rv = 1;
        break;
      }
      if( 0 != cc.load( argv[i] ) )
      {
        std::cerr << "ERROR:  cc.load(argv[i]) != 0.\n"
        << "  i = " << i << '\n'
        << "  File:  " << __FILE__ << '\n'
        << "  Line:  " << __LINE__ << '\n';
        rv = 1;
        break;
      }
    }
    else if( sarg == "--oudir" )
    {
      i += 1;
      if( i >= argc )
      {
        std::cout << "Error.  i >= argc.\n"
        << "  Expected a oudir.\n"
        << "  i = " << i << '\n';
        rv = 1;
        break;
      }
      cc.oudir = argv[i];
    }
    else if( sarg == "--blobfname" )
    {
      i += 1;
      if( i >= argc )
      {
        std::cout << "Error.  i >= argc.\n"
        << "  Expected a blobfname.\n"
        << "  i = " << i << '\n';
        rv = 1;
        break;
      }
      cc.blobfname = argv[i];
    }
  }// for

  cc.cout_info();
  return rv;
}// int parse_arguments( cconfig &cc, const int argc, const char** argv )





