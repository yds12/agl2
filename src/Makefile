# Makefile

# Variables
Objs=game.o drawer.o filemanipulator.o format.o timer.o keyboard.o mouse.o ciphers.o font.o sound.o music.o joystick.o \
		vector2.o intvector2.o gameobject.o image.o animation.o floatrectangle.o soundinstance.o
Codes=game.cpp drawer.cpp filemanipulator.cpp format.cpp timer.cpp keyboard.cpp mouse.cpp ciphers.cpp font.cpp sound.cpp \
		music.cpp joystick.cpp vector2.cpp intvector2.cpp gameobject.cpp image.cpp animation.cpp floatrectangle.cpp \
		soundinstance.cpp
Headers=game.h support.h drawer.h filemanipulator.h format.h timer.h keyboard.h mouse.h ciphers.h font.h sound.h \
		music.h joystick.h vector2.h intvector2.h gameobject.h image.h animation.h floatrectangle.h
Libs=-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

# Build the AGL library
agl: $(Objs)
	g++ -shared -o ../lib/libagl.so $(Objs) $(Libs)

# Build the AGL library for debugging
agl_debug:
	g++ -fPIC -c -g game.cpp
	g++ -fPIC -c -g drawer.cpp
	g++ -fPIC -c -g filemanipulator.cpp
	g++ -fPIC -c -g format.cpp
	g++ -fPIC -c -g timer.cpp
	g++ -fPIC -c -g keyboard.cpp
	g++ -fPIC -c -g mouse.cpp
	g++ -fPIC -c -g ciphers.cpp
	g++ -fPIC -c -g font.cpp
	g++ -fPIC -c -g sound.cpp
	g++ -fPIC -c -g soundinstance.cpp
	g++ -fPIC -c -g music.cpp
	g++ -fPIC -c -g joystick.cpp
	g++ -fPIC -c -g vector2.cpp
	g++ -fPIC -c -g intvector2.cpp
	g++ -fPIC -c -g gameobject.cpp
	g++ -fPIC -c -g image.cpp
	g++ -fPIC -c -g animation.cpp
	g++ -fPIC -c -g floatrectangle.cpp
	g++ -shared -g -o ../lib/libagl.so $(Objs) $(Libs)

# Build the AGL library
forms: form.cpp formcomponent.cpp button.cpp textfield.cpp
	g++ -fPIC -c form.cpp
	g++ -fPIC -c formcomponent.cpp
	g++ -fPIC -c button.cpp
	g++ -fPIC -c textfield.cpp
	g++ -shared -o ../lib/libagl-forms.so form.o formcomponent.o button.o textfield.o -lSDL -lagl -lagl-graphics -lagl-text

# Build the AGL library for debugging
forms_debug: form.cpp formcomponent.cpp button.cpp textfield.cpp
	g++ -fPIC -g -c form.cpp
	g++ -fPIC -g -c formcomponent.cpp
	g++ -fPIC -g -c button.cpp
	g++ -fPIC -g -c textfield.cpp
	g++ -shared -g -o ../lib/libagl-forms.so form.o formcomponent.o button.o textfield.o -lSDL -lagl -lagl-graphics -lagl-text

# Build the AGL library
graphics: graphics.cpp graphics.h
	g++ -fPIC -O3 -c graphics.cpp
	g++ -shared -O3 -o ../lib/libagl-graphics.so graphics.o -lSDL -lagl

# Build the AGL library for debugging
graphics_debug: graphics.cpp graphics.h
	g++ -fPIC -g -c graphics.cpp
	g++ -shared -g -o ../lib/libagl-graphics.so graphics.o -lSDL -lagl

# Build the AGL library
mapping: map.cpp camera.cpp isometricmap.cpp ortogonalmap.cpp
	g++ -fPIC -c camera.cpp
	g++ -fPIC -c map.cpp
	g++ -fPIC -c isometricmap.cpp
	g++ -fPIC -c ortogonalmap.cpp	
	g++ -shared -o ../lib/libagl-mapping.so camera.o map.o isometricmap.o ortogonalmap.o -lSDL -lagl

# Build the AGL library for debugging
mapping_debug: map.cpp camera.cpp isometricmap.cpp ortogonalmap.cpp
	g++ -fPIC -g -c camera.cpp
	g++ -fPIC -g -c map.cpp
	g++ -fPIC -g -c isometricmap.cpp
	g++ -fPIC -g -c ortogonalmap.cpp	
	g++ -shared -g -o ../lib/libagl-mapping.so camera.o map.o isometricmap.o ortogonalmap.o -lSDL -lagl

