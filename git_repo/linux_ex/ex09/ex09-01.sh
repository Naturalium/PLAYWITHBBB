#!/bin/bash

echo "this is example"

if [ -p $file_name ]; then
  echo ^d to exit
  cat < fifo_jy &
  cat > fifo_jy
else
  echo "file not exist!!"
  echo "type mkfifo fifo_jy"
  exit 0
fi
