#include <iostream>
 
int main (int argv, char *argc[]) {
  //--------------------------------------- Задание 1. -----------------------------------------
  //Создать и инициализировать переменные пройденных типов данных
  //(short int, int, long long, char, bool, float, double).
  {
    // Символьные типы
    char cLetter = 'R'; //размерностью 1 байт
    
    // Целочисленные типы
    short int iCount = 0; //Целое число со знаком размерностью 2 байта
    short iAge = 25; //Целое число со знаком размерностью 2 байта (краткая форма записи)
    long int iReceipt = 148'592; //Длинное целое знаковое размерностю 4 байта
    int iPaymentNumber = 47'812'467; //Длинное целое знаковое размерностью 4 байта (краткая форма записи)
    long long iAmountElements = 7'569'423'784'566'823LL; // Целое знаковое размерностью 8 байт

    // Числа с плавающей запятой
    float fPrice = 125.50F; //Число с плавающей запятой размерностью 4 байта
    double dSumm = 6'541.34; //Число с плавающей запятой двойной точности размерностью 8 байт

    // Логические типы
    bool bBigger = false; //Логический тип размерностю 1 байт
  }
  //------------------------------ Дополнительно к заданию 1. ----------------------------------
  //Еще нерассмотренные на курсе фундаментальные типы С++
  {
    //Символьные типы
    wchar_t wcCharacter = L'W'; // размерностью 2 байта

    // Числа с плавающей запятой
    long double dlPi = 3.141'592'653'589'793'238'462'643'383'279'5L;  // Число с плавающей запятой расширенной точности размерностью 12 байт
  }
  //--------------------------------------- Задание 2. -----------------------------------------
  //Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
  {
    enum Chips : char {
      X = 'X',
      O = 'O',
      EMPTY = ' '
    };
  }

  //--------------------------------------- Задание 3. -----------------------------------------
  //Создать массив (поле для игры в крестики нолики), способный содержать значения такого
  //перечисления и инициализировать его.
  //----------------------------------- Вариант решения 1 --------------------------------------
  {
    enum Chips : char {
      X = 'X',
      O = 'C',
      EMPTY = ' '
    };

    Chips aPlayingField[3][3] = {  
      {EMPTY, EMPTY, EMPTY},
      {EMPTY, EMPTY, EMPTY},
      {EMPTY, EMPTY, EMPTY}
      };
  }
  //----------------------------------- Вариант решения 2 --------------------------------------
  {
    enum Chips : char {
      CELL1 = '1',
      CELL2 = '2',
      CELL3 = '3',
      CELL4 = '4',
      CELL5 = '5',
      CELL6 = '6',
      CELL7 = '7',
      CELL8 = '8',
      CELL9 = '9',
      X = 'X',
      O = 'C',
      EMPTY = ' '
    };

    Chips aPlayingField[3][3] = {  
      {CELL1, CELL2, CELL3},
      {CELL4, CELL5, CELL6},
      {CELL7, CELL8, CELL9}
      };
  }  
  //--------------------------------------- Задание 4. -----------------------------------------
  //Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми
  //необходимыми свойствами (подумайте что может понадобиться).
  {
    enum Chips : char {
      X = 'X',
      O = 'C',
      EMPTY = ' '
    };

    enum PlayerType {
      HUMAN,
      COMPUTER
    };

    enum GameType {
      NETWORK,
      LOCALLY
    };

    struct IPv4 {
      unsigned short usPart1;
      unsigned short usPart2;
      unsigned short usPart3;
      unsigned short usPart4;      
    };

    struct Player {
      unsigned int iId; // Идентификатор игрока
      char caName [32]; //Имя игрока
      int iScore; //Счет выигрышей игрока
      Chips chip; //Какой фишкой играет игрок X или O
      PlayerType Type; //Тип игрока Комьютер или Человек
      IPv4 networkAddress; //Сетевой адрес игрока
    };

    struct TicTacToe {
      Chips aPlayingField[3][3]; //Игровое поле
      Player player1; //Игрок 1
      Player player2; //Игрок 2
      int iCountTour; //Количество туров в игре
      GameType type; //Тип игры.
      bool bGameOver; //Признак завершения игры
    };
  }

  //--------------------------------------- Задание 5. -----------------------------------------
  //Создать структуру (struct MyVariant) объединяющую: union MyData (int, float, char)
  //и 3-и битовых поля (флага) указывающими какого типа значение в данный момент содержится
  //в объединении (isInt, isFloat, isChar). Продемонстрировать пример использования в коде
  //этой структуры.
  {
    union MyData {
      char cSymbol;
      int iOperand;
      float fOperand;
      };
      
    struct MyVariant {
      MyData data;
      unsigned short isChar : 1;
      unsigned short isInt : 1;
      unsigned short isFloat : 1;
    };

    MyVariant variant;
    variant.data.cSymbol = '5';
    variant.isChar = 1;
    variant.isInt = 0;
    variant.isFloat = 0;
    std::cout << "Type char:     " << variant.data.cSymbol << ";\tflag isChar: "<< variant.isChar << ";  flag isInt: "
	      << variant.isInt << ";  flag isFloat: " << variant.isFloat <<  std::endl;

    variant.data.iOperand = 347;
    variant.isChar = 0;
    variant.isInt = 1;
    variant.isFloat = 0;
    std::cout << "Type int:     " << variant.data.iOperand << ";\tflag isChar: "<< variant.isChar << ";  flag isInt: "
	      << variant.isInt << ";  flag isFloat: " << variant.isFloat <<  std::endl;

    variant.data.fOperand = 59.458;
    variant.isChar = 0;
    variant.isInt = 0;
    variant.isFloat = 1;
    std::cout << "Type float:  " << variant.data.fOperand << ";\tflag isChar: "<< variant.isChar << ";  flag isInt: "
	      << variant.isInt << ";  flag isFloat: " << variant.isFloat <<  std::endl;
  }
  return 0;
}
