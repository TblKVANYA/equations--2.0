
// Воробьев Иван
// 28.08.2021
// Копирование разрешено, если глазам не больно

//! @file main.c
//! @mainpage
//! main.c
//! \author Vorobev Ivan
//! \data 27.08.2021

#include "kvadrik_header.h"

/*!
 * запускает всю программу, в зависимости от ifdef вызывает тестировщик или пользовательскую программу
 * @return 0
 */
int main() {
    //! переменная, указывающая на наличие ошибок в приложении
    int result_code = 0;

// Опциональность программы: если переменная DEBUG определена,программа будет выполнять тест,
// иначе - решение с введенными данными
#define  DEBUG                               //  раскоментить, чтобы перейти в режим тестирования программы
#   ifdef DEBUG
        result_code = test_solving();     // название основной функции, выполняющей тестирование
#   else
        result_code =  solve_equations();  // название основной функции, взаимодействующей с пользователем
#   endif

    if (result_code != 0) // обе подфункции возвращают 0, если сработали корректно
        print_error(result_code); // вывод ошибки

    return 0;
}
