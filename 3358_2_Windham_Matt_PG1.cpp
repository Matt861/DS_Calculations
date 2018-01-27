// Author /s: Matt Windham & Kevin Kim
// Due Date:  1/30/17
// Programming Assignment Number 1
// Spring 2017 - CS 3358 - Section Number 2
//
// Instructor:  Husain Gholoom
//
/* Program takes a value between 0 and 200 from the user.
 The value is then implemented in several functions seperately.
 Each function uses the value to execute a specific calculation. */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int programStart();
//Displays program functions and prompts user input
void currencyCalculation(int);
//Calculates and displays the currency calculation
void ageCalculation(int);
//Calculates and displays the age calculation
void separateNumber(int);
//Separates number to digits in numbers and english
void armstrongNumber(int);
//Calculates whether user input is an armstrong number
void factorial(int);
//Calculates the factorial of the user input
void prime(int);
//Displays whether user input is prime and all primes previous
void hailstone(int);
//Displays the hailstone sequence for the user input

int main()
{
    char ch = 'y';  //switch for program
    //y || Y = execute program  n || N = terminate program
    do
    {
        switch(ch)
        {
            case 'Y':
            case 'y':
            {
                int userInput;  //user input that will be calculated
                //must be 0-200 to function
                userInput = programStart();
                currencyCalculation(userInput);
                ageCalculation(userInput);
                separateNumber(userInput);
                armstrongNumber(userInput);
                factorial(userInput);
                prime(userInput);
                hailstone(userInput);
                cout << "Would like to try for another number?" << endl
                << "Enter y || Y for yes or n || N for no ---> ";
                cin >> ch;
                cout << endl << endl;
                break;
            }
            case 'N':
            case 'n':
            {
                cout << endl << endl
                << "This APP is developed by Kevin Kim and Matt Windham"
                << endl << "January 30 - 2017" << endl;
                return 0;
                break;
            }
            default:
            {
                cout << endl << endl
                << "Error *** Invalid choice - Must be Y || y || N || n"
                << endl << endl
                << "Enter y || Y for yes or n || N for no ---> ";
                cin >> ch;
                cout << endl << endl;
                break;
            }
                return 0;
        }
    }while(true);
    
    return 0;
    
}

int programStart()
{
    //Used to select a number between 0 and 200
    int userInput;
    char restart = 'N'; //variable to re-prompt user for input if error
    //y || Y = reprompt cin n || N = terminate program
    
    cout << "Welcome to My App." << endl
    << "This APP accepts an integer from the keyboard." << endl
    << "the APP Calculates and Displays the Following   :" << endl << endl
    << "1. Assuming that the integer represents a $$ amount, then the "
    << "number of quarters, dimes, nickels, and pennies will be "
    << "calculated and displayed" << endl << endl
    << "2. Assuming that the integer represents person's Age in years, "
    << "then number of months, days, hours, minutes, and seconds for the "
    << "person will be calculated and displayed" << endl << endl
    << "3. The numbers will be separated into its individual digits. Then "
    << "each digit of the integer will be displayed in English." << endl
    << endl
    << "4. Indicate whether or not the integer is an armstrong number."
    << endl << endl
    << "5. The factorial of the integer will be calculated and displayed"
    << endl << endl
    << "6. Indicate whether or not the integer is prime. Then, all the "
    << "prime numbers between 1 and that number will also be displayed."
    << endl << endl
    << "7. The hailstone sequence starting at n will be calculated and "
    << "displayed." << endl << endl;
    cout << "Enter a positive integer number > 0 and < 200 --->  ";
    cin >> userInput;
    while(cin.fail())
    {
        cout << "\nError *** Incorrect input - You entered a character" << endl
        << "Enter a Positive Integer" << endl << endl;
        cin.clear();
        cin.ignore(10, '\n');
        cout << "Would like to try for another number?" << endl
        << "Enter y || Y for yes or n || N for no ---> ";
        cin >> restart;
        switch(restart)
        {
            case 'y':
            case 'Y':
            {
                cout << "Enter a positive integer number > 0 and < 200 --->  ";
                cin >> userInput;
                break;
            }
            case 'n':
            case 'N':
            {
                cout << endl << endl
                << "This APP is developed by Kevin Kim and Matt Windham"
                << endl << "January 30 - 2017" << endl;
                return 0;
                break;
            }
            default:
            {
                cout << endl << endl
                << "Error *** Invalid choice - Must be Y || y || N || n"
                << endl << endl
                << "Enter y || Y for yes or n || N for no ---> ";
                cin >> restart;
                cout << endl << endl;
                break;
            }
        }
    }
    while(userInput <= 0 || userInput >= 200)
    {
        cout << "Error *** number must be > 0 and < 200" << endl;
        cout << "Would like to try for another number?" << endl
        << "Enter y || Y for yes or n || N for no ---> ";
        cin >> restart;
        switch(restart)
        {
            case 'y':
            case 'Y':
            {
                cout << "Enter a positive integer number > 0 and < 200 --->  ";
                cin >> userInput;
                break;
            }
            case 'n':
            case 'N':
            {
                cout << endl << endl
                << "This APP is developed by Kevin Kim and Matt Windham"
                << endl << "January 30 - 2017" << endl;
                break;
            }
            default:
            {
                cout << endl << endl
                << "Error *** Invalid choice - Must be Y || y || N || n"
                << endl << endl
                << "Enter y || Y for yes or n || N for no ---> ";
                cin >> restart;
                cout << endl << endl;
                break;
            }
        }
    }
    cout << endl << endl << endl;
    return userInput;
}

