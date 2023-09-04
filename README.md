# Real-time Currency Exchange Rate Monitoring and Notification System

## Overview

The Currency Exchange Rate Monitoring and Notification System is a versatile and practical software application designed to empower users with real-time tracking of currency exchange rates and proactive notifications regarding significant fluctuations. This project combines elements of currency data retrieval, multithreading, and user interaction to deliver a valuable financial tool.

## Features

### 1. Real-time Exchange Rate Updates

- The system provides real-time exchange rate updates for multiple currencies, making it an invaluable resource for individuals or businesses involved in international transactions.

### 2. User-Friendly Interface

- A user-friendly command-line interface allows users to input and convert currency amounts effortlessly.
- Clear and concise prompts guide users through the application's functionalities.

### 3. Rate Fluctuation Notifications

- The system continually monitors exchange rates and notifies users when significant rate fluctuations occur, helping users stay informed and make timely financial decisions.

### 4. Thread-Safe Rate Updates

- The program ensures thread safety when updating exchange rates, maintaining data integrity and reliability.

## Supported Currencies (Simulated)

The system currently supports the following currencies (simulated rates, replace with actual data source):

- USD (United States Dollar)
- EUR (Euro)
- GBP (British Pound)
- BDT (Bangladeshi Taka)

## How to Use

1. **Compile the Code**: Compile the C source code using a C compiler. For example, using `gcc`:

`gcc currency_exchange.c -o currency_exchange -pthread`

Ensure the `-pthread` flag is used to enable multithreading.

2. **Run the Program**: Execute the compiled program:

`./currency_exchange`

3. **Follow On-Screen Prompts**: The program will guide you through currency conversions and provide alerts when significant rate fluctuations are detected.

## Extending the Project

This project serves as a foundation for building more comprehensive currency monitoring and trading applications. Here are some ideas for extending the project:

- **Integration with Real Data Sources**: Replace simulated rates with live data sources to provide accurate exchange rates.
- **User Authentication**: Implement user accounts to personalize notifications and track transaction history.
- **Historical Data Analysis**: Add the ability to retrieve historical exchange rate data and perform trend analysis.
- **Graphical User Interface (GUI)**: Develop a GUI application for a more user-friendly experience.

## License

This project is open-source and available under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as needed.

## Contributions

Contributions to this project are welcome! If you have ideas for improvements or new features, please open an issue or submit a pull request on the GitHub repository. Or email me privately and I'll respond to it.

## Acknowledgments

This project is inspired by the need for real-time currency exchange rate monitoring and the importance of staying informed about financial fluctuations.


