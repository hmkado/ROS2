# Base image with ROS 2 desktop and GUI tools
FROM osrf/ros:humble-desktop-full

# Install extra dev tools
RUN apt update && apt install -y \
    tree \
    git \
    vim

# Set default command
CMD ["bash"]