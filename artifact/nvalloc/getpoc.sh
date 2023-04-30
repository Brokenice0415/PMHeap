#!/bin/bash

# rm -rf poc
# mkdir poc

# for crash in `ls output/crashes | grep -v README`
# do
#     echo $crash
#     ../../driver/bin/driver output/crashes/$crash 2> poc/$crash.c
# done

rm -rf poc minimized_output*
mkdir poc
mkdir poc/AC poc/OC poc/AW poc/RW

for choice in "AC" "OC" "AW" "RW"
do
    # echo $choice
    mkdir minimized_output-$choice
    if [ "$choice" == "AC" ]; then
    SPEC="-e OVERLAP \
        -e RESTRICTED_WRITE_IN_CONTAINER -e RESTRICTED_WRITE_IN_BUFFER \
        -e ARBITRARY_WRITE_IN_CONTAINER -e ARBITRARY_WRITE_IN_BUFFER"
    elif [ "$choice" == "OC" ]; then
    SPEC="-e RESTRICTED_WRITE_IN_CONTAINER -e RESTRICTED_WRITE_IN_BUFFER \
        -e ARBITRARY_WRITE_IN_CONTAINER -e ARBITRARY_WRITE_IN_BUFFER \
        -e ALLOC_IN_CONTAINER -e ALLOC_IN_BUFFER"
    elif [ "$choice" == "AW" ]; then
    SPEC="-e OVERLAP \
        -e ARBITRARY_WRITE_IN_CONTAINER -e ARBITRARY_WRITE_IN_BUFFER \
        -e ALLOC_IN_CONTAINER -e ALLOC_IN_BUFFER"
    else 
    SPEC="-e OVERLAP \
        -e RESTRICTED_WRITE_IN_CONTAINER -e RESTRICTED_WRITE_IN_BUFFER \
        -e ALLOC_IN_CONTAINER -e ALLOC_IN_BUFFER"
    fi
    for crash in `ls output-$choice/crashes | grep -v README`
    do
        # echo $crash
        ../../driver/minimize.py minimized_output-$choice/$crash -- ../../driver/bin/driver $SPEC $(pwd)/output-$choice/crashes/$crash  2> /dev/null
    done
    for crash in `ls minimized_output-$choice`
    do
        ../../driver/bin/driver $SPEC output-$choice/crashes/$crash minimized_output-$choice/$crash 2> poc/$choice/$crash.c
    done
done