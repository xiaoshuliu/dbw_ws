/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2015-2017, Dataspeed Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Dataspeed Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#include "Demo.h"

namespace main_demo
{

Demo::Demo(ros::NodeHandle &node, ros::NodeHandle &priv_nh) : counter_(0)
{

  ignore_ = false;
  enable_ = false;
  count_ = false;
  priv_nh.getParam("ignore", ignore_);
  priv_nh.getParam("enable", enable_);
  priv_nh.getParam("count", count_);

  sub_enable_ = node.subscribe("dbw_enabled", 1, &Demo::recvEnable, this);
  sub = node.subscribe("v_control", 1000,  &Demo::chatterCallback,this);
  control_data_.brake_cmd = 0.0;
  control_data_.gear_cmd = dbw_mkz_msgs::Gear::NONE;
  control_data_.steering_joy = 0.0;
  control_data_.steering_mult = false;
  control_data_.throttle_joy = 0.0;
  control_data_.turn_signal_cmd = dbw_mkz_msgs::TurnSignal::NONE;
  control_data_.joy_throttle_valid = false;
  control_data_.joy_brake_valid = false;

  pub_throttle_ = node.advertise<dbw_mkz_msgs::ThrottleCmd>("throttle_cmd", 1);
  pub_brake_ = node.advertise<dbw_mkz_msgs::BrakeCmd>("brake_cmd", 1);
  pub_turn_signal_ = node.advertise<dbw_mkz_msgs::TurnSignalCmd>("turn_signal_cmd", 1);
  pub_steering_ = node.advertise<dbw_mkz_msgs::SteeringCmd>("steering_cmd", 1);
  pub_gear_ = node.advertise<dbw_mkz_msgs::GearCmd>("gear_cmd", 1);
  if (enable_) {
    pub_enable_ = node.advertise<std_msgs::Empty>("enable", 1);
    pub_disable_ = node.advertise<std_msgs::Empty>("disable", 1);
  }

  cmd_timer_ = node.createTimer(ros::Duration(0.02), &Demo::cmdCallback, this);
}

void Demo::cmdCallback(const ros::TimerEvent& event)
{
  // Optional watchdog counter
  if (count_) {
    counter_++;
  }

  // Throttle
  dbw_mkz_msgs::ThrottleCmd throttle_msg;
  throttle_msg.enable = true;
  throttle_msg.ignore = ignore_;
  throttle_msg.count = counter_;
  throttle_msg.pedal_cmd_type = dbw_mkz_msgs::ThrottleCmd::CMD_PERCENT;
  throttle_msg.pedal_cmd = control_data_.throttle_joy;
  pub_throttle_.publish(throttle_msg);

  // Brake
  dbw_mkz_msgs::BrakeCmd brake_msg;
  brake_msg.enable = true;
  brake_msg.ignore = ignore_;
  brake_msg.count = counter_;
  brake_msg.pedal_cmd_type = dbw_mkz_msgs::BrakeCmd::CMD_PERCENT;
  brake_msg.pedal_cmd = control_data_.brake_cmd;
  pub_brake_.publish(brake_msg);

  // Steering
  dbw_mkz_msgs::SteeringCmd steering_msg;
  steering_msg.enable = true;
  steering_msg.ignore = ignore_;
  steering_msg.count = counter_;
  steering_msg.steering_wheel_angle_cmd = 2;
  if (control_data_.steering_mult) {
    steering_msg.steering_wheel_angle_cmd *= 2.0;
  }
  pub_steering_.publish(steering_msg);

  // Gear
  if (control_data_.gear_cmd != dbw_mkz_msgs::Gear::NONE) {
    dbw_mkz_msgs::GearCmd gear_msg;
    gear_msg.cmd.gear = control_data_.gear_cmd;
    pub_gear_.publish(gear_msg);
  }

  // Turn signal
  dbw_mkz_msgs::TurnSignalCmd turn_signal_msg;
  turn_signal_msg.cmd.value = control_data_.turn_signal_cmd;
  pub_turn_signal_.publish(turn_signal_msg);
}

void Demo::recvEnable(const std_msgs::Bool::ConstPtr& msg)
{
}


void Demo::chatterCallback(const dbw_demo::control::ConstPtr& msg)
{

  control_data_.joy_throttle_valid = true;


  control_data_.joy_brake_valid = true;


  control_data_.throttle_joy = msg->throttle;


  control_data_.brake_cmd = msg->brake;

  control_data_.steering_joy = msg->steering;

  if(msg->gear_cmd == 1){
    control_data_.gear_cmd = dbw_mkz_msgs::Gear::PARK;
  }
  else if (msg->gear_cmd == 2){
    control_data_.gear_cmd = dbw_mkz_msgs::Gear::REVERSE;
  }
  else if (msg->gear_cmd == 3){
    control_data_.gear_cmd = dbw_mkz_msgs::Gear::DRIVE;
  }
  else if (msg->gear_cmd == 4){
    control_data_.gear_cmd = dbw_mkz_msgs::Gear::NEUTRAL;
  }
  else{
    control_data_.gear_cmd = dbw_mkz_msgs::Gear::NONE;
  }


  if(msg->turn_signal_cmd == -1){
    control_data_.turn_signal_cmd = dbw_mkz_msgs::TurnSignal::RIGHT;
  }
  else if (msg->turn_signal_cmd == 1){
    control_data_.turn_signal_cmd = dbw_mkz_msgs::TurnSignal::LEFT;
  }
  else {
    control_data_.turn_signal_cmd = dbw_mkz_msgs::TurnSignal::NONE;
  }
}



}
