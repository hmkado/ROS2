#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

class RobotPublisher : public rclcpp::Node{     //Inherits from rclcpp::Node
    public:
        RobotPublisher()
        : Node("robot_publisher"),x_(0.0),y_(0.0),z_(0.0)       //Initialization list
        {
            //Initialize publisher
            publisher_ = this->create_publisher<geometry_msgs::msg::Point>("robot_position",10);    
            //Call "create_publisher()" from rclcpp::Node to publish with a topic name "robot_publisher"
            //Call publisher_position from this class
            timer_ = this->create_wall_timer(std::chrono::seconds(1),std::bind(&RobotPublisher::publish_position,this));
        }
    private:
        void publish_position(){
            auto msg = geometry_msgs::msg::Point();
            msg.x = x_;
            msg.y = y_;
            msg.z = z_;
            RCLCPP_INFO(this->get_logger(),"Publishing: x=%.2f, y=%.2f, z=%.2f",x_,y_,z_);
            publisher_->publish(msg);
            x_ += .1;
            y_ += .1;
        }
        rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        double x_,y_,z_;
}

int main(int argc,char* argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<RobotPublisher>());
    rclcpp::shutdown();
    return 0;
}
