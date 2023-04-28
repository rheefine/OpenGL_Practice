# OpenGL_Practice

## Overview

[컴퓨터 그래픽스 강의](http://giplab.kyonggi.ac.kr/)를 수강하며 OpenGL 실습을 진행한 기록을 담은 레포지토리입니다.  
This is a repository documenting my experience of taking a [computer graphics course](http://giplab.kyonggi.ac.kr/) and practicing OpenGL programming.  
<br/>

## How To

### Build

각각의 과제 파일은 `win32` 환경에서 [CMake](https://cmake.org/)와 [VcPkg](https://github.com/microsoft/vcpkg)를 사용하여 다음과 같이 빌드할 수 있습니다.  

```console
$ cd assignment_1
$ cd gl_1_1
$ cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]\vcpkg\scripts\buildsystems\vcpkg.cmake"
$ cmake --build build --config debug
```  
  
### Run
```console
$ .\build\debug\gl_1_1.exe
```
<br/>

***

## Dependencies

This project uses external library:

- freeGLUT, MIT license, https://github.com/FreeGLUTProject/freeglut/blob/master/COPYING