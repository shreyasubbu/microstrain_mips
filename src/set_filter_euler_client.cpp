#include "ros/ros.h"
#include "microstrain_3dm/SetFilterEuler.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "set_filter_euler_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<microstrain_3dm::SetFilterEuler>("SetFilterEuler");
  microstrain_3dm::SetFilterEuler srv;

  srv.request.angle.x = atoll(argv[1]);
  srv.request.angle.y = atoll(argv[2]);
  srv.request.angle.z = atoll(argv[3]);


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
