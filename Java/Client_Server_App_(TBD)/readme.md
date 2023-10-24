# Semester Project

The topic of the semester project is defined by the student and must be approved by the supervisor within the 1st checkpoint (see below).

## Requirements

### Server-side Application

- The application is of the client-server type.
- It deals with 3 domain types and implements complete CRUD operations (basic data operations for insertion, reading, updating, deletion).

**Server Part**

- It is a three-tier application.
- Built on the Spring framework and written in Java.
- Utilizes object-relational mapping in the persistent layer.
- Any relational database with persistent data storage can be used, which can handle multiple requests (DB server).
- In-memory or simple embedded file databases (e.g., SQLite) are not considered.
- Works with at least 3 entities from the relational database (all CRUD operations, minimum 1 many-to-many relationship, thus there will be 4 tables in the relational database; using ORM).
- Implements an additional query using ORM (beyond CRUD and manipulation with M:N relationships, ideally realized in JPQL).
- The layer of application logic allows all operations of the data layer (CRUD for all entities, manipulation with M:N relationships, additional query).
- Appropriately designed and documented REST API provides all operations of the application logic layer (including CRUD for all entities).
- Compliance with web standards, including HTTP status.
- Adherence to RESTful principles will be part of the evaluation.
- Complete, well-processed, and machine-readable API documentation (preferably OpenAPI): all resources (addresses), operations, and data formats.
- A separate data model for the API ("DTO" classes) is strongly recommended.
- Contains automated tests.
- Three different types of tests that were covered in the subject.
- Appropriately assembled (Gradle) and tests are executed and evaluated as part of the assembly.
- Version controlled using the git system.
- The repository located at Gitlab FIT (gitlab.fit.cvut.cz/<username>/<server_repo>) should be used for development and submission.

**Client-side Application**

- Any programming/scripting language.
- Any interface (GUI, web application, interactive console application).
- Accesses the RESTful web service provided by the server-side.
- Implements a complex business operation using the server-side.
- This operation (from the user's perspective, it is a single action, for example, initiated by a button in a form) is composed of multiple individual steps from the system's perspective, e.g., database operations or decision-making (if) on the client side.
- Version controlled.
- The repository located at Gitlab FIT (gitlab.fit.cvut.cz/<username>/<client_repo>, it can be the same repository as for the server) should be used for development and submission.

## Submission

The topic of the semester project is specified by the student and is approved by the supervisor within the 1st checkpoint (deadline see exercise schedule). The specification includes:

- Description of the business operation to be implemented in the client.
- Data model used in the server part (can be relational or object-oriented).
- Description of the additional complex query to be implemented in the server part.
- Submission via the repository on Gitlab FIT.

The regular deadline for submitting the semester project is 05.01.2023. Up to 60 points can be obtained for a semester project submitted on time. In the case of late submission, the point gain will be reduced by 10 points for each started week.

