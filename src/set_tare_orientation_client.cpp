#include "ros/ros.h"
#include "microstrain_3dm/SetTareOrientation.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "set_tare_orientation_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<microstrain_3dm::SetTareOrientation>("SetTareOrientation");
  microstrain_3dm::SetTareOrientation srv;

  srv.request.axis= atoll(argv[1]);

  if (client.call(srv))
  {
      if (srv.response.success)
      {
        ROS_INFO("success");
      }
  }
  else
  {
    ROS_INFO("Failed to call service");
  }
  return 0;
}
