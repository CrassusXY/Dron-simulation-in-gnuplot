TRGDIR=./
OBJ=./obj
CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc

__start__: DragonFly.out
	./DragonFly.out

DragonFly.out: ${OBJ} ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/main.o ${OBJ}/Matrix.o ${OBJ}/Vector.o ${OBJ}/Surface.o ${OBJ}/Cuboid.o ${OBJ}/HexaPrism.o ${OBJ}/Drone.o ${OBJ}/Hill.o ${OBJ}/Plateau.o ${OBJ}/RectaPlateau.o ${OBJ}/Scene.o
	g++ -o DragonFly.out ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Matrix.o ${OBJ}/Vector.o  ${OBJ}/Surface.o ${OBJ}/Cuboid.o ${OBJ}/HexaPrism.o ${OBJ}/Drone.o ${OBJ}/Hill.o ${OBJ}/Plateau.o ${OBJ}/RectaPlateau.o ${OBJ}/Scene.o -lpthread

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/RectaPlateau.hh
	g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

${OBJ}/Matrix.o: src/Matrix.cpp inc/Matrix.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Matrix.o src/Matrix.cpp

${OBJ}/Vector.o: src/Vector.cpp inc/Vector.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Vector.o src/Vector.cpp

${OBJ}/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Cuboid.o src/Cuboid.cpp

${OBJ}/HexaPrism.o: src/HexaPrism.cpp inc/HexaPrism.hh
	g++ ${CPPFLAGS} -o ${OBJ}/HexaPrism.o src/HexaPrism.cpp

${OBJ}/Drone.o: src/Drone.cpp inc/Drone.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Drone.o src/Drone.cpp

${OBJ}/Surface.o: src/Surface.cpp inc/Surface.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Surface.o src/Surface.cpp

${OBJ}/Hill.o: src/Hill.cpp inc/Hill.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Hill.o src/Hill.cpp

${OBJ}/Plateau.o: src/Plateau.cpp inc/Plateau.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Plateau.o src/Plateau.cpp

${OBJ}/RectaPlateau.o: src/RectaPlateau.cpp inc/RectaPlateau.hh
	g++ ${CPPFLAGS} -o ${OBJ}/RectaPlateau.o src/RectaPlateau.cpp

${OBJ}/Scene.o: src/Scene.cpp inc/Scene.hh
	g++ ${CPPFLAGS} -o ${OBJ}/Scene.o src/Scene.cpp
clear:
	rm -f DragonFly.out ${OBJ}
