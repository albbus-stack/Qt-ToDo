# Qt-ToDo

[![GPLv3 License](https://img.shields.io/badge/%20License-GPL%20v3-yellow?style=flat-square)](https://opensource.org/licenses/)
[![Qt](https://img.shields.io/badge/Qt-qmake-brightgreen?style=flat-square)](https://github.com/qt)
![Committed](https://img.shields.io/github/last-commit/albbus-stack/Qt-todo?label=Committed&color=42c5f5&style=flat-square&logo=qt&logoColor=42c5f5&logoWidth=18&labelColor=555555)

A simple ToDo list made using `C++` for data management and logic and [Qt](https://github.com/qt) for Gui.

## Build it

###### Requirements

* Qt 5.15 or higher
* MingW or another `C++` compiler
* Qt Creator to use .pro setup

###### Steps

1. Pull this repository.
2. Open [ToDo.pro](https://github.com/albbus-stack/Qt-ToDo/blob/master/ToDo.pro) with Qt Creator.
3. Run and enjoy. :octocat:

## Structure

You can see the UML class diagram on [this](https://app.lucidchart.com/documents/view/9751743c-2b2b-42f2-9e27-436e74323da8) LucidChart.

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

## Qt Tests

To run them, after building all the .pro files in the [test](https://github.com/albbus-stack/Qt-ToDo/tree/master/tests) folder you should go into your `/build-Test.../debug` folders and copy these .bat [files](https://github.com/albbus-stack/Qt-ToDo/blob/master/build/testController/TestController.bat), changing in them the `PATH` to your Qt installation.

#####
![Tests](https://github.com/albbus-stack/Qt-ToDo/blob/master/tests/Tests.png)

