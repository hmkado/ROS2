Build: docker-compose -f ros.yml up --build

Run: docker exec -it ros-ros2 bash

Source: source /opt/ros/humble/setup.bash

Resolve Dependencies: rosdep install -i --from-path src --rosdistro humble -y
