#include <stdio.h>
#include <stdlib.h>
#define array_size 20
//this is a struct which define a circular queue properties
typedef struct{
    int array[array_size];
    int front1;
    int rear1;
    int front2;
    int rear2;
}CircularQueue;

//this is a method which return a queue struct and this method will assign the default values of variables
CircularQueue* createCircularQueue() {
    //there is a malloc function in here to allocated memeory
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->front1 = 0;
    queue->rear1 = 0;
    queue->front2 = 10;
    queue->rear2 = 10;
    return queue;
}

//this is a engueue function to insert some value for queueu1
void enqueue1(CircularQueue *queue,int value){
    //this is decision block for queue is full or not
    if(queue->rear1==queue->front2-1){
        printf("Queue is full\n");
    }
    else{
        //if queue1 is empty => new value will insert the queue1
        queue->array[queue->rear1] =value;
        queue->rear1++;
        printf("%d is inserted to queue FIRST\n",value);
    }
}

//this is a engueue function to implement some value for queueu2
void enqueue2(CircularQueue *queue,int value){
    //this is decision block for queue is full or not
    if((queue->rear2+1)%array_size==queue->front1){
            printf("Queue is full");
    }
    else{
        //if queue2 is empty => new value will insert the queue2
        queue->array[queue->rear2] = value;
        queue->rear2++;
        printf("%d is inserted to queue SECOND\n",value);
    }
}


void dequeue1(CircularQueue* queue){
    //there is decision to conrtol for queue is empty or not
    if (queue->front1 == queue->rear1) {
        printf("Queue FIRST is empty\n");
    } else {
        //if queueu is not empty => front will be front-1 and value will deleted
        printf("%d is deleted\n",queue->array[queue->rear1]);
        queue->front1++;
    }
}


void dequeue2(CircularQueue* queue){
    //there is decision to conrtol queue is empty or not
    if (queue->front2 == queue->rear2) {
        printf("Queue SECOND is empty\n");
    } else {
        //if queueu is not empty => front will be front-1 and value will deleted
        printf("%d is deleted\n",queue->array[queue->front2]);
        queue->front2++;
    }
}


void printQueue(CircularQueue* queue,char queueName[]){
    //these are some variable to print function
    int frontIndex, rearIndex, queueSize;
    //for first queue
    if(queueName[0]=='F'){
        frontIndex=queue->front1;
        rearIndex=queue->rear1;
        queueSize=(rearIndex-frontIndex);
        printf("QUEUE:%s FRONT:%d REAR:%d SIZE:%d\n", queueName, frontIndex, rearIndex, queueSize);
        //there are a few codes to control queue is empty
        if(queue->rear1==queue->front1){
            printf("NO_CONTENT\n");
        }
        else{
        //this is a loop to print items of queues
        for (int i=(frontIndex);i<rearIndex;i++){
            printf("%d ",queue->array[i]);
        }
        printf("\n");
        }
    }
    //for second queue
    else{
        frontIndex=queue->front2;
        rearIndex=queue->rear2;
        queueSize=(rearIndex-frontIndex);
        printf("QUEUE:%s FRONT:%d REAR:%d SIZE:%d\n", queueName, frontIndex, rearIndex, queueSize);
         //there are a few codes to control queue is empty
        if(queue->rear2==queue->front2){
            printf("NO_CONTENT\n");
        }
        else{
        //this is a loop to print items of queues
        for (int i=(frontIndex);i<rearIndex;i++){
            printf("%d",queue->array[i]);
        }
        printf("\n");
        }
    }
}


int main()
{
    //these codes will open the .txt file and read input
    FILE *file=fopen("input.txt","r");//you can write your file name in here to control homework
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    //these are char arrays to read input text
    char command[10], queueName[10];
    int value;
    //there is a funtcion which return a queue to define queue1 and queue2
    CircularQueue* myqueue=createCircularQueue();
    //this loop will scan the input file and decide which function to use
    while (fscanf(file, "%s", command) != EOF) {
        //if intput text will start with 'E' that's mean ENQUEUE
        if (command[0] == 'E') {
            fscanf(file, "%s %d", queueName, &value);
            //if text will start with 'F' => QUEUE1 else QUEUE2
            if (queueName[0] == 'F') {
                enqueue1(myqueue, value);
            } else {
                enqueue2(myqueue, value);
            }
        }
        //if input file start with 'D' that is mean DEQUEUE
        else if (command[0] == 'D') {
            fscanf(file, "%s", queueName);
            //if text will start with 'F' => QUEUE1 else QUEUE2
            if (queueName[0] == 'F') {
                dequeue1(myqueue);
            }
            else {
                dequeue2(myqueue);
            }
        }
        //if input text will start with 'P' that's mean PRINT
        else if (command[0] == 'P') {
            fscanf(file, "%s", queueName);
            printQueue(myqueue, queueName);
        }
    }
    fclose(file);
    free(myqueue);
    return 0;
}
