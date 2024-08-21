# User Management with c_std

This project demonstrates a simple user management system implemented in C using the `c_std` framework. It handles user creation, storage in a PostgreSQL database, and serialization to JSON. The code is designed to be easily extendable and showcases some of the key features of the `c_std` framework.

## Features

- **User Creation**: Each user is assigned an ID, name, email, and registration timestamp.
- **Database Integration**: Users are stored in a PostgreSQL database.
- **Vector Container**: Users are maintained in a vector container for easy management.
- **JSON Serialization**: Users can be serialized to JSON for storage or transmission.
- **Time Management**: Registration time is captured and formatted using the `c_std` time module.

## Prerequisites

Ensure you have the following installed on your system:

- C compiler (e.g., GCC)
- PostgreSQL database server
- `c_std` framework (ensure all required modules are included)
- `libpq` (PostgreSQL C library)

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
    git clone https://github.com/yourusername/your-repo-name.git
    cd your-repo-name
    ```

2. **Configure the Project**: 
    Ensure your `Makefile` is set up correctly to include the `c_std` framework and link against the `libpq` library.

3. **Compile the Code**:
    ```bash
    make
    ```

4. **Run the Program**:
    ```bash
    ./user_management
    ```

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

## Project Structure

- **src/**: Contains the source files.
- **include/**: Contains header files.
- **Makefile**: Instructions for building the project.

## Contributing

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/your-feature`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

This project is built using the `c_std` framework, a custom C library aimed at simplifying and standardizing common tasks in C programming.
