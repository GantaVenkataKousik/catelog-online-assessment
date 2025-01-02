# Catalog Placements Assignment - Online

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="900">

**Name:** Ganta Venkata Kousik  
**Roll No:** 21pa1a0549<br>
**College:** Vishnu Institute of Technology

## Overview

This project is a simplified implementation of Shamir's Secret Sharing algorithm. The task is to find the constant term of a polynomial given a set of encoded roots in JSON format. The polynomial is represented as:

\[ f(x) = a_m x^m + a_{m-1} x^{m-1} + \ldots + a_1 x + c \]

Where:
- \( f(x) \) is the polynomial function
- \( m \) is the degree of the polynomial
- \( a_m, a_{m-1}, \ldots, a_1, c \) are coefficients (real numbers)
- \( a_m \neq 0 \) (ensuring the polynomial is of degree \( m \))

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="900">

## Features

- Reads input from JSON files containing encoded polynomial roots.
- Decodes the y-values from various bases.
- Uses Gaussian elimination to solve for the polynomial coefficients.
- Outputs the constant term \( c \) for each test case.

## Requirements

- C++ compiler (e.g., g++)
- RapidJSON library for JSON parsing

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="900">

## Setup

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/GantaVenkataKousik/catelog-online-assessment
   ```

2. **Install RapidJSON:**
   Ensure that the RapidJSON library is installed and accessible in your include path.

3. **Compile the Code:**
   ```bash
   g++ -o main main.cpp -I/path/to/rapidjson/include
   ```

## Usage

1. **Prepare JSON Files:**
   Ensure that your JSON files (`input1.json`, `input2.json`, etc.) are in the same directory as the executable.

2. **Run the Program:**
   ```bash
   ./main
   ```

3. **Output:**
   The program will output the constant term \( c \) for each test case.

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="900">

## Example JSON Format
```
{
"keys": {
    "n": 10,
    "k": 7
  },
  "1": {
    "base": "6",
    "value": "13444211440455345511"
  },
  "2": {
    "base": "15",
    "value": "aed7015a346d63"
  },
  "3": {
    "base": "15",
    "value": "6aeeb69631c227c"
  },
  "4": {
    "base": "16",
    "value": "e1b5e05623d881f"
  },
  "5": {
    "base": "8",
    "value": "316034514573652620673"
  },
  "6": {
    "base": "3",
    "value": "2122212201122002221120200210011020220200"
  },
  "7": {
    "base": "3",
    "value": "20120221122211000100210021102001201112121"
  },
  "8": {
    "base": "6",
    "value": "20220554335330240002224253"
  },
  "9": {
    "base": "12",
    "value": "45153788322a1255483"
  },
  "10": {
    "base": "7",
    "value": "1101613130313526312514143"
  }
}
```


<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="900">

## Notes

- Ensure that the JSON files are correctly formatted and contain valid data.
- The program assumes that the number of roots provided (n) is greater than or equal to the minimum number of roots required (k).


## Contact

For any questions or issues, please contact Ganta Venkata Kousik at venkatakousikcse01@gmail.com or 21pa1a0549@vishnu.edu.in 
