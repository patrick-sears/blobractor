

#ifndef CCONFIG_H
#define CCONFIG_H

#include <string>
#include <fstream>



class cconfig
{
public:
  ~cconfig();
  cconfig();
  cconfig(const cconfig &Xref);

  void operator=(const cconfig &Xref);


  // load functions return 0 if success.
  // non-zero upon failure.
  int load(const char* fname)
  { std::string f(fname); return load(f); }
  int load(const std::string &fname);


  void cout_info()const;

  // std::string indir;
  // Not needed because dirlist file has full path names.

  std::string install_dir;
  std::string dirlist;
  std::string oudir;

  std::string blobfname;

private:

  int config_id;



};//class cconfig





#endif

