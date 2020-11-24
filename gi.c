#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <time.h>
#include <signal.h>
#define MAX 1000000


//struct message to send 
struct message{
                  struct timespec timestamp;
                  char g;
                  int x;
                } ciao;


int main(int argc, char* argv[]){ 
         
         if(argc!=4){
                perror("Wrong number of inputs elements, you should write:\n      <gi.exe> <id> <gir> <offset>");
                return -1;
              }

         int id=atoi(argv[1]); //id tell me if process is G1 or G2
         int gir= atoi(argv[2]);//g sees input(write) end of Gi and R' pipe
         int offset=atoi(argv[3]);//offset 
         int i; //index for cycle
         int tmp; //variable for computing delay
         
         
        
         /*-------------------SEND MESSAGES IN LOOP-------------------*/
            for(i=0;i<MAX;i++){
               
                //get time in timestamp
                clock_gettime(CLOCK_REALTIME,&(siao.timestamp)); 
                //printf("The actual time is: %ld\n", siao.timestamp.tv_sec);
                //printf("The actual time is: %ld\n", siao.timestamp.tv_nsec);

                //put id in siao.g
                ciao.g=(char)id;
                //printf("Hello i'm process %d\n", siao.g);

                //in x i have the message's number
                ciao.x=i;
                //printf("My number is %d\n", siao.x);

                //write on pipe and error check
                if(write(gir,&ciao,sizeof(siao))<0){
                         perror("ERROR in Gi and R communication...");
                         exit(-3);
                        }

                //introduce delay
                tmp=offset+(rand()%offset+1);
                usleep(tmp);
                
                }
            /*---------------------------------------------------------*/

            //signal for controlling scheduling between R and G1,G2 
            //printf("G %d prekill\n", id);
            //fflush(stdout);
            
            raise(SIGSTOP);
            
            close(gir);//close pipe
           
            //printf("G %d post kill\n", id);
            //fflush(stdout);
            return 0;
          
          
}   





