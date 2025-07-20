# Steam Like Client
## Dependencies
- Boost-Beast
- Boost-Json
- gtkmm-4.0

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