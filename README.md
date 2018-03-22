# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

#  Writeup for Udacity SDC Term 2 PID Controller Project 4

---



#**Rubic points**


##PROJECT SPECIFICATION
#PID Controller

#Compilation

####CRITERIA
####MEETS SPECIFICATIONS
Requirement:  Your code should compile.

Reflection/Response:  Code compiles without errors with cmake and make.

No modifications were made to CMakeLists.txt to ensure that project can compile on any platform.

#Implementation

####CRITERIA
####MEETS SPECIFICATIONS
Requirement:  The PID procedure follows what was taught in the lessons.

Reflection/Response:  

First, I implemented the PID Controller algorithm presented in the lessons.  I tuned the hyperparameters until the car could drive around the track successfully.  I paid attention to where the car was steering incorrectly and adjusted the P component coefficients in order for the car to steer  


#Reflection

####CRITERIA
####MEETS SPECIFICATIONS

Requirement:  Describe the effect each of the P, I, D components had in your implementation.




Student describes the effect of the P, I, D component of the PID algorithm in their implementation. Is it what you expected?


#Reflection/Response:

###1.  P = Proportional 
The P component of the PID controller controls how much the car will steer in proportion to the cross-track error (CTE).  The P component of the PID Controller controls how quickly to turn the steering when the heading is not at the set value.

The cross-track error measures how far from the middle line of the road the car is. The higher the CTE, the farther off from the middle of the road the car is and the car must correct itself by steering back to the middle of the road.  

If the P is too low, this will lead to slow "reaction time" and the car cannot handle sharp curves because it reacts too slowly and does not steer aggressively back to the center when it is turning around sharp curves.

Setting a higher P will give a faster response.  If the P is set optimally, then the steering correction will happen fast and smoothly to bring the car back to the middle.
However, if the P term is too high, then the car will constantly try to correct to get back to the middle.  This will result in overshooting and oscillations. However, if the P coefficient is too low, then the 



###2.  "I" = Integral 
The I component of the PID controller sums up all CTEs and is used to prevent biases where the car drives too long on one side of the road.  Let's say that the car has been driving on the right side of the road for a while,then the CTE is "+" and I (Integral) grows larger and larger over time because of the positive addition for CTE and requires "-" correction or steering to the left in order to prevent the I component from getting larger.  If the I coefficient is too low, then the car will tend to drift to one side of the road and stay on that side too long.  If the I coefficient is too high, the car will respond faster to drive back to the middle, but it also creates more oscillations and a more jarring driving experience.


###3. "D" = Differential
The D component of the PID controller stands for differential (derivative) and specifies how fast and aggressively the controller deals with rate of change. 
The D component is important for dampening P's overshooting and limiting the speed of the steering response when the rate of change is increasing, such as going around sharp curves.  



#Reflection

####CRITERIA
####MEETS SPECIFICATIONS
Visual aids are encouraged, i.e. record of a small video of the car in the simulator and describe what each component is set to.

Describe how the final hyperparameters were chosen.

#Reflection/Response:
I've recorded a small video of the car in the simulator.

Here is how I chose the initial and final hyper-parameters: (P, I, D coefficients).

I started by experimenting with different coefficients using manual tuning to get a feel of how each component affected the driving performance of the car.  For instance, I would set the P coefficient high while keeping the I and D coefficient low.  I observed the behavior of each component by itself, and increased the value until the car could make progress around the track without going off to the side.  Then, I combined all the components for PID controller. 

My approach was to start off with slow speed so that there was less rate of change.  The slower speed helped the car from having to constantly having to correct.

I then increased the Proportional setting, until the car made progress around the track without going off to the side of the road. I found that when I increased P too high that the car would constantly overshoot and weave back and forth. 

To dampen the steering overshooting, I added higher Derivative. I kept adding more P and D until the car stayed mostly on the road. However, I noticed that the car would steer towards the middle but was slow to get there. So then I kept increasing the I(ntegral) coefficient until the car started weaving and then I backed off I.  

 


----------------------------------------------



#Simulation

####CRITERIA
####MEETS SPECIFICATIONS
The vehicle must successfully drive a lap around the track.

#Reflection/Response:
I implemented PID controller so that the vehicle can successfully drive a lap around the track.
The car tires does not leave the drivable portion of the track surface or pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe for humans.

----------------
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).




