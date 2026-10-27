//Lium Powers, Computer Science, 10/27/2026

//Imports the libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//function declarations
void findTempRange(int temp);

//main function begins
int main()
{
    //opens the file
    std::ifstream infile;
    infile.open("HourlyTemps.dat");

    //if it cannot find file, ends the program
    if (!infile)
    {
        std::cout << "File not found, ending program";
        return 1;
    }

    //variable declarations
    int temp;
    infile >> temp; //prime read

    //prints the measurement bar/axis to tell what the temp is
    std::cout << std::setw(7) << "-30" << std::setw(9) << "0" << std::setw(10) << "30"; 
    std::cout << std::setw(10) << "60" << std::setw(10) << "90" << std::setw(11) << "120" << std::endl; 

    //iterates through file and plugs values into findTempRange
    while (infile)
    {

        //if temp is out of range, lets user know what temp it is
        if (temp < -30 || temp > 120)
        {
            std::cout << "Temp is out of range: " << temp << std::endl;
        }
        else
        {
            std::cout << std::setw(3) << temp;
            findTempRange(temp);
        }
        
        //gets the next temperature from file
        infile >> temp;
    }
    
    //closes file and ends main
    infile.close();
    return 0;
}

//Prints stars for the temp, each star represnets a range of three degrees
void findTempRange(int temp)
{
    int stars = 0;
    int count = 0;
    if (temp / 3.0 >= 0)
        {
            //prints appropriate whitespace
            std::cout << std::setw(13) << "|";

            //divides by three and "rounds" by adding 0.5
            //if num should round up, adding 0.5 brings to the next int
            //determines how many stars to print for the temp (temp/3.0)
            stars = (temp / 3.0) + 0.5;
            while (stars > count)
            {
                std::cout << "*";
                count = count + 1;
            }
            std::cout << "\n";
        }
        //if the temp is negative
        else if (temp / 3.0 < 0)
        {
            stars = (temp / -3.0) + 0.5;
            //takes whitespace and accounts for how many stars there will be to print the right space
            std::cout << std::setw(13 - (temp / -3.0));
            while (stars > count)
            {
                std::cout  << "*";
                count = count + 1;
            }
            std::cout << "|";
            std::cout << "\n";
        }
}