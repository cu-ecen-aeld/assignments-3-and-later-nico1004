#include <stdio.h>
#include <errno.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
	//syslog setup
	openlog(NULL, 0, LOG_USER);
	if (argc != 3 )
	{
		syslog(LOG_ERR,"invalid amount of arguents!");
		return 1;
	}
	
	char *filename = argv[1];
	char *writestr = argv[2];
	FILE *file = fopen(filename, "w+");
	if (file == NULL)
	{
		syslog(LOG_ERR, "error opening file %s: %m", filename);
		return 1;
	}

	int retval = fprintf(file, "%s", writestr);
	if (retval < 0)
	{
		syslog(LOG_ERR, "error writing string %s to file %s: %m", writestr, filename);
                return 1;
	}
	
	syslog(LOG_DEBUG, "Writing %s to %s", writestr, filename);

	retval = fclose(file);
	if (retval == EOF)
	{
		syslog(LOG_ERR, "error closing file %s: %m", filename);
                return 1;
	}


	return 0;
}

