sudo touch lofsdisk/file1
sudo touch lofsdisk/file2
sudo echo "Dmitrii" > sudo lofsdisk/file1
sudo echo "Naumov" > sudo lofsdisk/file2
sudo mkdir lofsdisk/bin
sudo mkdir lofsdisk/lib
sudo cp /bin/bash ./lofsdisk/bin/bash
bash_deps="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"
for i in $bash_deps; do sudo cp -v --parents "$i" "./lofsdisk"; done
gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk/ /bin/bash -c "./ex2.out > ex2.txt"
sudo sh -c "./ex2.out >> lofsdisk/ex2.txt"
