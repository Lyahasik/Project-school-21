mkdir -p Build
cd Build || exit
cmake ..
make -j 6
