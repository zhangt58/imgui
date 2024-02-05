@ECHO OFF
"SET "PATH=C:/Users/zhangt/Downloads/base-7.0.8/testioc/bin/windows-x64;C:/Users/zhangt/Downloads/base-7.0.8/bin/windows-x64;%PATH%"
SET EPICS_CA_AUTO_ADDR_LIST=YES

copy example_glfw_opengl3.exe dist\
cd dist
example_glfw_opengl3