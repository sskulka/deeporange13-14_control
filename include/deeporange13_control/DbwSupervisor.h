/*
 A class deifinition to allow the supervising of dbw control and communication ...
between multiple functional objects like VehicleModel and DeepOrangeDbwCan
*/


#ifndef _DBW_SUPERVISOR_H_
#define _DBW_SUPERVISOR_H_

#include <string.h>
#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <can_msgs/Frame.h>
#include <geometry_msgs/TwistStamped.h>
#include <nav_msgs/Odometry.h>
#include <deeporange13_msgs/RaptorState.h>
#include <deeporange13_msgs/RosState.h>

namespace deeporange_dbw_ros
{
    class DbwSupervisor
    {
        public:
        DbwSupervisor(ros::NodeHandle &node, ros::NodeHandle &priv_nh);
        ~DbwSupervisor();

        private:
        void synchronise(const geometry_msgs::TwistStamped::ConstPtr& msg);
        // void publish_estop(const ros::TimerEvent& event);
        ros::Timer timer_;

        // Publishers
        ros::Publisher pub_trackVel_;
        ros::Publisher pub_rosState_;
        ros::Publisher pub_estop_;
        // Subscribers
        ros::Subscriber sub_raptor_;
        ros::Subscriber sub_cmdVel_;

        nav_msgs::Odometry odometryMsg_;
        deeporange13_msgs::RaptorState raptorMsg_;
        deeporange13_msgs::RosState rosSupMsg_;

    };
}

#endif // _DBW_SUPERVISOR_H_