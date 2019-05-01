#!/bin/bash


# Gets called by ../install.sh and so runs in "../".


wd=`pwd -P`


{
read install_directory
read symlink_directory
} < "install_directories"



rm -f "aas"


{
while read line; do
  if [[ "$line" = "!INSTALL_LOCATION" ]]; then
    echo "install_dir=\"$wd\"" >> aas
  else
    echo "$line" >> aas
  fi
done
} < "install_acc/aas"

chmod +x aas

#################################
cd "$symlink_directory"
rv="$?"
if (( rv != 0 )); then
  echo "Error:  Couldn't cd into symlink_dir."
  echo "  symlink_dir = [$symlink_dir]"
  echo
  exit 1
fi
#################################



if [[ -e "prs-blobractor" ]]; then
  rm "prs-blobractor"
fi

ln -sf "$wd/aas" "prs-blobractor"














