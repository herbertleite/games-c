CXX=i686-w64-mingw32-g++

SOURCE=final.cpp

LIBS= \
	-L./../WinBGIm \
	-lbgi \
	-lcomdlg32 \
	-lgdi32 \
	-lole32 \
	-loleaut32 \
	-luuid \
	-lwinmm \

INCLUDE=-I./../WinBGIm

OUTPUT="Battle Spaceship.exe"

CPPFLAGS=-static-libgcc -static-libstdc++

all:
	$(MAKE) --directory=../WinBGIm
	$(CXX) -o $(OUTPUT) $(CPPFLAGS) $(SOURCE) $(LIBS) $(INCLUDE)

clean:
	$(MAKE) --directory=../WinBGIm clean
	rm -rf $(OUTPUT)
