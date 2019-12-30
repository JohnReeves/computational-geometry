clear 
echo '+------------------+'
cal
echo '+------------------+'
date +'%d/%m/%Y %H:%M:%S'
echo '+------------------+'
echo

# gcc -o sample sample.c
# including any other gcc flags you like
# ./path-to-sample/sample

art_gallery=$PWD/"01 Polygon Triangulation/01 Art Gallery Theorems"

echo "building: "
echo '+------------------+'
echo "hello.c"
echo '+------------------+'
echo "binaries in ./Results"
echo '+------------------+'

gcc "$art_gallery/"hello.c -o ./Results/hello
#./Results/gcd
