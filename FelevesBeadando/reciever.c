#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main()

{

    int fd1;

    int tomb[5][3];

    // FIFO fájl helye

    char * myfifo = "/tmp/myfifo";

    // Nevesített csővezeték létrehozása (FIFO)

    mkfifo(myfifo, 0666);




    // FIFO megnyitása csak olvasásra, majd olvasni próbál,
    // de addig nem fog olvasni semmit, amíg 'B' program nem ad értéket

    fd1 = open(myfifo, O_RDONLY);

    read(fd1, &tomb, sizeof(tomb));

    close(fd1); 	// Csővezeték lezárása


        FILE *file_to_write = fopen("vegeredmeny.txt","a");

    if (file_to_write < 0){
        perror("Hiba üres a file");
        exit(-1);
    }

    printf("Sikeres file kiiras!\n");

    for(int i = 0; i < 5; i++)
    {
        fprintf(file_to_write, "%d meg %d lnkoja = %d\n", tomb[i][0], tomb[i][1], tomb[i][2]);
    }

    fclose(file_to_write);


    return 0;

}





