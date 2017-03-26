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
 ```p(X=x)``` where X is the discrete set of all possible values, and x  is a specific value. This is commonly abbreviated as p(x)
