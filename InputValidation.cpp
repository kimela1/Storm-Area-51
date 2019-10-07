/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Contains function definition for the function decalred in 
** InputValidation.hpp
*******************************************************************************/
#include "InputValidation.hpp"
#include <cstdlib>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
** Function Name: intValidation
** Description: Validates user input. Takes a const int parameter for the number
** of options to choose from.
*******************************************************************************/
int intValidation(const int numChoice)
{
  int input;

  do
  {
    // Source: https://stackoverflow.com/questions/13212043/integer-input-validation-how
    cout << "Please enter your choice: ";
    std::string line;
    while(std::getline(cin, line))  
    {
      std::stringstream linestream(line);
      if (!(linestream >> input))
      {
        // Input was not a number
        cout << "Invalid choice. Please choose from the options given: ";
        continue;
      }
      if ((input < 1) || (input > numChoice))
      {
        // Input was out of range
        cout << "Invalid choice. Please choose from the options given: ";
        continue;
      }
      char errorTest;
      if (linestream >> errorTest)
      {
        // Input had extra stuff on the same line
        cout << "Invalid choice. Please choose from the options given: ";
        continue;
      }
      else 
      {
        // Valid input, break out of the loop
        break;
      }  
    }
  } while(std::cin.fail() || input < 1 || input > numChoice);
  return input;
}
