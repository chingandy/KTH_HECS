// the desired angle
theta_R = atan2( yg-y0, xg-x0 ) *180/PI;
// control flow
switch(control_type){
  case ROTATION:
      Serial.print("the rotation control start!\n");

      if ( fabs(theta_true - theta_R) >  1 ) // set the tolerance in order to move on
      {

            w = r_K_psi * (theta_R*PI/180 - theta_true*PI/180);

            v = r_K_omega * (cos(theta_true*PI/180)*(x0 - x)+ sin(theta_true*PI/180)*(y0 - y));
      }
      else
      {
            control_type = TRANSLATION;
      }
  break;
  case TRANSLATION:
      Serial.print("the translation control start!\n");

      if ( fabs(x - xg)+fabs(y - yg) > 0.8 )

      {

            w = t_K_psi*(sin(theta_R*PI/180)*(x + p*cos(theta_true*PI/180)-x0) - cos(theta_R*PI/180)*(y + p*sin(theta_true*PI/180) - y0)) ;

            v = t_K_omega * (cos(theta_R*PI/180)*(xg - x)+ sin(theta_R*PI/180)*(yg - y));

      }
      else
      {

            control_type = STOP;

      }
  break;
  case STOP:
        w = 0 ;
        v = 0 ;
        Serial.print("STOP\n");
        send_done();
  break;

}


right = v + 0.5 * w;
left = v- 0.5 * w;
