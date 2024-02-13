# 42_Minitalk
The purpose of this project is to code a small data exchange program using UNIX signals.
  - The "client" and "server" files are created.
  - Client, taking a PID as an argument, transmits the message it receives bit by bit (sending SIGUSR2 signal for 1 and SIGUSR1 signal for 0) as another argument.
  - The server processes the incoming signal, handles the received bits, and provides the output to the terminal.
