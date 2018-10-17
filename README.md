Note: This is my personal fork, where I changed the clock size in the status bar to be much bigger.  I want my pebble to show the time even when it shows a notification, too.

# Installation instructions

cd /h/software/pebble-sdk
tar -jxf pebble-sdk-4.5-linux64.tar.bz2
sudo apt-get install python-pip python2.7-dev
sudo pip install virtualenv
cd pebble-sdk-4.5-linux64
virtualenv --no-site-packages .env
source .env/bin/activate
pip install -r requirements.txt
deactivate

/h/software/pebble-sdk/pebble-sdk-4.5-linux64/bin/pebble sdk install https://github.com/aveao/PebbleArchive/raw/master/SDKCores/sdk-core-4.3.tar.bz2
sudo apt-get install libc6-dev-i386


# Building

make build, then copy build/*.pbw


PebbleNotificationCenter-Watchapp
=================================

Watchapp part of the Notification center for Pebble

Phone counterpart (with issue tracker): https://github.com/matejdro/PebbleNotificationCenter-Android    
Appstore entry: https://apps.getpebble.com/en_US/application/531c8f3646b8f200dd00018d    
Discussion forums: https://plus.google.com/communities/116982109550451242571    
