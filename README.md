# SHA-256

This is a project for GMIT's Theory of Algorithms module. This program is written in C and was developed using visual studio 2017. The purpose of this was to use the SHA-256 algorithm to encrypt a file containing a message. 

## Getting Started

Firstly, to get this current project on your local machine first clone or download this project as a zip.
```
git clone https://github.com/smcguire56/SHA-256
cd SHA-256
```
From there you can either run the program on the console using GCC's compiler or use visual studio.
To find the C file run:

```
cd SHA/SHA
```

From the console compile and run the C file locally using:
```
gcc main.c -o SHA
./SHA
```

or if you prefer to use visual studio go to the first SHA directory and double click on " SHA.sln ".

### Prerequisites

In order to run the C file, you must have a C compiler on your local computer, either GCC or Visual Studio with C functionality.

GCC: https://gcc.gnu.org/install/binaries.html
VS: https://visualstudio.microsoft.com/ 

## Running the tests

When you run the C file initially it will ask the user for a specific file you wish to apply the SHA-256 encryption to.
The file must exist in the same directory as the main.c file and you must also include the file extension when specifying which file (.txt).

## Authors

* **Sean McGuire** - [GitHub](https://github.com/smcguire56)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


