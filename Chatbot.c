#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void greetUser(char userName[]);
void playsongs();
void addnumbers();
void openWebsite();
void showTime();
void processInput(char userInput[], char userName[], char favoriteColor[]);


void greetUser(char userName[]) {
    printf("ChatBot: Hello! I'm ChatBot, your virtual assistant.\n");
    printf("ChatBot: Before we begin, may I know your name? ");
    fgets(userName, 50, stdin);
    userName[strcspn(userName, "\n")] = '\0';
    printf("ChatBot: Nice to meet you, %s!\n", userName);
    printf("ChatBot: Type 'exit' anytime to end the chat.\n");
}


void playsongs() {
    printf("ChatBot: Playing your favorite song...\n");
    system("start \"C:\\Users\\GARGI SHARMA\\Downloads\\song.mp3"); 
}


void addnumbers() {
    int num1, num2;
    printf("ChatBot: Please enter the first number: ");
    scanf("%d", &num1);
    printf("ChatBot: Please enter the second number: ");
    scanf("%d", &num2);
    printf("ChatBot: The sum of %d and %d is %d.\n", num1, num2, num1 + num2);
    getchar(); 
}

void openWebsite() {
    char url[256];
    printf("ChatBot: Please enter the URL of the website: ");
    scanf("%s", url);
    printf("ChatBot: Opening %s in your default browser...\n", url);
    char command[300];
    snprintf(command, sizeof(command), "start %s", url);
    system(command);
    getchar(); 
}


void showTime() {
    time_t t;
    time(&t);
    printf("ChatBot: The current time is: %s", ctime(&t));
}


void processInput(char userInput[], char userName[], char favoriteColor[]) {
    for (int i = 0; userInput[i]; i++) {
        userInput[i] = tolower(userInput[i]);
    }

    if (strstr(userInput, "play song")) {
        playsongs();
    } else if (strstr(userInput, "add numbers")) {
        addnumbers();
    } else if (strstr(userInput, "visit website")) {
        openWebsite();
    } else if (strstr(userInput, "time")) {
        showTime();
    } else if (strstr(userInput, "hello") || strstr(userInput, "hi")) {
        printf("ChatBot: Hello again, %s! How can I assist you?\n", userName);
    } else if (strstr(userInput, "bye")) {
        printf("ChatBot: Goodbye, %s! It was nice chatting with you.\n", userName);
    } else if (strstr(userInput, "color")) {
        printf("ChatBot: Your favorite color is %s. That's a great choice!\n", favoriteColor);
    } else {
        printf("ChatBot: I didn't quite understand that. Can you try asking in a different way?\n");
    }
}


int main() {
    char userInput[256];
    char userName[50];
    char favoriteColor[30];

    greetUser(userName);

    printf("ChatBot: What's your favorite color? ");
    fgets(favoriteColor, sizeof(favoriteColor), stdin);
    favoriteColor[strcspn(favoriteColor, "\n")] = '\0'; 
    printf("ChatBot: I like %s too! Let's continue.\n", favoriteColor);

    while (1) {
        printf("You: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0'; 

        if (strcmp(userInput, "exit") == 0) {
            printf("ChatBot: Exiting the chat. Goodbye, %s!\n", userName);
            break;
        }

        processInput(userInput, userName, favoriteColor);
    }

    return 0;
}