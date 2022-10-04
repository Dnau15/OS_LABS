gcc channel.c -o ch.out
gcc publisher.c -o pub.out
gcc subscriber.c -o sub.out

rm -f /tmp/ex1 

./ch.out $1
