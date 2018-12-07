
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

sem_t mutex,rwmutex;
int num = 0;

void *writer(void *arg)
{
    char msg[100];
    scanf("%s",msg);

    sem_wait(&rwmutex);

    FILE *fptr;
    fptr=fopen("./message.txt","a");
    if(fptr==NULL)
    {
        printf("Error");
        exit(1);
    }

    fprintf(fptr,"%s\n",msg);
    fclose(fptr);

    int f;
    f = ((int) arg);

    printf("Message sent by the writer %d is %s\n",f,msg);

    f++;
    sleep(1);
    sem_post(&rwmutex);
}

void *reader(void *arg)
{
    int check;
    sem_wait(&mutex);
    num++;

    if(num==1)
        sem_wait(&rwmutex);

    sem_post(&mutex);

    int f = ((int)arg);
    printf("Message read by the reader %d is \n",f);
    FILE *fpt1;
    fpt1=fopen("./message.txt","r");
    if(fpt1 ==NULL)
    {
        printf("Error");
        exit(1);
    }
    char ch=fgetc(fpt1);
    while(ch!= EOF)
    {
        printf("%c",ch);
        ch=fgetc(fpt1);
    }
    fclose(fpt1);

    sleep(1);
    sem_wait(&mutex);
    check ++;
    num--;
    check--;
    if(num==0)
        sem_post(&rwmutex);
    check++;
    sem_post(&mutex);
}



int main()
{
    pthread_t rno[1000],wno[1000];

    int wcount=0, rcount =0;
    sem_init(&mutex,0,1);
    sem_init(&rwmutex,0,1);

    printf("1. Add Writer\n");
    printf("2. Add Reader\n");
    printf("3. Exit\n");

    for (int flag=1000; flag>0 ; flag--)
    {
        int n;
        scanf("%d",&n);


        switch(n)
        {

            case 1 :
            {

                wcount++;
                pthread_create(&wno[wcount], NULL, writer, (void *) wcount);
                pthread_join(wno[wcount], NULL);
                break;
            }
            case 2 :
            {
                rcount++;
                pthread_create(&rno[rcount], NULL, reader, (void *) rcount);
                pthread_join(rno[rcount], NULL);
                break;
            }

            case 3 :
            {
                flag = 0;
                FILE *fptr;
                fptr=fopen("./message.txt","w");
                if(fptr==NULL)
                {
                    printf("Error");
                    exit(1);
                }
                fprintf(fptr,"");
                fclose(fptr);

                break;
            }

            default : printf("Invalid choice");

        }



    }


    return 0;
}

