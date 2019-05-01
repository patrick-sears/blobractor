#!/bin/bash


wd=`pwd -P`



{
read install_directory
read symlink_directory
} < "install_directories"



if [[ "_$1" = "_inplace" ]] || [[ -e "aas" ]] || [[ "$install_directory" = "!inplace" ]]; then
  install_acc/install_inplace.sh
  exit 0
fi



rsync -avz "$wd" "$install_directory"
rv=$?
echo "rsync rv = $rv"
if (( rv != 0 )); then
  echo "Error:  Bad rsync rv."
  echo
  exit 1
fi

base=`basename "$wd"`
cd "$install_directory/$base"


install_acc/install_inplace.sh





