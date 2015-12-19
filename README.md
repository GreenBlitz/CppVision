# CppVision
This project is an implementation of a robot vision in c++ designed to run on the Jetson TK1 board.



## Setting up the Project's Environment

First of all, this project is supposed to be build on either virtual or non-virtual Linux Ubunutu OS.
After you've managed to setup the Ubunutu enviorment, continue reading the tutorial.


### Downloading Eclipse
**If you already have eclipse CDT installed, skip this part of the tutorial.**

Download Eclipse CDT from: https://eclipse.org/cdt/ for linux, and download a jdk by running the following commands in the terminal: 

`$ sudo apt-get install default-jre`

`$ sudo apt-get install default-jdk`

When you finish downloading eclipse, extract the tar.gz file and open the program's executable which is located at <Extracted_Folder>/eclipse/eclipse.

And you are done, you have successfully installed eclipse CDT.


### Building OpenCV
**If you have already compiled and built opencv's sources, skip this part of the tutorial.**

Download opencv for Linux from http://opencv.org/
Extract the downloaded file and run the following commands:

`$ sudo apt-get install build-essential` (If you have have already installed the c++ compiler, don't run this command)

`$ sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev`

Extract OpenCV's sources into a folder which I will refer to as <opencv_src>.
Make a folder in <opencv_src>/opencv and call it "release".
Run the following commands:

`$ cd <opencv_src>/opencv/release`

`$ cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..`

`$ sudo make install`

The last one will take some time to execute, so be patient.
After that, you are done with building opencv.


### Source Download

Click the "Download Zip" button in the upper right corner of the github view.
Open the downloaded "CppVision-master.zip" and extract the "CppVision-master" folder into a folder which I will refer to as 
<downloaded_src>.
You have successfully downloaded the source files.


### Project Set-Up

After choosing a workspace, create a new C++ project by right-clicking the Project-Explorer and selecting 'New...'
Choose a name to the project and as for the compiler, choose the Linux GCC compiler and an empty project.
After creating the project create a new source folder, and name it "src".
Open <downloaded_src>/src and drag it's contents to the "src" folder in eclipse.
A prompt will show up, in which you want to check the "copy files" option.
Now right click on the project and select properties.

Go to C/C++ Build > Settings > Tool Settings > GCC C++ Compiler > Includes. 
In the 'include paths' option add `/usr/local/include` and `/usr/local/include/opencv`.

Now go to C/C++ Build > Settings > Tool Settings > GCC C++ Linker > Libraries.
In the 'library search path' option add `/usr/local/` and `/usr/local/lib/`.
In the 'libraries' option add `opencv_core` , `opencv_imgcodecs` , `opencv_imgproc` and `opencv_highgui`.

Click "Apply" and "OK".
Now right click the project and select the "Build Project" option.
Now the project should be built.
Run the project and you should see in the console: `Usage: display_image ImageToLoadAndDisplay`

Now right click the project and click the "Run as" option and in it select the "Run configurations..." option.
Right click the already existing configuration and choose the duplicate option.
Now change the configuration name to whatever you desire, I am going to refer to it as <run_cfg>.
In <run_cfg> go to the "Arguments" tab and add Usage: `<downloaded_src>/sample3.jpg`

Click on "Apply" and on "Run".

Now the project should run and you successfully built and ran the project.
