gcc ex3.c -o ex3
./ex3 3 &
pstree $$
sleep 3
pstree $$
sleep 3
pstree $$
sleep 3

./ex3 5 &

for i in `seq 10`
do
    pstree $$
    sleep 3
done
