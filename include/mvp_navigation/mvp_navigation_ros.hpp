/*
    This file is part of MVP-Navigation program.

    MVP-Navigation is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    MVP-Navigation is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MVP-Navigation.  If not, see <https://www.gnu.org/licenses/>.

    Author: Emir Cem Gezer
    Email: emircem@uri.edu;emircem.gezer@gmail.com
    Year: 2022

    Copyright (C) 2022 Smart Ocean Systems Laboratory
*/

#pragma once

#include "functional"
#include "thread"
#include <string>

#include "rclcpp/rclcpp.hpp"


#include "Eigen/Dense"

/** @brief ROS wrapper for MvpNavigation
 *
 *  This package wraps mvp navigation class and utilizes its
 *  functionality.
 *
 *  @see MvpNavigation
 */
class MvpNavigationROS : public rclcpp::Node
{
public:
    /** @brief Default constructor
     *
     */
    MvpNavigationROS(std::string name = "mvp_navigation");

private:
    /** @brief 
     */
    void load_config();

};
