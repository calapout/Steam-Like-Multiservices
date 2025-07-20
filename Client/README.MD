# Steam Like Client
## Dependencies
### Tools
- Ninja
- Cmake 3.30+
- Git
### Libraries
- Boost-Beast
- Boost-Json
- gtkmm-4.0

## How to build
1. clone VCPKG at the root of the project: `git clone https://github.com/microsoft/vcpkg ./vcpkg`
2. Create a build directory: `mkdir build` and then move to the directory with `cd build`
3. Configure cmake:
```sh
# Debug
cmake -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake DCMAKE_BUILD_TYPE=Debug -G Ninja -B ./ ../

# Release
cmake -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake DCMAKE_BUILD_TYPE=Release -G Ninja -B ./ ../
```
4. Execute `ninja` to build the project
5. Run the executable in `bin/{OS}/{ARCH}/SteamLikeClient`. On linux it is something like:
`bin/linux/x86_64/SteamLikeClient`. On Windows it should be something similar, except that the libraries will be  ending
in .dll instead of .so and the executable will be finishing with a .exe

## Layers
The application is composed currently of 3 layers

### Http Library (exported as a shared library)
this layer is in charge of offering a simple api over the http protocol for the different 
type of request (GET, POST, PUT, PATCH, DELETE). This layer is also responsible for parsing the data received as json
using templates and boost json

### Server Facade (exported as a shared library)
This layer exposes abstraction over the call to the server's rest api. It allows to extract the networking code away
from the client.

### Client (exported as an executable)
This layer serves as the application layer. It is responsible to serve the view of the system as a desktop application
made of multiple interface.