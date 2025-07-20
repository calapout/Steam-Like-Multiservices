# Steam-Like-Multiservices
Steam Like Multiservice is a portfolio project that aims at reproducing simple functionnalities of steam
using a distributed architecture. The system is currently deployed using a compose file in either
podman or docker. In the current form, the system is composed of those services:

## Services
### Client
This application is not a service per say, but it's actually a desktop application made with CPP
using GTk4 for the application framework and Boost Beast and Boost Json for the http communication and
parsing of the response.

The client uses C++23 and can be compile using CMAKE and VCPKG.

I decided to use C++ for the client as it's a language I really like and that I'm trying to improve.
I also wanted to learn a framework that can be used cross-platform. That is why I chose GTK4 over
the Win API. I also developed it on linux and I wanted a framework that integrate natively with what
I am using and that I can restyle easily.

### GoApi
This service serves as a server offering an http rest api to interact with the system.
This service interact with a postgresql 17 database. The reason I used go for the backend
is that I wanted to use a technology that is performant, easy to scale and that is memory safe.
Go is also simpler to use compare to other languages like Rust and can be compiled as a binary.

### Postgresql
A postgresql 17 database that store the data of the system. I went for postgresql as it is a
simple-to-use database that is also performant and open-source which fits all my current needs.

## License
This project is **source-available (no-derivatives)**. You may clone, view, and run it
locally for evaluation or portfolio review. You may not reuse any code, redistribute
copies, publish modified versions, or incorporate any part into other software or
services. See [LICENSE.txt](./LICENSE.txt) for details.