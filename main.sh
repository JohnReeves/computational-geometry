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
implementation=$PWD/"01 Polygon Triangulation/04 Implementation Issues"
intersection=$PWD/"01 Polygon Triangulation/05 Segment Intersection"

echo "building: "
echo '+------------------+'
echo "hello.c"
echo "list.c"
echo "polygon.c"
echo "intersection.c"
echo '+------------------+'
echo "binaries in ./Results"
echo '+------------------+'

gcc "$art_gallery/"hello.c -o ./Results/gallery_hello
gcc "$implementation/"list.c -o ./Results/list
gcc "$implementation/"polygon.c -o ./Results/polygon
gcc "$intersection/"intersection.c -o ./Results/intersection
#./Results/gcd