# Build the AGL library
motion: physicalenvironment.cpp iphysicalobject.cpp movingobject.cpp ramp.cpp
	g++ -fPIC -c physicalenvironment.cpp
	g++ -fPIC -c iphysicalobject.cpp
	g++ -fPIC -c movingobject.cpp
	g++ -fPIC -c ramp.cpp
	g++ -shared -o ../lib/libagl-motion.so physicalenvironment.o iphysicalobject.o ramp.o movingobject.o -lSDL -lagl

# Build the AGL library for debugging
motion_debug: physicalenvironment.cpp iphysicalobject.cpp movingobject.cpp ramp.cpp
	g++ -fPIC -g -c physicalenvironment.cpp
	g++ -fPIC -g -c iphysicalobject.cpp
	g++ -fPIC -g -c movingobject.cpp
	g++ -fPIC -g -c ramp.cpp
	g++ -shared -g -o ../lib/libagl-motion.so physicalenvironment.o iphysicalobject.o ramp.o movingobject.o -lSDL -lagl

# Build the AGL library
net: net.cpp net.h
	g++ -fPIC -c net.cpp
	g++ -shared -o ../lib/libagl-net.so net.o -lSDL -lSDL_net -lagl

# Build the AGL library
net_debug: net.cpp net.h
	g++ -fPIC -c net.cpp
	g++ -shared -o ../lib/libagl-net.so net.o -lSDL -lSDL_net -lagl

# Build the AGL library
text: imagefont.cpp
	g++ -fPIC -O3 -c imagefont.cpp
	g++ -shared -O3 -o ../lib/libagl-text.so imagefont.o -lSDL -lagl

# Build the AGL library for debugging
text_debug: imagefont.cpp
	g++ -fPIC -g -c imagefont.cpp
	g++ -shared -g -o ../lib/libagl-text.so imagefont.o -lSDL -lagl

# Build the objects
game.o: game.cpp game.h
	g++ -fPIC -c game.cpp
drawer.o: drawer.cpp drawer.h
	g++ -fPIC -c drawer.cpp
filemanipulator.o: filemanipulator.cpp filemanipulator.h
	g++ -fPIC -c filemanipulator.cpp
format.o: format.cpp format.h
	g++ -fPIC -c format.cpp
timer.o: timer.cpp timer.h
	g++ -fPIC -c timer.cpp
keyboard.o: keyboard.cpp keyboard.h
	g++ -fPIC -c keyboard.cpp
mouse.o: mouse.cpp mouse.h
	g++ -fPIC -c mouse.cpp
ciphers.o: ciphers.cpp ciphers.h
	g++ -fPIC -c ciphers.cpp
font.o: font.cpp font.h
	g++ -fPIC -c font.cpp
sound.o: sound.cpp sound.h
	g++ -fPIC -c sound.cpp
soundinstance.o: soundinstance.cpp sound.h
	g++ -fPIC -c soundinstance.cpp
music.o: music.cpp music.h
	g++ -fPIC -c music.cpp
joystick.o: joystick.cpp joystick.h
	g++ -fPIC -c joystick.cpp
vector2.o: vector2.cpp vector2.h
	g++ -fPIC -c vector2.cpp
intvector2.o: intvector2.cpp intvector2.h
	g++ -fPIC -c intvector2.cpp
gameobject.o: gameobject.cpp gameobject.h
	g++ -fPIC -c gameobject.cpp	
image.o: image.h image.cpp
	g++ -fPIC -c image.cpp
animation.o: animation.cpp animation.h
	g++ -fPIC -c animation.cpp
floatrectangle.o: floatrectangle.cpp floatrectangle.h
	g++ -fPIC -c floatrectangle.cpp

# Build the test application
test: test.cpp
	g++ -fpermissive -g -o test test.cpp -lagl

# Install the AGL library (for debug) on the system
install_debug:
	sudo mkdir /usr/include/agl/
	sudo cp -Rap *.h /usr/include/agl/
	make agl_debug
	sudo cp -Rap ../lib/*.so /usr/lib/

# Install the AGL library on the system
install:
	sudo mkdir /usr/include/agl/
	sudo cp -Rap *.h /usr/include/agl/
	make agl
	sudo cp -Rap ../lib/*.so /usr/lib/

# Install the AGL library on the system
install:
	../install.sh

# Install the AGL library on the system
install_debug:
	../install_debug.sh

# Uninstall the AGL library to the system
remove:
	sudo rm -rf /usr/lib/libagl.so
	sudo rm -rf /usr/lib/libagl-forms.so
	sudo rm -rf /usr/lib/libagl-graphics.so
	sudo rm -rf /usr/lib/libagl-mapping.so
	sudo rm -rf /usr/lib/libagl-motion.so
	sudo rm -rf /usr/lib/libagl-net.so
	sudo rm -rf /usr/lib/libagl-text.so

# Generates the AGL documentation
doc:
	doxygen doxyfile

# Cleans the directories, removing executables and objects
clean:
	rm *.o test ../lib/*.so
