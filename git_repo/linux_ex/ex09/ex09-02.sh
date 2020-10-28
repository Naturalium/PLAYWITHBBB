#!/bin/bash





file_name1="fifo_jy1"
file_name2="fifo_jy2"

if [ -p $file_name1 -a -p $file_name2 ]; then
  echo "write on the board fifo2"
  echo "press ^c to exit"
  cat < $file_name2 &
  cat > $file_name1
else
  echo "no pipe!"
  echo "type mkfifo fifo_jy1 & fifo_jy2"
fi
