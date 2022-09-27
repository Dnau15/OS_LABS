cd week1
mkdir fol1
date
sleep 3
mkdir fol2
date
sleep 3
touch fol1/root.txt
date
sleep 3
touch fol2/home.txt
date
sleep 3
ls / | sort -M -r > fol1/root.txt
ls ~ | sort -M -r > fol2/home.txt
ls fol1
ls fol2
