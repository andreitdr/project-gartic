# API

Below is a list of function that are used for the Backend


## User Login

<code>/user/login</code>

This function allows the frontend to check if the user exists or not. If the user exists, it will return the user's id. 
If not, it will return -1.


### Input
This function accepts <strong>JSON</strong> input format:
```json
{
    "username": "andrei2003",
    "password": "test"
}
```

### Output
This function returns a json with the following contents:
```json
{
    "ResponseState": true,
    "ResponseMessage": [
        "Success"
    ],
    "UserData": {
        "username": "andrei2003",
        "givenName": "andrei",
        "surname": "tudor",
        "userID": 1
    }
}
```

## User Register

<code>/user/register</code>

This function allows the frontend to register a new user to the database.

### Input
This function accepts <strong>JSON</strong> input format:
```json
{
    "username": "andrei2003",
    "password": "test"
}
```

### Output
This function returns a json with the following contents:
```json
{
    "ResponseState": true,
    "ResponseMessage": [
        "Success"
    ],
    "UserData": {
        "username": "andrei2003",
        "givenName": "andrei",
        "surname": "tudor",
        "userID": 1
    }
}
```