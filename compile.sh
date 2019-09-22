echo "Build Started..."

gcc -Wno-int-to-void-pointer-cast *.c LinkedList/*.c -o build

echo "Build Completed..."