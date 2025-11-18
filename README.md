Analog Clock - OpenGL Project
A simple and elegant analog clock implementation using OpenGL and GLUT, featuring real-time system time display with smooth animations.

🕐 Features
Real-time Clock: Displays current system time

Visual Design: Color-coded hands for hours, minutes, and seconds

Circular Numbers: Numbers 1-12 arranged in a circular pattern

Minute Markings: Short and long ticks for minute indicators

Rotating Numbers: Numbers on clock hands that rotate with movement

Smooth Updates: Automatic time updates every second

🛠️ Technical Specifications
Language: C++

Libraries: OpenGL, GLEW, FreeGLUT

OpenGL Version: 4.3

Platform: Windows

Compiler: Visual Studio compatible

🎨 Visual Elements
Clock Face: Orange circular boundary

Hour Hand: Green color

Minute Hand: Blue color

Second Hand: Red color

Background: Black

Numbers: White with orange main numbers

🚀 How to Run
Prerequisites:
Visual Studio 2019 or later

OpenGL libraries

GLEW and FreeGLUT installed

Compilation:
Open project in Visual Studio

Ensure library paths are configured

Build and run the project

⌨️ Controls
ESC Key: Exit the application

📁 Project Structure
main.cpp: Main source file containing all clock logic

Uses glutTimerFunc for periodic time updates

drawText() function for text rendering

drawNumber() functions for number positioning

updateTime() for real-time time calculations

🔧 Implementation Details
Trigonometric calculations for hand positioning

chrono library for system time access

Matrix transformations for text rotation

OpenGL primitive drawing (lines, circles)

Color-coded visual elements

⚙️ Key Functions
drawScene(): Main rendering function

updateTime(): Updates clock hands position

drawText(): Handles text rendering with scaling and rotation

getTime(): Retrieves current system time

resize(): Handles window resizing

This project demonstrates practical application of computer graphics concepts in creating functional and visually appealing utilities. The code showcases efficient use of OpenGL for 2D graphics and real-time animations.
