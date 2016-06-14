BOOST_INSTALL=/project/boost
BOOST_LIB=-L$(BOOST_INSTALL)/lib
BOOST_INCLUDE=$(BOOST_INSTALL)/include
INCLUDES = -Iinclude -I$(BOOST_INCLUDE)

OPTS = -g
LIBS = -lGL -lglut -lm /usr/lib64/libGL.so.1
ARCH := $(shell uname)
ifeq ($(ARCH), Linux)
else
 MACOSX_DEFINE = -DMACOSX -I/sw/include
 LIBS = -I/usr/common/include -I/usr/include/GL -L/sw/lib -L/System/Library/Frameworks/OpenGL.framework/Libraries -framework GLUT -framework OpenGL -lGL -lm -lobjc -lstdc++

endif

all:  texture.o Graphic.o Enemy.o EnemyManager.o Tile.o SearchManager.o Tower.o TowerManager.o Shot.o GraphicsManager.o Particle.o MoneyManager.o GameManager.o Driver.o Driver

Tile.o: Tile.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Tile.cpp

texture.o: texture.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c texture.cpp 

Particle.o: texture.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Particle.cpp 

Graphic.o: Graphic.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Graphic.cpp $(INCLUDES)

Shot.o: Shot.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Shot.cpp $(INCLUDES)

SearchManager.o: SearchManager.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c SearchManager.cpp

GraphicsManager.o: GraphicsManager.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c GraphicsManager.cpp $(INCLUDES)

MoneyManager.o: MoneyManager.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c MoneyManager.cpp 

Enemy.o: Enemy.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Enemy.cpp $(INCLUDES)

EnemyManager.o: EnemyManager.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c EnemyManager.cpp 

Tower.o: Tower.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c Tower.cpp 

TowerManager.o: TowerManager.cpp
	g++ $(OPTS) $(MACOSX_DEFINE) -c TowerManager.cpp

GameManager.o: GameManager.cpp GraphicsManager.o
	g++ $(OPTS) $(MACOSX_DEFINE) -c GameManager.cpp $(INCLUDES)

Driver.o: 
	g++ $(OPTS) -c Driver.cpp $(INCLUDES)

Driver: Driver.o GameManager.o GraphicsManager.o
	g++ $(OPTS) -o Driver texture.o Graphic.o SearchManager.o Enemy.o EnemyManager.o Tile.o Tower.o Shot.o MoneyManager.o  TowerManager.o Particle.o GraphicsManager.o GameManager.o  Driver.o $(LIBS) $(INCLUDES)


clean:
	rm -f *.o Driver
