echo 'Compilation for' $0 'started'
sudo g++ ./src/main.cpp glad.c -ldl -lglfw
echo $0 'compiled successfully'
./a.out
rm ./a.out