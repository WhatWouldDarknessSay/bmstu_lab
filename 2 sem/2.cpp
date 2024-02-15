#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;
int main(){
    // ifstream infile("2_input.txt");
    // ofstream outfile("2_output.txt");
    // string line;
    // while (getline(infile, line)) {
    //     int counter = 0;
    //     for ( string::size_type pos = 0;( pos = line.find_first_of( "0123456789", pos ) ) != string::npos;++pos ){
    //         counter++;
    //     }
    //     if (counter){
    //         outfile << line << "; digits: " << counter << endl;
    //     }
    // }
    // infile.close();
    // outfile.close();
    

    FILE* in_file= fopen("2_input.txt", "r");
    FILE *out_file= fopen("2_output.txt", "w");
    while (!feof(in_file)){
        string word = "";
        int ch;
        while(((ch = fgetc(in_file)) != EOF) && (ch != ' ')){
            word += ch;
            cout << to_string(ch);
        }
        int counter = 0;
        for ( string::size_type pos = 0;( pos = word.find_first_of( "0123456789", pos ) ) != string::npos;++pos ){
            counter++;
        }
        if(counter != 0){
            word += "; digits: " + to_string(counter) + '\n';
            fputs(word.c_str(), out_file);
        }
    }
    fclose(in_file);
    fclose(out_file);
}