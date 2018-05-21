# shadowsocksrr-asio

### a shadowsocksr C++ implement which driven by boost.asio

_**(still in the early stages of development, not yet ready to use)**_


# develop information

this project use CMake, early develop on the windows use VS2017/vs141 with CMake project support.

it also can build with pure CMake if you like.

### 3th lib depend
* Boost >= 1.67
* OpenSSL >=1.1.0f
* Libsodium >= 1.0.16

if you want to build and test this, set ```BOOST_ROOT``` ```BOOST_LIBRARYDIR``` ```OPENSSL_ROOT_DIR``` ```sodium_DIR``` variable on CMake or on ```CMakeSettings.json``` if you use VS2017 to develop.

and if you don't want set environment variable to DLL on debug, set ```STATIC``` ```sodium_USE_STATIC_LIBS``` to ```true``` to let Boost and Libsodium to link static lib.

## pre-build version 3th lib donwload pages (only for development)
* [Boost 1.67](https://dl.bintray.com/boostorg/release/1.67.0/binaries/)
* [OpenSSL 1.1.0f](https://www.npcglib.org/~stathis/blog/precompiled-openssl/)
* [Libsodium 1.0.16](https://download.libsodium.org/libsodium/releases/)


