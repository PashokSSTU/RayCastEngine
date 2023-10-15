if not exist raylib\ (
    git clone https://github.com/raysan5/raylib.git
    @echo Clonning raylib library
)

cd raylib 

if not exist build-win\ (
    cmake -DBUILD_SHARED_LIBS=ON -B ./build-win -G Ninja
    cd build-win
    ninja
    @echo Building raylib library
    cd ../../
) else (
    cd ../
)

cmake  -B ./build-win -G Ninja .
cd build-win
ninja