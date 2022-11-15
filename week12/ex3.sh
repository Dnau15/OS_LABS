echo "Dimas" > _ex3.txt
chmod -x _ex3.txt && ls -l _ex3.txt > ex3.txt
chmod u=rwx,o=rwx,g=--- _ex3.txt && ls -l _ex3.txt >> ex3.txt
chmod -R g=u _ex3.txt && ls -l _ex3.txt >> ex3.txt

echo "660 owner and group members can write and read the file, others cannot" >> ex3.txt
echo "775 owner can read, write and execute the file, group members and others can just read and execute the file" >> ex3.txt
echo "777 all can read, write and execute the file" >> ex3.txt
