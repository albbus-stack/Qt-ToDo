# Qt-ToDo

[![GPLv3 License](https://img.shields.io/badge/License-GPL%20v3-yellow.svg)](https://opensource.org/licenses/)
[![Qt](https://camo.githubusercontent.com/20b46b5f6c00149c9909f644845e4b17cdb94941/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f51742d716d616b652d677265656e2e737667)](https://github.com/qt)

A simple ToDo list made using `C++` for data management and logic and [Qt](https://github.com/qt) for Gui.

## Build it

###### Requirements

* Qt 5.15 or higher
* MingW or another `C++` compiler
* Qt Creator to use .pro setup

###### Steps

1. Pull this repository.
2. Open [ToDo.pro](https://github.com/albbus-stack/Qt-ToDo/blob/master/ToDo.pro) with Qt.
3. Run and enjoy. :octocat:

#### Qt Tests

To run them, after building all the .pro files in the [test](https://github.com/albbus-stack/Qt-ToDo/tree/master/tests) folder you should go into your `/build-Test...` folders and use these .bat [files](https://github.com/albbus-stack/Qt-ToDo/blob/master/build/testController/TestController.bat), changing in them the `PATH` to your Qt installation.

#####
![Tests](https://github.com/albbus-stack/Qt-ToDo/blob/master/tests/Tests.png)

## Shortcuts

`Ctrl + A` : Add a new task

`Ctrl + D` : Delete a selected task

`Ctrl + Alt + D` : Delete all tasks

`Ctrl + S` : Saves all your tasks

`Ctrl + Q` : Saves and then quits the program

`Ctrl + F` : Filter tasks by deadline day

`Ctrl + Z` : Remove the filter to see all the tasks

> *You can still view these under the `Actions` menu*

## Screenshot

![Screenshot](https://github.com/albbus-stack/Qt-ToDo/blob/master/ToDo_capture.PNG)
