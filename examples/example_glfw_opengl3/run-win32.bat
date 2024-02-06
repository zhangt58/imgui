@ECHO OFF
:: SET "EPICS_CA_AUTO_ADDR_LIST=YES"
SET "EPICS_CA_AUTO_ADDR_LIST=NO"
SET "EPICS_CA_NAME_SERVERS=127.0.0.1:50640"
SET "EPICS_CA_MAX_ARRAY_BYTES=32000000"

copy example_glfw_opengl3.exe dist\win32
copy cadata\libcadata.dll dist\win32
cd dist\win32\
example_glfw_opengl3