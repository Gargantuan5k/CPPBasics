#!/bin/bash
wd="$(readlink -f `dirname "$0"`)"

for dir in $(readlink -f $(find $wd -maxdepth 1 -mindepth 1 -name "Section*")); do 
    mkdir -p $dir/bin/linux
    for file in $(find $dir -maxdepth 1 -mindepth 1 -name "*.cpp"); do
        g++ $(readlink -f $file) -o "$dir/bin/linux/$(basename $file .cpp)"
    done
done
echo "\033[0;34mCompiled all .cpp files inside all Section directories (not in subdirectories)\033[0m"