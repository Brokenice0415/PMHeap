#!/bin/bash

while true
do
    sudo rm -r /pmem/nv_dir 2> /dev/null
    sudo mkdir /pmem/nv_dir 2> /dev/null
    sleep 8
done