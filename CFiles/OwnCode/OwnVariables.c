/* Already implemented Variables
#Changable
x : x position of the robot
y : y postion of the robot
phi : orientation of the robot
x0 : initial x position
y0 : initial y position
xg : goal x position
yg : goal y position
#Inchangeable
left : left control value
right : right control value
*/
#define ROTATION 0
#define TRANSLATION 1
#define STOP 2

//initialize the Controller
int control_type = ROTATION;

// The desired angle
double theta_R = 0.0;

// Sampling time
double h = 0.000001;

// v (input to translate) and w (input to rotate)
double w = 0.0;
double v = 0.0;

//Rotation Proportional Controller (Task 6)
double r_K_psi_min = 0.0;
double r_K_psi_max = 2.0 * L_true / (R_true * h);
double r_K_psi = r_K_psi_max * 0.00002;


//Rotation Proportional Controller (Task 8)
double r_K_omega_min = 0.0 ;
double r_K_omega_max = 2 / (R_true * h);
double r_K_omega = r_K_omega_max * 0.00000001;

//translation Proportional controller (Task 10)
double t_K_omega_min = 0.0 ;
double t_K_omega_max = 2 / (R_true * h);
double t_K_omega = t_K_omega_max * 0.000000003;

//translation proportional controller (Task 14)
double p = 10 ; // the design parameter 50
double t_K_psi_min = 0.0 ;
double t_K_psi_max = 2 * L_true / (h*p*R_true);
double t_K_psi = t_K_psi_max *0.000005;
