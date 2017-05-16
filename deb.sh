#!/bin/bash

# Deb Package Generation Script
# 
# Place all files correctly in the deb directory,
# update deb/DEBIAN/control file,
# then run this script to pack it into a deb package.

cp -R deb deb_temp
sudo chmod 6775 -R deb_temp
sudo chmod a-s -R deb_temp/DEBIAN
sudo chown root: -R deb_temp
find deb_temp -name ".svn" -type d | xargs sudo rm -rf
dpkg -b deb_temp .
sudo rm -rf deb_temp
