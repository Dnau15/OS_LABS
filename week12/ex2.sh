echo "Dima" > ../week01/file.txt
# inode of file.txt
inode=$(ls -i ../week01/file.txt | cut -d " " -f1)

# remove _ex2.txt if it already exists
rm -f _ex2.txt

link ../week01/file.txt _ex2.txt
find . -inum $inode > ex2.txt
find . -inum $inode -exec rm {} \; >> ex2.txt
