#include<stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int  pid, fpipe[2], fpipe2[2];
	char buff[100];

	pipe(fpipe);
	pipe(fpipe2);

	pid = fork();

	while(1){

		if( pid == 0){

			close(fpipe[1]);
			close(fpipe2[0]);
			
			read(fpipe[0], buff, sizeof(buff));
			printf("P1 says : %s\n", buff);

			printf("P2 : ");
//            fgets(buff,sizeof(buff),stdin);

			scanf("%s", buff);
			write(fpipe2[1], buff, sizeof(buff));

			
		}
        else{

            printf("P1: ");
//            fgets(buff,sizeof(buff),stdin);
//            fgets(buf,10,stdin);
        	scanf("%s", buff);            
            close(fpipe[0]);
			close(fpipe2[1]);
			
			
            write(fpipe[1], buff, sizeof(buff));


			read(fpipe2[0], buff, sizeof(buff));
            printf("P2 says: %s\n", buff);


		}

	
	}

	return 0;
}
