echo 'Compilation for' $0 'started'
sudo g++ ./src/main.cpp ./src/shader.h ./src/vendor/glad.c -ldl -lglfw
echo $0 'compiled successfully'
./a.out