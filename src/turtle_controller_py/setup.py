import os
from setuptools import setup
from glob import glob


package_name = 'turtle_controller_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rarts',
    maintainer_email='ruben.arts@hotmail.com',
    description='Example package for a python only ROS2 project using pixi.',
    license='MIT',
    entry_points={
        'console_scripts': [
            'controller = turtle_controller_py.controller:main'
        ],
    },
    tests_require=['pytest'],
)
