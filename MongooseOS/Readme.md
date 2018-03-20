# Mongoose OS

See https://www.mongoose-os.com and https://forum.mongoose-os.com

## Setting up programming environment

### Basic - getting started
    1) Download mos.exe into f.instance C:\MOS
    2) Put that directory into PATH
    3) Create a project folder

      cd MOS
      mkdir MOSprojectABC
      cd MOSprojectABC
      mos init

    4) In mos.yml, add the following line

      platform: esp32

    5) After making changes to the generated src/main.c file use this to build and flash to board.

      mos build
      mos flash
      mos console

### Using Visual Studio Code
Once you've got the basic setup above working you should also consider configuring VS.CODE to have a better programming experience.

    1) Install Visual Studio Code
    Go to https://code.visualstudio.com

    2) Add the C/C++ extension
    3) Add the tasks.json file below:

    (content of tasks.json):
    {
    "version": "0.1.0",
    "command": "mos",
    "args": ["build"],
    "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceRoot}"],
        "pattern": {
            "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
            "file": 1,
            "line": 2,
            "column": 3,
            "severity": 4,
            "message": 5
        }
      }
    }

    4) Clone the GIT repository (to get the headers for intellisense)

    cd C:\MOS
    git clone https://github.com/cesanta/mongoose-os.git

    5) Add Include Dirs in VS.CODE

    In your main.c file, click on one of the "#include" lines that have a red squiggly underneath. Then click yellow lightbulb to the left, and choose "Add include path to settings".

    Under the Win32 section in the c_cpp_properties.json file that appears, add "C:/MOS/mongoose-os" to both "includePath", and to "path". Notice that it uses forward slash.

    Go back to main.c and observe that the red squiggly lines are gone. Type in f.instance 'mgos_gpio' to observe that you have intellisense now.