void currencyCalculation(int userInput)
{
    //Declares units of currency
    int quarters,
    dimes,
    nickels,
    pennies;
    
    //Sets value of currency
    quarters = userInput * 4;
    dimes = userInput * 10;
    nickels = userInput * 20;
    pennies = userInput * 100;
    
    cout << "Currency Calculation" << endl << endl
    << "$" << userInput << "   is equivalent to:" << endl << endl << endl
    << quarters << "\tquarter/s"  << endl
    << dimes << "\tdime/s" << endl
    << nickels << "\tnickel/s" << endl
    << pennies << "\tcent/s" << endl << endl << endl;
}

void ageCalculation(int userInput)
{
    //Declares units of time
    int months,
    days,
    hours,
    minutes,
    seconds;
    
    //Sets units of time
    months = userInput * 12;
    days = userInput * 365;
    hours = userInput * 8760;
    minutes = userInput * 525600;
    seconds = userInput * 31540000;
    
    cout << "Age Calculation" << endl << endl << endl
    << "Assuming that you are " << userInput << " years old, then"
    << endl << endl
    << "You are \t" << months << "\tmonths old" << endl
    << "You are \t" << days << "\tdays old" << endl
    << "You are approximately\t" << hours << "\thours old" << endl
    << "You are approximately\t" << minutes << "\tminutes old" << endl
    << "You are approximately\t" << seconds << "\tseconds old" << endl
    << endl << endl;
}

void separateNumber(int userInput)
{
    int ones,
    tens,
    hundreds;
    string englishDigits[10] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
    
    if(userInput > 0)
    {
        if(userInput >= 10)
        {
            if(userInput >= 100)
            {
                hundreds = userInput / 100;
            }
            tens = userInput / 10;
        }
        ones = userInput % 10;
    }
    cout << "Separating digits for the integer " << userInput << endl;
    if(userInput >= 100)
    {
        cout << hundreds << "   " << tens << "   " << ones << endl;
        for(int i = 0; i < 10; i++)
        {
            if(hundreds == i)
                cout << englishDigits[i] << " ";
        }
        for(int i = 0; i < 10; i++)
        {
            if(tens == i)
                cout << englishDigits[i] << " ";
        }
        for(int i = 0; i < 10; i++)
        {
            if(ones == i)
                cout << englishDigits[i] << " ";
        }
    }
    if(userInput >= 10 && userInput < 100)
    {
        cout << tens << "   " << ones << endl;
        for(int i = 0; i < 10; i++)
        {
            if(tens == i)
                cout << englishDigits[i] << " ";
        }
        for(int i = 0; i < 10; i++)
        {
            if(ones == i)
                cout << englishDigits[i] << " ";
        }
    }
    if(userInput < 10)
    {
        cout << ones << endl;
        for(int i = 0; i < 10; i++)
        {
            if(ones == i)
                cout << englishDigits[i] << " ";
        }
    }
    cout << endl << endl << endl << endl;
}

void armstrongNumber(int userInput)
{
    //Declares digit values used
    int ones,
    tens,
    hundreds;
    
    if(userInput > 0)
    {
        if(userInput >= 10)
        {
            if(userInput >= 100)
            {
                hundreds = userInput / 100;
            }
            tens = userInput / 10;
        }
        ones = userInput % 10;
    }
    if(userInput == pow(hundreds, 3) + pow(tens, 3) + pow(ones, 3))
        cout << userInput << "\tis an Armstrong Number.";
    else
        cout << userInput << "\tis NOT an Armstrong Number.";
    cout << endl << endl << endl;
}

void factorial(int userInput)
{
    //Sets factorial value equal to 1
    long double factorial = 1;
    
    for(int i = 1; i <= userInput; i++)
    {
        factorial *= i;
    }
    
    cout << "Factorial of " << userInput << " = " << factorial
    << endl << endl << endl;
}

void prime(int userInput)
{
    //iteration used in for loop
    int i;
    //Sets initial value of isPrime to true
    bool isPrime = true;
    
    for(i = 2; i <= userInput / 2; ++i)
    {
        if(userInput % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << userInput << " is a prime number"
        << endl << endl;
    else
        cout << userInput << " is not a prime number"
        << endl;
    
    cout << endl << "All primes between 1 and " << userInput << " are"
    << endl << endl;
    if(userInput >= 1)
        cout << "1\tnumber is prime" << endl;
    if(userInput > 2)
        cout << "2\tnumber is prime" << endl;
    for(int j = 3; j <= userInput; j++)
    {
        isPrime = true;
        for(int k = 2; k < j; k++)
        {
            if(j % k == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
            cout << j << "\tnumber is prime" << endl;
    }
    cout << endl << endl;
}

void hailstone(int userInput)
{
    //Sets initial value of the counter to 1
    int iCount = 1;
    
    cout << "The hailstone sequence starting at " << userInput << " is (";
    
    while (userInput != 1)
    {
        cout << userInput << " ";
        // if number is even
        if (userInput % 2 == 0)
        {
            userInput /= 2;
        }
        // if number is odd
        else
        {
            userInput = userInput * 3 + 1;
        }
        ++iCount;
    }
    cout << "1) and it contains " << iCount << " numbers"
    << endl << endl << endl;
}