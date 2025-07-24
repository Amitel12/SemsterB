#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	char tweet[] = "This is my @mention";
	char* mention = strchr(tweet, '@');
	printf("mention: %s\n", mention);
	mention[0] = '*';
	printf("%s\n", tweet);
	if (strchr(tweet, '#') == NULL)
	{
		printf("strchr returned NULL\n");
	}
	return 0;
}