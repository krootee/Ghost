## Using Player/Stage to simulate

These files are used by Player/Stage to run robot simulation.

### Install

On Ubuntu 16.04 install ROS using ´´´sudo apt-get install ros-kinetic-desktop-full´´´. That should also bring in the ros-kinetic-stage application.

You _might_ need to add this to ~.bashrc

export LD_LIBRARY_PATH=/usr/local/lib64:$LD_LIBRARY_PATH}
export PKG_CONFIG_PATH=/usr/local/lib64/pkgconfig:$PKG_CONFIG_PATH}

Then start simulation by running

´´´stage gothenburg.world´´´

### Links
http://rtv.github.io/Stage/
and
http://playerstage.sourceforge.net/index.php?src=stage
and
http://player-stage-manual.readthedocs.io/
