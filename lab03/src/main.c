#include "message.h"
#include "tunnel.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

Tunnel *tunnel;

char *inputText[3] = {"text0", "text1text1", "text2text2text2"};

char text[3][50];
int point[3] = {0};
int state[3] = {0};


static void *subMachine(void *arg)
{
	int deviceID = *((int *)arg);
	int textLength = strlen(inputText[deviceID]);
    sleep(1);
    // printf("device %d start.", deviceID);
	for ( int i = 0; i < textLength; ++i)
	{
		write_to_tunnel(tunnel, inputText[deviceID][i], deviceID);
		sleep(1);
	}
    state[deviceID] = 1;
	// printf("device %d complete\n", deviceID);

}


void print_divide() {printf("===============\n");}

void print_all_text()
{
    print_divide();
    for (int i = 0; i < 3; ++i)
    {
        printf("text %d: %s\n", i, text[i]);
    }
    print_divide();
}

int main(int argc, char **argv)
{
	int s;
    pthread_t subThread[3];
    printf("CPU is running normally\n");
    sleep(1);
    printf("Interrupt!\n");
    printf("Tunnel Manager running\n");
	tunnel = new_tunnel();
    printf("CPU recovers running normally\n");
    sleep(1);

    for ( int i = 0; i < 3; ++i)
    {
        s = pthread_create(&subThread[i], NULL, subMachine, &i);
		// printf("%d %ld\n", i, s);
		sleep(1);
    }
    printf("Interrupt!\nTunnel and CPU begin data exchanging\n");
	while (1) {
		Message msg = get_from_tunnel(tunnel);
        int isOver = 1;
        for (int i = 0; i < 3; ++i)
        {
            //printf("state %d:%d\n", i, state[i]);
            isOver &= state[i];
        }
        if (msg.did == -1)
        {
            if (isOver)
                break;
            continue;
        }
		text[msg.did][point[msg.did]] = msg.chr;
		point[msg.did]++;
        print_all_text();
        sleep(1);

        // check if all sub-machine sent data over
            
	}
    printf("CPU is running normally\n");

    return 0;
}
