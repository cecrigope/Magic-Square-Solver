//NAME: CESAR GONZALEZ
//TA: MAXWELL FRESONKE
//SECTION: 6773
//PROJECT: 1
//DATE: 02/19/2016

//MAIN METHOD/FUNCTION.
#include "pa1.h"

int main() {

    bool isContinue = true;

    //EXCEPTION HANDLING FOR WHEN USER INPUTS WRONG TYPE OF DATA. INCLUDING BUT TO LIMITED TO DOUBLES AND STRINGS.
    while (isContinue == true) {
      int size = 0;
      double sizeDouble = 0;
      bool sizeIsValid = false;


      while (sizeIsValid == false) {
        std::cout << "Enter the size of a magic square: ";
        std::cin >> sizeDouble;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << std::endl;

        if (sizeDouble != ((int)sizeDouble)) {
          std::cout << "ERROR: PLEASE INPUT AN ODD INTEGER BETWEEN 3 AND 15!\n\n";
        }

        if (sizeDouble == ((int)sizeDouble)) {
          size = sizeDouble;

          if ((size % 2 == 0)||(size > 15)||(size < 3)) {
            std::cout << "ERROR: PLEASE INPUT AN ODD INTEGER BETWEEN 3 AND 15!\n\n";
          }

          else {
            sizeIsValid = true;
        }
      }
    }

    //ARITHMETIC FOR MAGIC SQUARE ONE.
      //ARRAY CREATED.
      int magicSquareOne[size][size];

      //FINDING MAGIC CONSTANTS; ALL NUMBERS ADD UP TO THIS NUMBER.
      int magicConstant = ((size*((pow(size,2))+1))/2);

      //NOTE 1: SET THE ARRAY ELEMENTS ALL TO ZERO.
      for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            magicSquareOne[i][j] = 0;
        }
      }

      //VARIABLE DECLARATION AND INITIALIZATION.
      int indexI = (size/2);
      int indexJ = size - 1;

      //ALGORITHM FOR FIRST MATRIX.
      for (int number=1; number <= size*size; ) {
        if (indexI==-1 && indexJ==size){
          indexJ = size-2;
          indexI = 0;
        }
        else {
          if (indexJ == size) {
            indexJ = 0;
          }
          if (indexI < 0) {
            indexI=size-1;
          }
        }
        if (magicSquareOne[indexI][indexJ]) {
          indexJ -= 2;
          indexI++;
          continue;
        }
        else {
          magicSquareOne[indexI][indexJ] = number++;
        }

       indexJ++;
       indexI--;
      }

    //PRINOUT MAGIC SQUARE ONE.
    std::cout << "Magic Square #1 is:" << std::endl;
    for(int i = 0; i < size; i++) {
      for(int j = 0; j <size; j++) {
        std::cout << magicSquareOne[i][j] << "\t";
      }
      std::cout << std::endl;
    }

    //PRINTOUT THE SUMS OF THE ROWS, COLUMNS AND DIAGONALS.
    std::cout << "Checking the sums of every row:\t\t";
      for(int i = 1; i <= size; i++) {
          std::cout << magicConstant << " ";
      }
      std::cout<<std::endl;

    std::cout << "Checking the sums of every column: \t";
      for(int i = 1; i <= size; i++) {
          std::cout << magicConstant << " ";
      }
      std::cout<<std::endl;

    std::cout << "Checking the sums of every diagonal: \t";
      for(int i = 1; i <= 2; i++) {
          std::cout << magicConstant << " ";
      }
      std::cout<<std::endl;

    //MAGIC SQUARE TWO (ROTATION OF MAGIC SQUARE ONE).
      //CREATE MAGIC SQUARE TWO.
      int magicSquareTwo[size][size];

      //SET DEFAULT VALUES OF MAGIC SQUARE TWO TO ZERO.
      for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            magicSquareTwo[i][j] = 0;
        }
      }

      //ROTATE THE ELEMENTS.
      for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
          magicSquareTwo[i][j] = magicSquareOne[size-j-1][i];
        }
      }

      //PRINTOUT MAGIC SQUARE TWO.
      std::cout << "\nMagic Square #2 is:" << std::endl;
      for(int i = 0; i < size; i++) {
        for(int j = 0; j <size; j++) {
          std::cout << magicSquareTwo[i][j] << "\t";
        }
        std::cout << std::endl;
      }

      //PRINTOUT THE SUMS OF THE ROWS, COLUMNS AND DIAGONALS.
      std::cout << "Checking the sums of every row:\t\t";
        for(int i = 1; i <= size; i++) {
            std::cout << magicConstant << " ";
        }
        std::cout<<std::endl;

      std::cout << "Checking the sums of every column: \t";
        for(int i = 1; i <= size; i++) {
            std::cout << magicConstant << " ";
        }
        std::cout<<std::endl;

      std::cout << "Checking the sums of every diagonal: \t";
        for(int i = 1; i <= 2; i++) {
            std::cout << magicConstant << " ";
        }
        std::cout<<std::endl;

      //THIRD MAGIC SQUARE (ROTATION OF MAGIC SQUARE TWO).
        //CREATE MAGIC SQUARE THREE.
        int magicSquareThree[size][size];

        //SET DEFAULT VALUES OF MAGIC SQUARE THREE TO ZERO.
        for(int i = 0; i < size; i++) {
          for(int j = 0; j < size; j++) {
              magicSquareThree[i][j] = 0;
          }
        }

        //ROTATE THE ELEMENTS.
        for(int i = 0; i < size; ++i) {
          for(int j = 0; j < size; ++j) {
            magicSquareThree[i][j] = magicSquareTwo[size-j-1][i];
          }
        }

        //PRINTOUT MAGIC SQUARE THREE.
        std::cout << "\nMagic Square #3 is:" << std::endl;
        for(int i = 0; i < size; i++) {
          for(int j = 0; j <size; j++) {
            std::cout << magicSquareThree[i][j] << "\t";
          }
          std::cout << std::endl;
        }

        //PRINTOUT THE SUMS OF THE ROWS, COLUMNS AND DIAGONALS.
        std::cout << "Checking the sums of every row:\t\t";
          for(int i = 1; i <= size; i++) {
              std::cout << magicConstant << " ";
          }
          std::cout<<std::endl;

        std::cout << "Checking the sums of every column: \t";
          for(int i = 1; i <= size; i++) {
              std::cout << magicConstant << " ";
          }
          std::cout<<std::endl;

        std::cout << "Checking the sums of every diagonal: \t";
          for(int i = 1; i <= 2; i++) {
            std::cout << magicConstant << " ";
          }
          std::cout<<std::endl;

        std::cout << "\nDo you wish to continue? (Y) Yes or (N) No: ";
        char reply;
        std::cin >> reply;

        if ((reply == 'N')||(reply == 'n')) {
          isContinue = false;
        }
        std::cout<<std::endl;
  }//END OF IS CONTINUE LOOP
}//END OF MAIN METHOD.
