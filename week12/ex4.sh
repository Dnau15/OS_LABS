rm -fr tmp
mkdir tmp

touch ./tmp/file1
touch ./tmp/file2

rm -f ./tmp/link1

ln ./tmp/file1 ./tmp/link1

rm -f ex4.txt

gcc ex4.c -o ex4.out
./ex4.out 
