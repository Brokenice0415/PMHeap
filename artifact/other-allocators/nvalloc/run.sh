#!/bin/bash

source ../../common.sh

SO_FILE=$(pwd)/libnvalloc.a
if [ ! -e $SO_FILE ]; then

  make_input
fi

AFL_PRELOAD=$SO_FILE run_all