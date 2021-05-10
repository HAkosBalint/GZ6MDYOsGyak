#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>


int lnko(double x, double y);

int main()

{

    srand(time(NULL)); // Random szám indító

    int input[2];

    int szamparok;

    FILE *fp = fopen("bemenet.txt","r");

   if (fp < 0){
        perror("Hiba üres a file");
        exit(-1);
   }

   fscanf(fp,"%d",&szamparok);

   int megoldas;

   printf("A fileban talalhato egyenletek szama: %d \n",szamparok);

   for(int i = 0; i < szamparok; i++){

        for(int k = 0; k < 2; k++){

            fscanf(fp,"%d",&input[k]);

        }



    }

    return 0;

}
/*void fif(int tomb[]) {

    int fd;
    // FIFO fájl helye

    char * myfifo = "/tmp/myfifo";

    // Nevesített csővezeték létrehozása (FIFO)

    mkfifo(myfifo, 0666);

    // FIFO megnyitása csak írásra

    fd = open(myfifo, O_WRONLY);

    write(fd, &tomb, 3);

    close(fd); // Csővezeték lezárása
}*/

int lnko(double x, double y){


  if (x == 0) {
    return y;
  }

  while (y != 0) {
    if (x > y)
      x = x - y;
    else
      y = y - x;
  }

    return x;


}
