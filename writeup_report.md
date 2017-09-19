
# **PID Control** 

## Writeup

---

**PID Control Project**

The steps in developing this project are the following:
* Initially PID controller is implemented.
* Then the parameters are tuned manually to go around the loop.
* Use twiddle for auto tuning of parameters.
* Check if it works else tune parameters manually.
* Add a logic for speed control

### Files Submitted & Implementation Details

#### 1. Submission includes all required files 

My project includes the following files:
* src/main.cpp implemnted the PID usage
* src/PID.cpp implements error calculation and twiddling functionality.
* src/PID.h has declarations of various parameters used in PID implementation

#### 2. Implementation Details and Parameter Tuning

The controller used is PID, how the different terms affect the performance are described below:
* P term: It affects the rate of turn for the error, an appropriat value is needed for the vehicle to turn when ever needed else it will fall outside. Higher P value leads to further oscillations in driving. 
* I term: It affects any bias. If there is a bias in sensor values then this term helps to tune it. In current project it doesent seem to have a higher significance. 
* D term: It dampens the oscillations caused by P term. In the project the term has negative impact while driving straight. It was leading to further oscillations but a reduced/increased D term was causing the system out of control. 

For tuning the parameters initially I tried manually and got a basic run complete then used twiddle to fine tune the parameters. I observed that twiddle was deteriorating the performance further. I assume this is because the tract is not uniform and the twiddle faces different error rates everytime and the parameters tuned in straight line were different from the parameters tuned in corners. I felt all the parameters were tending to their lowest using twiddle. 

As the twiddle idea did not turnout to be good, I tried tuning parameters manually. The main challenge I fekt is that some parameters worked will in corners and some worked great in straight lines. It was tough to create parameters which are working good in all conditions. I finally tried to adjust the throttle based on the current cross track error and steering values and it seemed to have a good impact. 

The final video is (result_video.mp4)[./result_video.mp4].

