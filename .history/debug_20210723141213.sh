echo 'Compilation for' $0 'started'
sudo g++ main.cpp glad.c -ldl -lglfw
echo $0 'compiled successfully'
./a.out
