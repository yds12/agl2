sudo mkdir /usr/include/agl/
sudo cp -Rap *.h /usr/include/agl/
make agl
sudo cp -Rap ../lib/*.so /usr/lib/
make graphics
make text
make mapping
make motion
make net
sudo cp -Rap ../lib/*.so /usr/lib/
make forms
sudo cp -Rap ../lib/*.so /usr/lib/
