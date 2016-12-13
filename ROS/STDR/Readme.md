# STDR - Simple Two Dimensional Robot Simulator

http://stdr-simulator-ros-pkg.github.io/

https://github.com/stdr-simulator-ros-pkg

Start simulator with command:

roslaunch stdr_launchers server_with_map_and_gui_plus_robot.launch

Then start the application with

roscore
python listener.py

//Then start the keyboard operator with:
//rosrun teleop_twist_keyboard teleop_twist_keyboard.py cmd_vel:=robot0/cmd_vel

#Troubleshooting

##### Get the error "Could not spawn robot. Robot didn't respond within time or registered with incorrect name" when trying to add robot in GUI.
This is a bug with the compiled versionin apt-get. You need to install STDR again, but this time from GIT.

See: http://wiki.ros.org/stdr_simulator/Tutorials/Set%20up%20STDR%20Simulator

Also make sure you source devel/setup.sh afterwards.
