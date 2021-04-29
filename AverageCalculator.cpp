#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

//create a function for 
double average(string scores){
    //declareing the variable
    string num = "";
    double total = 0;
    double count = 1; //how many scores you have
    
    //for loop to read the string line by char from start to the end
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] != ' '){
            //determine the score from the string line by the space 
            num += scores[i];
        }
        else{
            //count the number of scores as the space goes
            count++;
            //convert the num from string to int and 
            //total = total + num
            total += stoi(num);
            //initializing the number when the for loop hits the space
            num = "";
        }
    }
    //to add the last score from the total
    //total = total + num
    total += stoi(num);
    //return the average
    return total / count;
}

int
main (void)
{
//declare the variables
  fstream file;
  fstream file2;
  
  string line = "";
  string score = "";
  
  double avg = 0;
  int index = 0;

//open the file and 
    file.open ("scores.txt", ios::in);
    if (file.is_open ())
    {
        //getline saves a line from the file and saves it into the 2nd arguement line
        while (getline (file, line)) 
       {
           //find the : in the line
         index = line.find (":");
         // locate the space to determine the scores
         score = line.substr (index + 2);
         //call the average function
         avg = average(score);
         //open the tmp file 
         file2.open("tmp.txt", ios::out | ios::app);
         //tmp_file.clear();
         if(file2.is_open()){
             //print the average with 2 demicals using fixed and setprecision
             file2 << line << " : Average : " << fixed << setprecision(2) << avg << endl;
         }
         //close tmp file
         file2.close();
       }
    }
    //close file
  file.close();
  
  //delete the file
  remove("scores.txt");
  //rename the tmp.tst to scores.txt
  rename("tmp.txt","scores.txt");
}



