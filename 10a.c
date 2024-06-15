#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
void create_daemon() {
	pid_t pid;
	// Fork the parent process
	pid = fork();
	// If the fork failed, exit
	if (pid < 0) {
		exit(EXIT_FAILURE);
	}
	// If we got a good PID, let the parent terminate
	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}
	// Create a new SID for the child process
	if (setsid() < 0) {
		exit(EXIT_FAILURE);
	}
	// Change the file mode mask
	umask(0);
	// Change the current working directory
	if ((chdir("/")) < 0) {
		exit(EXIT_FAILURE);
	}
	// Close out the standard file descriptors
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	// Open new file descriptors to /dev/null
	open("/dev/null", O_RDONLY); // stdin
	open("/dev/null", O_WRONLY); // stdout
	open("/dev/null", O_WRONLY); // stderr
	}
int main() {
	// Create the daemon process
	create_daemon();
	// Open a log for writing
	openlog("daemon_example", LOG_PID, LOG_DAEMON);
	// Daemon loop
	while (1) {
		// Daemon-specific code goes here
		syslog(LOG_NOTICE, "Daemon is running...");
		sleep(30); // Sleep for 30 seconds
	}
	// Close the log
	closelog();
	return EXIT_SUCCESS;
}
