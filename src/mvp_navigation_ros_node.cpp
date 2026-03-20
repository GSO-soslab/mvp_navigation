
#include "mvp_navigation/mvp_navigation_ros.hpp"

#include "iostream"

int main(int argc, char* argv[]) {

    rclcpp::init(argc, argv);

    auto navigation_ros = std::make_shared<MvpNavigationROS>();

    rclcpp::spin(navigation_ros);

    rclcpp::shutdown();

    return 0;

}