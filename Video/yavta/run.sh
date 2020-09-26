echo ""
sudo dmesg -C 
sudo sh -c 'echo "3" >> /sys/class/video4linux/video0/dev_debug'
sudo sh -c 'echo "3" >> /sys/module/videobuf2_v4l2/parameters/debug'
sudo sh -c 'echo "3" >> /sys/module/videobuf2_core/parameters/debug'
./yavta -F /dev/video0 --caputure=10
./yavta -l --enum-inputs --enum-formats /dev/video0
echo ""
echo ""
dmesg
