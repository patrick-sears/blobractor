

#include "cconfig.h"


#include <iostream>
#include <fstream>
#include <sstream>



cconfig::~cconfig()
{
}


cconfig::cconfig()
{
}



cconfig::cconfig(const cconfig &Xref)
{
}

void cconfig::operator=(const cconfig &Xref)
{
}


void cconfig::cout_info()const
{
  using std::cout;
  cout << "Class cconfig, line " << __LINE__ 
  << ", file:  " << __FILE__ << '\n';
  cout << "  blobfname:  [" << blobfname << "]\n";
  //cout << "indirlist:  " << indirlist << '\n';
}// cconfig::





int cconfig::load(const std::string &fname)
{
    std::ifstream fin(fname.c_str());
    if( ! fin.is_open() )
    {
        std::cerr << "ERROR:  File didn't open.\n"
        << "   [" << fname << "]\n"
        << "   In file:  " << __FILE__ << '\n'
        << "   Line:     " << __LINE__ << '\n';
        return 1;
    }

    std::string sline;
    int safe = 10000;

    while(true)
    {
        if(--safe <= 0)
        {
          std::cerr << "ERROR:  (--safe < 0)\n"
          << "  File:  " << __FILE__ << '\n'
          << "  Line:  " << __LINE__ << '\n';
          return 2;
        }

        getline(fin,sline,'\n');
        if( sline == "!end_of_data" ) break;

        if( sline.size() == 0 ) continue;
        if( sline.at(0) != '!' ) continue;

        if(           sline == "!install_dir" )
          getline( fin, install_dir, '\n' );
        else if(      sline == "!oudir" )
          getline( fin, oudir, '\n' );
        else if( sline == "!blobfname" )
          getline( fin, blobfname, '\n' );
        else if( sline == "!dirlist" )
          getline( fin, dirlist, '\n' );

    }

  return 0;
}// cconfig::









