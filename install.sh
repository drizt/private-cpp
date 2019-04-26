#!/bin/sh

dir=$HOME/.config/QtProject/qtcreator/qtcreator/wizards/classes/private-cpp

[ -d $dir ] && rm -fr $dir
mkdir -p $dir
cp file.cpp file.h file_p.h wizard.json $dir
