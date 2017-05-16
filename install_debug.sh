sudo mkdir /usr/include/agl/
sudo cp -Rap *.h /usr/include/agl/
make debug
sudo cp -Rap ../lib/*.so /usr/lib/
