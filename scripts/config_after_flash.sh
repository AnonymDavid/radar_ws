#!/bin/bash

sudo apt-get update

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt install curl -y
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo apt-get update
sudo apt install ros-melodic-desktop-full -y
sudo apt autoremove -y
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential -y
sudo rosdep init
sudo rosdep fix-permissions
rosdep update

sudo apt-get install ros-melodic-catkin -y
#sudo apt-get install python3-catkin-tools -y

apt-get install python-catkin-tools -y

sudo apt-get install can-utils -y

# Jetson fan configuration (FONTOS: kell hozzá git - sudo apt-get install git)
# További infók: https://github.com/Pyrestone/jetson-fan-ctl
# Hőmérséklet beállításhoz: sudo vi /etc/automagic-fan/config.json
# i - szerkesztés
# esc - kilépés szerkesztésből
# :wq - esc után kell beírni, mentés
# utána futtatni kell a sudo service automagic-fan restart parancsot, hogy újrainduljon a rendszer
cd ~/Downloads
git clone https://github.com/Pyrestone/jetson-fan-ctl.git
cd jetson-fan-ctl
sudo ./install.sh

# Jetpack  4.2.1 telepitése esetén a következő parancsot is futtatni kell!
# sudo apt-get install python3-catkin-tools

# Amennyiben a catkin build parancs kiadása után nem akar buildelni egy packeget sem,
# akkor a következő parancsot kell futtatni:
# source /opt/ros/melodic/setup.bash

# Jetson TX2 drive:
# https://drive.google.com/drive/u/0/folders/1sQsHwyEITcJF3i213fPAqgnhQGdsDK3w