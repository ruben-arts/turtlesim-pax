#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class SquareDrawer : public rclcpp::Node
{
public:
  SquareDrawer() : Node("square_drawer"), count_(0)
  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&SquareDrawer::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto msg = geometry_msgs::msg::Twist();
    if (count_ % 4 == 0)
    {
      msg.angular.z = 0.0;
      msg.linear.x = 2.0;
    }
    else
    {
      msg.angular.z = 1.57; // 90 degrees in radians
      msg.linear.x = 0.0;
    }
    publisher_->publish(msg);
    count_++;
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t count_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SquareDrawer>());
  rclcpp::shutdown();
  return 0;
}
