#!/bin/bash
# $Id: mk,v 1.15 2022-03-21 13:34:13-07 - - $
pkill gv
cid $0 lab0-intro-unix.mm countwords.perl
make

touch *-version
for dir in */countwords.d
do
   pushd $dir
   make ci
   make
   make tar
   make lis
   popd
done

