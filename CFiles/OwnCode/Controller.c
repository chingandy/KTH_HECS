// theta_R = atan2( yg-y0, xg-x0 ) * 180 / PI;
//
//
//
//   u_difference = r_K_psi * (theta_R - theta);
//
//   u_average =  r_K_omega *(cos(theta * PI / 180) * (x0 - x) + sin(theta * PI / 180) * (y0 - y));


switch ( control_type )
{
  case ROTATION:

    // the desired angle
    theta_R = atan2( yg-y0, xg-x0 ) * 180 / PI;

    if ( theta != theta_R )
    {

      w = r_K_psi * (theta_R - theta);

      v = r_K_omega *
        (cos(theta * PI / 180) * (x0 - x) + sin(theta * PI / 180) * (y0 - y));
    }
    else
    {
      u_psi = 0;
      u_omega = 0;
      control_type = TRANSLATION;
    }
    break;

  case TRANSLATION:
    if ( fabs(
        cos(theta_R * PI / 180) * (xg - x) + sin(theta_R * PI / 180) * (yg - y))
      > distance_tolerance )
    {
      u_omega = t_K_omega *
        (cos(theta_R * PI / 180) * (xg-x) + sin(theta_R * PI / 180) * (yg-y));

      u_psi = t_K_psi *
        (sin(theta_R * PI / 180) * (x + t_p * cos(theta * PI / 180) - x0)
         - cos(theta_R * PI / 180) * (y + t_p * sin(theta * PI / 180) - y0));
    }
    else
    {
      u_psi = 0;
      u_omega = 0;
      control_strategy = STOP_CONTROL;
    }
    break;

  case STOP:

    u_psi = 0;
    u_omega = 0;
    break;

}
right = u_average + 0.5 * u_difference;
left = u_average - 0.5 * u_difference;
