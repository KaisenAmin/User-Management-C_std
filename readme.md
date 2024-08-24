# User Management with C_STD

This project demonstrates a simple user management system implemented in C using the `C_STD` framework. It handles user creation, storage in a PostgreSQL database, and serialization to JSON. The code is designed to be easily extendable and showcases some of the key features of the `C_STD` framework.

## Features

- **User Creation**: Each user is assigned an ID, name, email, and registration timestamp.
- **Database Integration**: Users are stored in a PostgreSQL database.
- **Vector Container**: Users are maintained in a vector container for easy management.
- **JSON Serialization**: Users can be serialized to JSON for storage or transmission.
- **Time Management**: Registration time is captured and formatted using the `C_STD` time module.

## Requirements

- GCC compiler (ensure it's added to your system's PATH).
- CMake for building the project.
- OpenSSL (for SSL/TLS functionality, if needed).
- **Linux Users**: Ensure you have development libraries installed:
  ```bash
  sudo apt-get install libssl-dev
  ```
  
## Prerequisites

Ensure you have the following installed on your system:

- C compiler (e.g., GCC)
- PostgreSQL database server
- `C_STD` framework (ensure all required modules are included)
- `libpq` (PostgreSQL C library)
- CMake for project configuration and build

## Getting Started

### Setting Up PostgreSQL

1. **Install PostgreSQL** on your machine if it's not already installed.

2. **Create a Database**:
    ```sql
    CREATE DATABASE test;
    ```

3. **Create the Users Table**:
    ```sql
    CREATE TABLE users (
        id SERIAL PRIMARY KEY,
        name VARCHAR(100),
        email VARCHAR(100),
        time_registered TIMESTAMP
    );
    ```

### Building the Project

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/KaisenAmin/User-Management-C_std.git
    cd User-Management-C_std
    ```

2. **Create and Navigate to the Build Directory**:
    ```bash
    mkdir build
    cd build
    ```

3. **Clean Previous Builds** (optional):
    Before starting a new build, it's a good practice to clean previous build files:
    ```bash
    rm -rf CMakeCache.txt CMakeFiles
    ```

4. **Configure the Project**: 
    Use CMake to configure the project with GCC as the compiler:
    ```bash
    cmake -G "Unix Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
    ```

5. **Compile the Code**:
    ```bash
    cmake --build .
    ```

6. **Run the Program**:
    ```bash
    make run
    ```

If everything is set up correctly, the program will run, connect to the PostgreSQL database, and perform the user management tasks.

## Usage

The program will:

1. Attempt to connect to the PostgreSQL database.
2. Create a new user with random details.
3. Store the user in the PostgreSQL database.
4. Display all users currently in the vector container.
5. Serialize the vector of users to JSON and print it to the console.

### Example Output

```bash
Time is 2024-08-21
Data in Vector Container of Users
Id : 4, Name : User 123, Email : User123@gmail.com
Json Serialized Data is
[
    {
        "id": 4,
        "name": "User 123",
        "email": "User123@gmail.com",
        "time_registered": "2024-08-21T15:23:45"
    }
]
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

This project is built using the `C_STD` framework, a custom C library aimed at simplifying and standardizing common tasks in C programming.
