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

//Controller type
int control_type = ROTATION;

// The desired angle
double theta_R = 0.0;

// The robot cannot (in general) be rotated *exactly* theta_R degrees
/*double angle_tolerance = 6;*/
double angle_tolerance = 2.0;

// The robot cannot (in general) be translated *exactly* to the goal (cm)
/*double distance_tolerance = 20;*/
double distance_tolerance = 1.0;

// Sampling time
double h = 1.0;

// v (input to translate) and w (input to rotate)
double w = 0.0;
double v = 0.0;

// Part I of Rotation Control
double r_K_psi_min = 0.0;
double r_K_psi_max = 2.0 * L_true / (R_true * Ts);
double r_K_psi = r_K_psi_max * 0.1;

// Part II of Rotation Control
double r_K_omega_min = 0.0;
double r_K_omega_max = 2.0 / (R_true * h);
double r_K_omega = r_K_omega_max * 0.5;

// Part II of Line Following Control
double t_p = 40.0;
double t_K_psi_min = -2.0 * L_true / (t_p * h * R_true);
double t_K_psi_max = 0.0;
double t_K_psi = t_K_psi_min * 0.5;

// Part I of Line Following Control
double t_K_omega_min = 0.0;
double t_K_omega_max = 2.0 / (R_true * h);
double t_K_omega = t_K_omega_max * 0.1;
