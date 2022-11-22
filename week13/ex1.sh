fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs -t ext4 lofs.img
mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk/
