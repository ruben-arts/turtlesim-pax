import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class CircleMover(Node):
    def __init__(self):
        super().__init__('circle_mover')
        self.publisher_ = self.create_publisher(Twist, 'turtle1/cmd_vel', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.callback)
        self.v = 0

    def callback(self):
        if self.v < 4.0:
            self.v += 0.1
        msg = Twist()
        msg.linear.x = self.v  # Speed value
        msg.angular.z = 2.0  # Turn value
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)

    circle_mover = CircleMover()

    try:
        rclpy.spin(circle_mover)
    except KeyboardInterrupt:
        circle_mover.get_logger().info('Stopping node...')
    finally:
        # Destroy the node explicitly
        circle_mover.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
