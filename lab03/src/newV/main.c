#include "message.h"
#include "tunnel.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

Tunnel *tunnel;

char *inputText[3] = {"text0", "text1text1", "text2text2text2"};

char text[3][50];
int point[3] = {0};


static void *subMachine(void *arg)
{
	int deviceID = *((int *)arg);
	int textLength = strlen(inputText[deviceID]);
	printf("%d, %d\n", deviceID, textLength);
	printf("%d\n", tunnel);
	for ( int i = 0; i < textLength; ++i)
	{
		write_to_tunnel(tunnel, inputText[deviceID][i], deviceID);
		sleep(1);
	}
	printf("sub %d complete\n", deviceID);

}

void *test_print(int c)
{
	//int c = *((int *) arg);
	pthread_t tid = pthread_self();
	for ( int i = 0; i < 100; ++i)
	{
		printf("%ld:test_print %d\n", tid, c);
		sleep(1);
	}
}

int main(int argc, char **argv)
{
	int s;
    pthread_t subThread[3];
	tunnel = new_tunnel();

    for ( int i = 0; i < 3; ++i)
    {
        s = pthread_create(&subThread[i], NULL, subMachine, &i);
		printf("%d %d\n", i, s);
		sleep(1);
    }
	while (1) {
		if ( tunnel_empty(tunnel) ) 
			continue;
		Message msg = get_from_tunnel(tunnel);
		text[msg.did][point[msg.did]] = msg.chr;
		printf("text %d: %s\n", msg.did, text[msg.did]);
		point[msg.did]++;
	}

    return 0;
}
