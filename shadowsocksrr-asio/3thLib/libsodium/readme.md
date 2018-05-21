
# note for update

the file Findsodium.cmake are come from the offical project of Libsodium on the github at 2018-05-20

it come from the https://github.com/jedisct1/libsodium/blob/master/contrib/Findsodium.cmake

and , if anyone need update the lib at future , update as above , follow the offical CMake way is best awy.


# note for install 

## for windows user

download the newgest version of libsodium from [this](https://download.libsodium.org/libsodium/releases/) if you are in windows.

now \[2018-05-20\] , the newgest version of libsodium is ```libsodium-1.0.16-msvc.zip``` .

and set the ```sodium_DIR``` variable on the ```CMakeSettings.json``` if you develop on VS2017 or direct set it on CMake if you use CMake GUI or command.

and if you like , set ```sodium_USE_STATIC_LIBS``` to ```true``` to let it on STATIC link.

or set a environment variable which named ```sodium_DIR``` to the libsodium dir to let CMakeFind auto find above variable.


