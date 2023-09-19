#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class CircleDrawer : public rclcpp::Node
{
public:
  CircleDrawer() : Node("circle_drawer")
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&CircleDrawer::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = geometry_msgs::msg::Twist();

    // Open-loop control to draw a circle
    msg.linear.x = 1.0;  // Linear speed
    msg.angular.z = 1.0; // Angular speed

    publisher_->publish(msg);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CircleDrawer>());
  rclcpp::shutdown();
  return 0;
}
