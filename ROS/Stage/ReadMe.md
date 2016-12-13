## Using Player/Stage to simulate

These files are used by Player/Stage to run robot simulation.

### Install

On Ubuntu 16.04 install ROS using ´´´sudo apt-get install ros-kinetic-desktop-full´´´. That should also bring in the ros-kinetic-stage application.

You _might_ need to add this to ~.bashrc

export LD_LIBRARY_PATH=/usr/local/lib64:$LD_LIBRARY_PATH}
export PKG_CONFIG_PATH=/usr/local/lib64/pkgconfig:$PKG_CONFIG_PATH}

Then start simulation by running

´´´stage gothenburg.world´´´

NB - I was unable to get Player working on Ubuntu 16.04. I tried downloading the current snapshot from https://sourceforge.net/p/playerstage/svn/HEAD/tree/, and built it, but never managed to get everything working.

### Links
http://rtv.github.io/Stage/
and
http://playerstage.sourceforge.net/index.php?src=stage
and
http://player-stage-manual.readthedocs.io/

http://askubuntu.com/questions/859110/install-package-robot-player-on-ubuntu-16-04

http://answers.ros.org/question/249570/gazebo-or-rviz/

https://discourse.ros.org/t/using-ros-for-simulating-autonomous-rc-cars/924
