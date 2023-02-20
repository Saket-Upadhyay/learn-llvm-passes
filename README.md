# Learn LLVM Passes
A bunch of elementary LLVM Analysis and Transformation Passes.

:gear: The project was build and tested with LLVM-14 (with the new `PassManager`) on MacOS X 13.x and Ubuntu 22.x.

## Prerequisites
#### Linux
```shell
sudo apt-get install cmake llvm-14 clang-14
```
#### MacOS
```shell
brew install llvm@14
```

_You might need to install HomeBrew in MacOS, learn more from [brew.sh](https://brew.sh)._

---


## Build
#### Fetch Repository
```shell
git clone https://github.com/Saket-Upadhyay/learn-llvm-passes.git
```
#### Change directory to the project
```shell
cd learn-llvm-passes
```
#### Create a build folder and initiate CMake in it.
```shell
mkdir build
cd build
cmake ..
```
#### Build using Make
```shell
make
```

###### Everything together will look something like this -
```shell
git clone https://github.com/Saket-Upadhyay/learn-llvm-passes.git
cd learn-llvm-passes
mkdir build
cd build
cmake ..
make
```

> Note: MacOS will create `.dylib` (dynamic library) files and Linux will create `.so` (shared object) file.
---
## Run
#### Create LLVM IR
```shell
clang -S -emmit-llvm <path to c++/c file>
```

#### Load pass with `opt` and run on generated IR
```shell
 opt -load-pass-plugin ../build/source/<pathto .so or .dylib> -passes=<pass-name> <path to llvmir.ll>
```

### Example
```shell
cd tests
clang -S -emit-llvm helloWorld.cpp
opt -load-pass-plugin ../build/source/countinstructions/countinst.{so|dylib} -passes="count-intr" -disable-output helloWorld.ll
```

:pencil2: In the example above, I am not using a transformation pass, it's just an analysis pass, hence I used `-disable-output` to avoid new procesed file from `opt`. Do not use this if you are running a transformation pass.
