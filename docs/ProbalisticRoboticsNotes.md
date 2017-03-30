# Notes from Probabilistic Robotics book
Book authors: Sebastian Thrun, Wolfram Burgard, Dieter Fox

Notes: Frode Lillerud, march/april 2017

# Chap 1 - Basics

### 1.3
Probabilistic robotics tend to be more robust than model-based motion planning techniques or reactive behavior-based approaches.

(My Arduino based folkracer is mostly "reactive behavior based", since it just reacts to the IR sensor inputs.)

Probabilistic robotics is have weaker requirements on the accuracy of the robot's model, and the accuracy of the sensors.

Two disadvantages are that PR have a higher *computational complexity*, and there is *a need to approximate*.

# Chap 2 - Recursive State Estimation

### 2.1

At the core of PR is the idea of *estimating state from sensor data*. State estimation seeks to recover state variables from the data.

### 2.2
``p(X=x)`` where X is the discrete set of all possible values, and x  is a specific value. This is commonly abbreviated as p(x).

#### 2.3.1 - State

State is denoted by ``x``, and ``xt`` is the state at time t.

Pose: Location and orientation relative to a global coordinate frame. Pose includes variables for the *configuration of the robots actuators*.

Robot *velocity* and *the joints velocities* are commonly referred to as *dynamic state*.

#### 2.3.2 - Environment Interaction

*Environment measurement data* is information gathered via cameras, sensors, etc.

*Control data* can be *velocity*.

Measurement and control; Measurement gives the robot MORE information about the environment, while control (moving actuators etc.) leaves the robot with LESS information about the environment.
