#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

class RobotSubscriber : public rclcpp::Node {
public:
    RobotSubscriber()
    : Node("robot_subscriber")
    {
        subscription_ = this->create_subscription<geometry_msgs::msg::Point>(
            "robot_position",
            10,
            std::bind(&RobotSubscriber::position_callback, this, std::placeholders::_1));
    }

private:
    void position_callback(const geometry_msgs::msg::Point::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "Received: x=%.2f, y=%.2f, z=%.2f", msg->x, msg->y, msg->z);
    }

    rclcpp::Subscription<geometry_msgs::msg::Point>::SharedPtr subscription_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RobotSubscriber>());
    rclcpp::shutdown();
    return 0;
}
