#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
// Signal handler function
void sigint_handler(int signum) {
printf("Caught SIGINT (signal number %d). Now resetting to default action.\n", signum);
// Set up the sigaction structure to reset SIGINT to default action
struct sigaction sa;
sa.sa_handler = SIG_DFL; // Default signal handler
sa.sa_flags = 0; // No flags
sigemptyset(&sa.sa_mask); // Clear all signals from the signal set
// Reset the signal action for SIGINT to the default action
if (sigaction(SIGINT, &sa, NULL) == -1) {
perror("sigaction");
exit(EXIT_FAILURE);
}
}
int main() {
// Set up the sigaction structure for the custom signal handler
struct sigaction sa;
sa.sa_handler = sigint_handler; // Our custom signal handler
sa.sa_flags = 0; // No flags
sigemptyset(&sa.sa_mask); // Clear all signals from the signal set
// Set the signal action for SIGINT
if (sigaction(SIGINT, &sa, NULL) == -1) {
perror("sigaction");
exit(EXIT_FAILURE);
}
printf("Press Ctrl+C to trigger SIGINT. After the first Ctrl+C, the default action will be restored.\n");
// Loop indefinitely to keep the program running
while (1) {
pause(); // Wait for signals
}
return 0;
}
