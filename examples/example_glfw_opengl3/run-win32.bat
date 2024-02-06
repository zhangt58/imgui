@ECHO OFF
SET EPICS_CA_AUTO_ADDR_LIST=YES

copy example_glfw_opengl3.exe dist\
cd dist
example_glfw_opengl3