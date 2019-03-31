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

## Code Details

- The main function:
1. Initially I declare the array 'H' containing the current hash value, this is defined in the page 15, consist of the  following eight 32-bit words in hex. This array will later be changed.
2. Then I declare the FILE msgf which will allow the program to take in user specific files.
3. I call the sha256() function including the variables H and msgf.
4. After sha256 updates the value of H I then print the value of H to the console.
5. Finally closing the file stream.

- The filehandler function:
1. this function asks the user for the file the user wants to hash.
2. does a check to make sure the file exists.
3. loops through until it finds an existing file.
4. then returns the file pointer.

- The sha function:
1. defines varaibles used to keep track of the K values while keeping track of the status of the message block.
2. looping through the message block calling the nextmsgblock function.
3. Does a big endian to little endian change if required. 
4. Later then returning the updated value of H back to the main function.

- nextmsgblock function:
1.   takes in the variables msgf, the message block M, the status and the number of bits.
2.   Later does a check to change to big endian if required. 
3.   append the file size in bits as a unsigned 64 bit
4.   Later pads the rest with all zeros.
s
## Authors

* **Sean McGuire** - [GitHub](https://github.com/smcguire56)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


